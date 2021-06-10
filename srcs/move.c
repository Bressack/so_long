/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:13:19 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/10 14:43:51 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_tile	*move1(t_map *map, int dir)
{
	if (map->won || ((dir == KEY_ARROW_TOP) && (map->player.y - 1 < 0))
		|| ((dir == KEY_ARROW_BOT) && (map->player.y + 1 > map->sy - 1))
		|| ((dir == KEY_ARROW_RIGHT) && (map->player.x + 1 > map->sx - 1))
		|| ((dir == KEY_ARROW_LEFT) && (map->player.x - 1 < 0)))
		return (NULL);
	if (dir == KEY_ARROW_TOP)
		return (&map->tiles[map->player.y - 1][map->player.x]);
	else if (dir == KEY_ARROW_BOT)
		return (&map->tiles[map->player.y + 1][map->player.x]);
	else if (dir == KEY_ARROW_RIGHT)
		return (&map->tiles[map->player.y][map->player.x + 1]);
	else if (dir == KEY_ARROW_LEFT)
		return (&map->tiles[map->player.y][map->player.x - 1]);
	return (NULL);
}

void	move2(t_map *map, int dir, t_tile *target)
{
	if (target->type == CHAR_EMPTY)
	{
		if (dir == KEY_ARROW_TOP)
			map->player.y -= 1;
		else if (dir == KEY_ARROW_BOT)
			map->player.y += 1;
		else if (dir == KEY_ARROW_RIGHT)
			map->player.x += 1;
		else if (dir == KEY_ARROW_LEFT)
			map->player.x -= 1;
	}
	write(1, "player pos: [", 13);
	ft_putnbr(map->player.x);
	write(1, "][", 2);
	ft_putnbr(map->player.y);
	write(1, "]\n", 2);
}

void	move(t_map *map, int dir)
{
	t_tile		*target;

	target = move1(map, dir);
	if (target == NULL)
		return ;
	if (target->type == CHAR_EXIT)
	{
		map->won = 1;
		target->type = CHAR_EMPTY;
	}
	else if (target->type == CHAR_WALL)
		return ;
	else if (target->type == CHAR_PLAYER)
		write(1, "humm, hello ?\n", ft_strlen("humm, hello ?\n"));
	else if (target->type == CHAR_COLLECT)
	{
		map->collect_count--;
		target->type = CHAR_EMPTY;
		target->img = map->empty_img;
	}
	move2(map, dir, target);
}
