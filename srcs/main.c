/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:44:04 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/10 15:00:37 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>


int		global_hook(void)
{
	exit(0);
	return (0);
}

void	error(char *msg)
{
	eprint(""C_G_RED"error: "C_G_WHITE);
	eprint(msg);
	eprint(""C_RES"\n");
	exit(-1);
}

t_img	init_img(t_mlx mlx, unsigned int color, int sx, int sy)
{
	t_img		new;
	int			k;

	new.id = mlx_new_image(mlx.id, sx, sy);
	if (!new.id)
		error("graphics server: unable to create a new image");
	new.data = (unsigned int *)mlx_get_data_addr(new.id, &new.bpp, &new.sl,
			&new.ed);
	if (!new.data)
		error("graphics server: unable to create a new image");
	k = 0;
	while (k < sx * sy)
	{
		new.data[k] = mlx_get_color_value(mlx.id, color);
		k++;
	}
	return (new);
}

int	main(int ac, char **av)
{
	t_all	all;
	t_mlx	mlx;
	t_map	map;

	if (ac != 2)
		error("usage: so_long path");
	map = init_map(av[1]);
	mlx.id = mlx_init();
	if (mlx.id == NULL)
		error("graphics server: unable to connect to the graphics server");
	mlx.win.sx = SIZE_SCREEN_X;
	mlx.win.sy = SIZE_SCREEN_Y;
	mlx.win.id = mlx_new_window(mlx.id, mlx.win.sx, mlx.win.sy, WIN_TITLE);
	if (mlx.win.id == NULL)
		error("graphics server: unable to create a new window");
	mlx_string_put(mlx.id, mlx.win.id, (mlx.win.sx / 2) - 50, mlx.win.sy / 2,
		mlx_get_color_value(mlx.id, COLOR_COLLECT), "loading...");
	mlx_do_sync(mlx.id);
	map = init_tiles(mlx, map);
	all.mlx = &mlx;
	all.map = &map;
	mlx_hook(mlx.win.id, 33, 0, global_hook, NULL);
	mlx_key_hook(mlx.win.id, hooks, &all);
	mlx_loop(mlx.id);
	return (0);
}
