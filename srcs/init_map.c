/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:18:00 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/10 14:27:11 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	get_file(t_map *map, int fd, int ret)
{
	char	*line;

	line = NULL;
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			error("unable to read the map file");
		if (!ret)
			break ;
		if (ft_strfind_ls_char(line, CHECK_STR) == -1)
			error("map contain bad characters");
		if (map->sx == -1)
			map->sx = ft_strlen(line);
		else if (map->sx != ft_strlen(line))
			error("the map is not rectangular");
		map->map[map->sy] = ft_strdup(line);
		map->sy++;
	}
	if (map->sx < 3 || map->sx >= SIZE_SCREEN_X)
		error("map size x not in range");
	if (map->sy < 3 || map->sy >= SIZE_SCREEN_Y)
		error("map size y not in range");
	close(fd);
}

t_map	init_map(char *filename)
{
	t_map	map;
	int		fd;
	int		ret;
	char	*line;

	ret = ft_strlen(filename);
	if (ret < 4 || ft_strcmp(filename + ret - 4, ".ber"))
		error("bad file name (file must be in format file.ber)");
	ret = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error("unable to open the map file");
	line = NULL;
	while (get_next_line(fd, &line) > 0)
		ret++;
	map.map = NULL;
	map.sx = -1;
	map.sy = 0;
	map.map = try_malloc(sizeof(char *) * (ret + 1));
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error("unable to open the map file");
	get_file(&map, fd, 0);
	return (map);
}
