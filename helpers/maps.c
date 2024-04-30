/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:51:55 by emyildir          #+#    #+#             */
/*   Updated: 2024/04/30 09:21:20 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_walls(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (((i == 0 || i == map->height - 1) || \
				(j == 0 || j == map->width - 1)) \
				&& map->map[i][j] != WALL_CHR
			)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_map(t_map *map)
{
	size_t	i;
	size_t	j;
	int		*arr;

	arr = (int *) ft_calloc(128, 4);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (!(map->map[i][j] == EXIT_CHR || map->map[i][j] == PLAYER_CHR || \
				map->map[i][j] == EMPTY_CHR || map->map[i][j] == WALL_CHR \
				|| map->map[i][j] == COLLECTIBLE_CHR) \
			)
				break ;
			arr[map->map[i][j]]++;
			j++;
		}
		i++;
	}
	if (arr[EXIT_CHR] != 1 || arr[PLAYER_CHR] != 1 || arr[COLLECTIBLE_CHR] <= 0)
		return (0);
	free(arr);
	return (i == map->height && check_walls(map));
}

int	check_size(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->map[i])
	{
		if (i == 0)
			map->width = ft_strlen(map->map[i]);
		else
			if (ft_strlen(map->map[i]) != map->width)
				return (0);
		i++;
	}
	map->height = i;
	return (map->width != 0);
}

int	load_map(t_map *map)
{
	char	*data;
	char	*buff;
	int		read_bytes;

	data = ft_strdup("");
	buff = (char *) malloc(sizeof(char) * 1024);
	if (!buff)
		return (0);
	while (1)
	{
		read_bytes = read(map->fd, buff, 1023);
		if (read_bytes <= 0)
			break ;
		buff[read_bytes] = '\0';
		ft_strappend(&data, buff);
	}
	free(buff);
	map->map = ft_split(data, '\n');
	return (1);
}

t_map	*handle_map(char *path)
{
	t_map	*map;

	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		return (0);
	map->fd = open(path, O_RDONLY);
	if (map->fd == -1)
		return (0);
		
	if (!load_map(map) || !check_size(map) || \
		!validate_map(map) || !check_walls(map))
		return (0);
	return (map);
}
