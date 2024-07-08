/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 04:08:16 by emyildir          #+#    #+#             */
/*   Updated: 2024/07/08 04:15:34 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**copy_map(t_map map)
{
	char	**new_map;
	int		i;

	new_map = ft_calloc(map.map_height, sizeof(char *));
	i = -1;
	while (++i < map.map_height)
		new_map[i] = ft_strdup(map.map[i]);
	return (new_map);
}

int	flood_fill(t_map map)
{
	char	**const new_map = copy_map(map);

	if (!new_map)
		return (0);
	
}