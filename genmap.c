/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:06:20 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/10 15:44:06 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <sys/types.h>
# include <stdarg.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <time.h>

# define INT_MAX			2147483647
# define CHAR_EMPTY			'0'
# define CHAR_WALL			'1'
# define CHAR_PLAYER		'P'
# define CHAR_COLLECT		'C'
# define CHAR_EXIT			'E'

int		check_arg(long sx, long sy, long ratio_wall, long ratio_collect)
{
	if (sx < 0 || sx > INT_MAX)
	{
		dprintf(2, "sx must be an positive integer\n");
		return (-1);
	}
	if (sy < 0 || sy > INT_MAX)
	{
		dprintf(2, "sy must be an positive integer\n");
		return (-1);
	}
	if (ratio_wall < 0 || ratio_wall > 100)
	{
		dprintf(2, "ratio_wall must be an positive integer in range [0-100]\n");
		return (-1);
	}
	if (ratio_collect < 0 || ratio_collect > 100)
	{
		dprintf(2, "ratio_collect must be an positive integer in range [0-100]\n");
		return (-1);
	}
	if ((sx - 2) * (sy - 2) < 3)
	{
		dprintf(2, "the map must contain at least 3 cases (actual: %ld)\n", (sx - 2) * (sy - 2));
		return (-1);
	}
	return (0);
}

char	**alloc_map(long sx, long sy)
{
	char	**map;

	if (!(map = malloc(sizeof(char *) * sy)))
		return (NULL);
	for (int i = 0; i < sy; i++)
	{
		if (!(map[i] = malloc(sx)))
			return (NULL);
		memset(map[i], CHAR_EMPTY, sx);
	}
	return (map);
}

void	surrounding_map(char **map, long sx, long sy)
{
	for (int i = 0; i < sx; i++)
		map[0][i] = CHAR_WALL;
	for (int i = 0; i < sx; i++)
		map[sy - 1][i] = CHAR_WALL;
	for (int i = 0; i < sy; i++)
		map[i][0] = CHAR_WALL;
	for (int i = 0; i < sy; i++)
		map[i][sx - 1] = CHAR_WALL;
}

void	print_map(char **map, long sx, long sy)
{
	for (int i = 0; i < sy; i++)
		printf("%.*s\n", (int)sx, map[i]);
}

void	fill(char **map, long sx, long sy, char c, long ratio)
{
	int	filled_goal;

	int		rx;
	int		ry;

	int 	i;

	if (ratio == -1)
		filled_goal = 1;
	else
		filled_goal = (double)(sy - 1) * (double)(sx - 1) * (double)((double)ratio / (double)100);
	i = 0;
	while (i < filled_goal)
	{
		rx = rand() % ((sx - 2) + 1);
		ry = rand() % ((sy - 2) + 1);

		if (map[ry][rx] == CHAR_EMPTY)
		{
			map[ry][rx] = c;
			i++;
		}
	}

}

int		main(int ac, char **av)
{
	long	sx;
	long	sy;
	long	ratio_wall;
	long	ratio_collect;

	char	**map;

	srand(time(NULL) + getpid());
	if (ac != 5)
	{
		dprintf(2, "bag ags, usage: genmap sx sy ratio_wall ratio_collect\n");
		return (-1);
	}
	sx = atol(av[1]);
	sy = atol(av[2]);
	ratio_wall = atol(av[3]);
	ratio_collect = atol(av[4]);
	if (check_arg(sx, sy, ratio_wall, ratio_collect) == -1)
		return (-1);
	if (!(map = alloc_map(sx, sy)))
		return (-1);
	surrounding_map(map, sx, sy);
	fill(map, sx, sy, CHAR_PLAYER, -1);
	fill(map, sx, sy, CHAR_EXIT, -1);
	fill(map, sx, sy, CHAR_COLLECT, -1);
	fill(map, sx, sy, CHAR_COLLECT, ratio_collect);
	fill(map, sx, sy, CHAR_WALL, ratio_wall);
	print_map(map, sx, sy);
	return (0);
}
