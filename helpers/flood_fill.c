/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 04:08:16 by emyildir          #+#    #+#             */
/*   Updated: 2024/07/10 12:59:47 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**copy_map(t_map *map)
{
	char	**new_map;
	int		i;

	new_map = ft_calloc(map->map_height + 1, sizeof(char *));
	i = -1;
	while (++i < map->map_height)
		new_map[i] = ft_strdup(map->map[i]);
	new_map[i] = 0;
	return (new_map);
}

void	spread(char **map, int height, int width, t_point point)
{
	if (point.x < 0 || point.y < 0 || point.x >= width || \
		point.y >= height || map[point.y][point.x] == WALL_CHR)
		return ;
	map[point.y][point.x] = WALL_CHR;
	spread(map, height, width, (t_point){.x = point.x + 1, .y = point.y});
	spread(map, height, width, (t_point){.x = point.x - 1, .y = point.y});
	spread(map, height, width, (t_point){.x = point.x, .y = point.y - 1});
	spread(map, height, width, (t_point){.x = point.x, .y = point.y + 1});
}

int	flood_fill(t_map *map)
{
	char **const	new_map = copy_map(map);
	const t_point	player_point = get_player_point(map);
	int				i;
	int				j;

	if (!new_map)
		return (0);
	spread(new_map, map->map_height, map->map_width, player_point);
	i = -1;
	while (new_map[++i])
	{
		j = -1;
		while (new_map[i][++j])
			if (new_map[i][j] == COLLECTIBLE_CHR || new_map[i][j] == EXIT_CHR)
				return (free_map(new_map), 0);
	}
	return (free_map(new_map), 1);
}
