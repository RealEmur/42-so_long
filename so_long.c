/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:47:54 by emyildir          #+#    #+#             */
/*   Updated: 2024/07/12 21:56:54 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	main(int size, char **args)
{
	t_map	map;

	if (size != 2)
		return (ft_printf("Error: You need to provide a map file.\n", 0));
	if (!is_extension_ber(args[1]))
		return (ft_printf("Error: Map files have to end with .ber extension.\n"), 0);
	map = handle_map(args[1]);
	if (map.error)
	{
		if (map.map)
			free_map(map.map);
		ft_printf("Error: Map format is not true.\n");
	}
	else if(!start_game(&map))
		ft_printf("Error: Window could not be created.\n");
	return (0);
}
