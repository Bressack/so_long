/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:14:38 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/10 15:00:59 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	hooks(int key, void *arg)
{
	t_all	*all;

	all = (t_all *)arg;
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_ARROW_TOP || key == KEY_W)
		move(all->map, KEY_ARROW_TOP);
	else if (key == KEY_ARROW_BOT || key == KEY_S)
		move(all->map, KEY_ARROW_BOT);
	else if (key == KEY_ARROW_RIGHT || key == KEY_D)
		move(all->map, KEY_ARROW_RIGHT);
	else if (key == KEY_ARROW_LEFT || key == KEY_A)
		move(all->map, KEY_ARROW_LEFT);
	draw_window(*all->mlx, *all->map);
	return (key);
}
