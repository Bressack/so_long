/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:14:49 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/10 14:54:52 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	draw_won(t_mlx mlx, t_map map)
{
	if (map.collect_count)
	{
		mlx_string_put(mlx.id, mlx.win.id, (
				mlx.win.sx / 2) - 50, mlx.win.sy / 2, mlx_get_color_value(
				mlx.id, COLOR_EXIT), "DEFEAT !");
	}
	else
	{
		mlx_string_put(mlx.id, mlx.win.id, (
				mlx.win.sx / 2) - 50, mlx.win.sy / 2, mlx_get_color_value(
				mlx.id, COLOR_PLAYER), "VICTORY !");
	}
}

void	draw_window(t_mlx mlx, t_map map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map.sy)
	{
		j = 0;
		while (j < map.sx)
		{
			if (map.player.x == j && map.player.y == i)
				mlx_put_image_to_window(mlx.id, mlx.win.id,
					map.player.img.id, map.player.sx * j, map.player.sy * i);
			else
				mlx_put_image_to_window(mlx.id, mlx.win.id,
					map.tiles[i][j].img.id, map.tiles[i][j].sx * j,
					map.tiles[i][j].sy * i);
			j++;
		}
		i++;
	}
	if (map.won)
		draw_won(mlx, map);
}
