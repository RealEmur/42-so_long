/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:48:59 by emyildir          #+#    #+#             */
/*   Updated: 2024/07/10 20:08:03 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# define WALL_CHR '1'
# define COLLECTIBLE_CHR 'C'
# define PLAYER_CHR 'P'
# define EXIT_CHR 'E'
# define EMPTY_CHR '0'
# define EXIT_W_PLAYER_CHR 'X'

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0 
# define KEY_S  1
# define KEY_D 2

# define MOVE_UP 0
# define MOVE_DOWN 1
# define MOVE_LEFT 2
# define MOVE_RIGHT 3

# define RIGHT 0
# define LEFT 1

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "./lib/libft/libft.h"
#include "./lib/mlx/mlx.h"

#define CHARACTER_IMAGE_RIGHT_PATH "./textures/character_right.xpm"
#define CHARACTER_IMAGE_LEFT_PATH "./textures/character_left.xpm"
#define COLLECTIBLE_IMAGE_PATH "./textures/collectible.xpm"
#define EXIT_IMAGE_PATH "./textures/door.xpm"
#define EXIT_W_PLAYER_PATH "./textures/exit_w_player.xpm"
#define WALL_IMAGE_PATH "./textures/wall.xpm"
#define EMPTY_IMAGE_PATH "./textures/empty.xpm"

#define	TEXTURE_SIZE 64

typedef struct s_point {
	int	x;
	int y;
	int	dir;
} t_point;


typedef struct	s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_map{
	int		error;
	char	**map;
	int		map_width;
	int		map_height;
}	t_map;


typedef struct s_images{
	void	*empty_image;
	void	*wall_image;
	void	*exit_image;
	void	*exit_w_player_image;
	void	*character_r_image;
	void	*character_l_image;
	void	*collectible_image;
} t_images;

typedef struct s_game
{
	int			score;
	int			collectibles_count;
	t_point		player_point;
	t_images	images;
	t_map		*map;
	t_vars		vars;
}	t_game;

int			flood_fill(t_map *map);
int			start_game(t_map	*map);
int			is_extension_ber(char *name);
int			initialize_window(t_game *game);
void		free_map(char **map);
void		end_game(t_game *game);
void		move(t_game	*game, int dir);
void		put_image_to_window(t_vars *vars, void *img, int x, int y);
t_map		handle_map(char *path);
t_point		get_player_point(t_map *map);
t_images	render_images(t_game *game);

#endif