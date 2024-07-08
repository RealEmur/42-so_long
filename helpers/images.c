/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 22:33:51 by emyildir          #+#    #+#             */
/*   Updated: 2024/07/08 04:01:49 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_image(t_vars *vars, char *path, void **image, int trash)
{
	*image = mlx_xpm_file_to_image(vars->mlx, path, &trash, &trash);
}

void	put_image_to_window(t_vars *vars, void *img, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img, \
	x * TEXTURE_SIZE, y * TEXTURE_SIZE);
}

t_images	render_images(t_vars *vars)
{
	t_images	images;

	render_image(vars, CHARACTER_IMAGE_PATH, &images.character_image, 0);
	render_image(vars, WALL_IMAGE_PATH, &images.wall_image, 0);
	render_image(vars, EXIT_IMAGE_PATH, &images.exit_image, 0);
	render_image(vars, COLLECTIBLE_IMAGE_PATH, &images.collectibe_image, 0);
	render_image(vars, EXIT_W_PLAYER_PATH, &images.exit_w_player_image, 0);
	render_image(vars, EMPTY_IMAGE_PATH, &images.empty_image, 0);
	return (images);
}
