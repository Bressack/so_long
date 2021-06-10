/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:44:14 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/10 15:41:09 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <sys/types.h>
# include <stdarg.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <utils.h>
# include <graphic_server.h>
# include <color_shell.h>
typedef struct s_map
{
	int				won;
	int				collect_count;
	char			**map;
	t_tile			player;
	t_tile			**tiles;
	t_img			empty_img;
	t_img			wall_img;
	t_img			player_img;
	t_img			exit_img;
	t_img			collect_img;
	long			sx;
	long			sy;
}					t_map;
typedef struct s_all
{
	t_mlx			*mlx;
	t_map			*map;
}					t_all;
int		hooks(int key, void *arg);
void	draw_window(t_mlx mlx, t_map map);
void	move(t_map *map, int dir);
t_map	init_map(char *filename);
void	error(char *msg);
t_map	init_tiles(t_mlx mlx, t_map map);
t_img	init_img(t_mlx mlx, unsigned int color, int sx, int sy);
#endif
