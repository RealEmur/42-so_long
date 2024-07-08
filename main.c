/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:47:54 by emyildir          #+#    #+#             */
/*   Updated: 2024/07/08 04:05:38 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	main(int size, char **args)
{
	t_map	map;
	
	if (size == 2)
	{
		map = handle_map(args[1]);
		if(map.error)
			ft_printf("Map error\n");
		else 
			start_game(&map);
	}
	return (0);
}