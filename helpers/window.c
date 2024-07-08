/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 03:53:58 by emyildir          #+#    #+#             */
/*   Updated: 2024/07/08 04:02:58 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	on_press_key(int keycode, t_game *game)
{
	int (*keys)[255] = &(int [255]){0}; 
	
	(*keys)[KEY_W] = MOVE_UP;
	(*keys)[KEY_A] = MOVE_LEFT;
	(*keys)[KEY_S] = MOVE_DOWN;
	(*keys)[KEY_D] = MOVE_RIGHT;
	if (keycode == KEY_ESC)
		end_game(game);
	else if ((*keys)[keycode] || keycode == KEY_W)
		move(game, (*keys)[keycode]);
	return (0);
}


int		render_window(t_game *game)
{
	void	*chars[255];
	int		i;
	int		j;
	t_map	*map;

	ft_bzero(chars, 255);
	chars[(int) WALL_CHR] = game->images.wall_image;
	chars[(int) COLLECTIBLE_CHR] = game->images.collectibe_image;
	chars[(int) PLAYER_CHR] = game->images.character_image;
	chars[(int) EXIT_CHR] = game->images.exit_image;
	chars[(int) EMPTY_CHR] = game->images.empty_image;
	chars[(int) EXIT_W_PLAYER_CHR] = game->images.exit_w_player_image;
	i = -1;
	map = game->map;
	while (++i < map->map_height)
	{
		j = -1;
		while (++j < map->map_width)
			put_image_to_window(&game->vars, chars[(int) map->map[i][j]], j, i);
	}
	return (0);
}

void	initialize_window(t_game *game)
{
	game->vars.mlx = mlx_init();
	game->vars.win = mlx_new_window(game->vars.mlx, game->map->map_width * TEXTURE_SIZE, \
	game->map->map_height * TEXTURE_SIZE, "so_long");
	game->images = render_images(&(game->vars));
	mlx_hook(game->vars.win, 2, 0, on_press_key, game);
	mlx_loop_hook(game->vars.mlx, render_window, game);
	mlx_loop(game->vars.mlx);
}