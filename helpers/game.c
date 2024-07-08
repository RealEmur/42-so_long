/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:36:44 by emyildir          #+#    #+#             */
/*   Updated: 2024/07/08 04:02:54 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int		get_collectible_count(t_map *map)
{
	int		count;
	int		i;
	int		j;

	count = 0;
	i = -1;
	while (++i < map->map_height)
	{
		j = -1;
		while (++j < map->map_width)
			if ((map->map)[i][j] == COLLECTIBLE_CHR)
				count++;
	}
	return (count);
}

void	end_game(t_game *game)
{
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	exit(0);
}

void	start_game(t_map *map)
{
	t_game	*const game = &(t_game) {0};
	
	game->map = map;
	game->player_point = get_player_point(map);
	game->collectibles_count = get_collectible_count(map);
	game->score = 0;
	initialize_window(game);
}