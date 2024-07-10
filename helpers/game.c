/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:36:44 by emyildir          #+#    #+#             */
/*   Updated: 2024/07/10 20:08:37 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_collectible_count(t_map *map)
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
	free_map(game->map->map);
	if (game->vars.win)
		mlx_destroy_window(game->vars.mlx ,game->vars.win);
	if (game->images.character_r_image)
		mlx_destroy_image(game->vars.mlx, game->images.character_r_image);
	if (game->images.character_l_image)
		mlx_destroy_image(game->vars.mlx, game->images.character_l_image);
	if (game->images.collectible_image)
		mlx_destroy_image(game->vars.mlx, game->images.collectible_image);
	if (game->images.exit_image)
		mlx_destroy_image(game->vars.mlx, game->images.exit_image);
	if (game->images.exit_w_player_image)
		mlx_destroy_image(game->vars.mlx, game->images.exit_w_player_image);
	if (game->images.wall_image)
		mlx_destroy_image(game->vars.mlx, game->images.wall_image);
	if (game->images.empty_image)
		mlx_destroy_image(game->vars.mlx, game->images.empty_image);
	exit(0);
}

int	start_game(t_map *map)
{
	t_game *const	game = &(t_game){0};

	game->map = map;
	game->player_point = get_player_point(map);
	game->collectibles_count = get_collectible_count(map);
	game->score = 0;
	return (initialize_window(game));
}
