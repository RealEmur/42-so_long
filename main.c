/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:47:54 by emyildir          #+#    #+#             */
/*   Updated: 2024/04/30 09:20:15 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	main(int size, char **args)
{
	t_map *map;
	if (size == 2)
	{
		map = handle_map(args[1]);
		if(!map)
			printf("Map error\n");
		else 
		{
			for(int i = 0; map->map[i]; i++)
			{
				printf("Error\n", map->map[i]);
			}
		}
	}
	free(map);
	return (0);
}