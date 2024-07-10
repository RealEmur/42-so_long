/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:51:55 by emyildir          #+#    #+#             */
/*   Updated: 2024/07/10 17:05:27 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_walls(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map->map_height)
	{
		j = -1;
		while (++j < map->map_width)
		{
			if (((i == 0 || i == map->map_height - 1) || \
				(j == 0 || j == map->map_width - 1)) \
				&& map->map[i][j] != WALL_CHR
			)
				return (0);
		}
	}
	return (1);
}

int	validate_map(t_map *map)
{
	int		i;
	int		j;
	int		*arr;

	arr = (int *) ft_calloc(128, 4);
	i = -1;
	while (++i < map->map_height)
	{
		j = -1;
		while (++j < map->map_width)
		{
			if (!(map->map[i][j] == EXIT_CHR || map->map[i][j] == PLAYER_CHR || \
				map->map[i][j] == EMPTY_CHR || map->map[i][j] == WALL_CHR \
				|| map->map[i][j] == COLLECTIBLE_CHR) \
			)
				break ;
			arr[(int) map->map[i][j]]++;
		}
	}
	if (arr[EXIT_CHR] != 1 || arr[PLAYER_CHR] != 1 || arr[COLLECTIBLE_CHR] <= 0)
		return (free(arr), 0);
	free(arr);
	return (i == map->map_height && check_walls(map));
}

int	check_size(t_map *map)
{
	int		i;

	i = -1;
	while (map->map[++i])
	{
		if (i == 0)
			map->map_width = ft_strlen(map->map[i]);
		else
			if (ft_strlen(map->map[i]) != (unsigned long) map->map_width)
				return (0);
	}
	map->map_height = i;
	return (map->map_width != 0);
}

int	load_map(t_map *map, int fd)
{
	char		*buff;
	int			read_bytes;
	char *const	data = ft_strdup("");

	buff = (char *) malloc(sizeof(char) * (1024 + 1));
	if (!buff)
		return (0);
	while (1)
	{
		read_bytes = read(fd, buff, 1024);
		if (read_bytes <= 0)
			break ;
		buff[read_bytes] = '\0';
		ft_strappend((char **) &data, buff);
	}
	free(buff);
	if (ft_strnstr(data, "\n\n", ft_strlen(data)))
		return (free(data), 0);
	map->map = ft_split(data, '\n');
	return (free(data), 1);
}

t_map	handle_map(char *path)
{
	int		fd;
	t_map	map;

	fd = open(path, O_RDONLY);
	map.error = 0;
	map.map = 0;
	if (fd == -1 || !load_map(&map, fd) || !check_size(&map) || \
		!validate_map(&map) || !check_walls(&map) || !flood_fill(&map))
		map.error = 1;
	close(fd);
	return (map);
}
