/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 22:33:51 by emyildir          #+#    #+#             */
/*   Updated: 2024/07/10 20:07:47 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_image(t_game *game, char *path, void **image, int trash)
{
	*image = mlx_xpm_file_to_image(game->vars.mlx, path, &trash, &trash);
	if (!*image)
	{
		ft_printf("Error\nFailed to load image: %s\n", path);
		end_game(game);
	}
}

void	put_image_to_window(t_vars *vars, void *img, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img, \
	x * TEXTURE_SIZE, y * TEXTURE_SIZE);
}

t_images	render_images(t_game *game)
{
	t_images	images;

	render_image(game, CHARACTER_IMAGE_RIGHT_PATH, &images.character_r_image, 0);
	render_image(game, CHARACTER_IMAGE_LEFT_PATH, &images.character_l_image, 0);
	render_image(game, WALL_IMAGE_PATH, &images.wall_image, 0);
	render_image(game, EXIT_IMAGE_PATH, &images.exit_image, 0);
	render_image(game, COLLECTIBLE_IMAGE_PATH, &images.collectible_image, 0);
	render_image(game, EXIT_W_PLAYER_PATH, &images.exit_w_player_image, 0);
	render_image(game, EMPTY_IMAGE_PATH, &images.empty_image, 0);
	return (images);
}
