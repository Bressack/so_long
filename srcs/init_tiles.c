/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:32:58 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/10 14:25:35 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_map	init_tile_each_dispatch2(t_map map, int i, int j)
{
	if (map.tiles[i][j].type == CHAR_COLLECT)
	{
		map.collect_count++;
		map.tiles[i][j].color = COLOR_COLLECT;
		map.tiles[i][j].img = map.collect_img;
	}
	else if (map.tiles[i][j].type == CHAR_PLAYER)
	{
		map.tiles[i][j].type = CHAR_EMPTY;
		map.tiles[i][j].color = COLOR_EMPTY;
		map.tiles[i][j].img = map.empty_img;
		map.player.x = j;
		map.player.y = i;
	}
	else if (map.tiles[i][j].type == CHAR_EXIT)
	{
		map.tiles[i][j].color = COLOR_EXIT;
		map.tiles[i][j].img = map.exit_img;
	}
	return (map);
}

t_map	init_tile_each_dispatch(t_map map, int i, int j)
{
	if (map.tiles[i][j].type == CHAR_EMPTY)
	{
		map.tiles[i][j].color = COLOR_EMPTY;
		map.tiles[i][j].img = map.empty_img;
	}
	else if (map.tiles[i][j].type == CHAR_WALL)
	{
		map.tiles[i][j].color = COLOR_WALL;
		map.tiles[i][j].img = map.wall_img;
	}
	else
		return (init_tile_each_dispatch2(map, i, j));
	return (map);
}

t_map	init_tile_each(t_map map, int tsx, int tsy)
{
	int		i;
	int		j;

	i = 0;
	while (i < map.sy)
	{
		map.tiles[i] = try_malloc(sizeof(t_tile) * map.sx);
		j = 0;
		while (j < map.sx)
		{
			map.tiles[i][j].type = map.map[i][j];
			map.tiles[i][j].x = j;
			map.tiles[i][j].y = i;
			map = init_tile_each_dispatch(map, i, j);
			map.tiles[i][j].sx = tsx;
			map.tiles[i][j].sy = tsy;
			j++;
		}
		i++;
	}
	return (map);
}

t_map	init_tiles(t_mlx mlx, t_map map)
{
	int	tsx;
	int	tsy;

	tsx = mlx.win.sx / map.sx;
	tsy = mlx.win.sy / map.sy;
	map.tiles = try_malloc(sizeof(t_tile *) * map.sy);
	map.won = 0;
	map.empty_img = init_img(mlx, COLOR_EMPTY, tsx, tsy);
	map.wall_img = init_img(mlx, COLOR_WALL, tsx, tsy);
	map.collect_img = init_img(mlx, COLOR_COLLECT, tsx, tsy);
	map.player_img = init_img(mlx, COLOR_PLAYER, tsx, tsy);
	map.exit_img = init_img(mlx, COLOR_EXIT, tsx, tsy);
	map.player.type = CHAR_PLAYER;
	map.player.sx = tsx;
	map.player.sy = tsy;
	map.player.color = COLOR_PLAYER;
	map.player.img = map.player_img;
	map.collect_count = 0;
	map = init_tile_each(map, tsx, tsy);
	draw_window(mlx, map);
	return (map);
}
