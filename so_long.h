/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:48:59 by emyildir          #+#    #+#             */
/*   Updated: 2024/07/08 03:59:04 by emyildir         ###   ########.fr       */
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

typedef enum e_chars
{
	WALL,
	COLLECTIBLE,
	PLAYER,
	EXIT,
	EMPTY,
	EXIT_W_PLAYER
}	t_chars;

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0 
# define KEY_S  1
# define KEY_D 2

# define MOVE_UP 0
# define MOVE_DOWN 1
# define MOVE_LEFT 2
# define MOVE_RIGHT 3

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "./lib/libft/libft.h"
#include "./lib/mlx/mlx.h"

#define CHARACTER_IMAGE_PATH "./textures/character.xpm"
#define COLLECTIBLE_IMAGE_PATH "./textures/collectible.xpm"
#define EXIT_IMAGE_PATH "./textures/door.xpm"
#define EXIT_W_PLAYER_PATH "./textures/exit_w_player.xpm"
#define WALL_IMAGE_PATH "./textures/wall.xpm"
#define EMPTY_IMAGE_PATH "./textures/empty.xpm"

#define	TEXTURE_SIZE 64

typedef struct s_point {
	int	x;
	int y;
} t_point;


typedef struct	s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_map{
	int		fd;
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
	void	*character_image;
	void	*collectibe_image;
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

void		move(t_game	*game, int dir);
void		start_game(t_map	*map);
void		end_game(t_game *game);
t_map		handle_map(char *path);
t_images	render_images(t_vars *vars);
void		put_image_to_window(t_vars *vars, void *img, int x, int y);
t_point		get_player_point(t_map *map);
void		initialize_window(t_game *game);

#endif