/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:48:59 by emyildir          #+#    #+#             */
/*   Updated: 2024/04/30 08:38:06 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# define WALL_CHR '1'
# define COLLECTIBLE_CHR 'C'
# define PLAYER_CHR 'P'
# define EXIT_CHR 'E'
# define EMPTY_CHR '0'

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "./lib/libft/libft.h"



typedef struct s_map
{
	int		fd;
	char	**map;
	int		width;
	int		height;
}	t_map;

t_map	*handle_map(char *path);

#endif