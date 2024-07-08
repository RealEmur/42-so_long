/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:07:56 by emyildir          #+#    #+#             */
/*   Updated: 2024/07/08 04:17:58 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_point	get_player_point(t_map *map)
{
	t_point	point;
	
	point.y = 0;	
	while (point.y < map->map_height)
	{
		point.x = 0;
		while (point.x < map->map_width)
		{
			if (map->map[point.y][point.x] == PLAYER_CHR || \
			map->map[point.y][point.x] == EXIT_W_PLAYER_CHR)
				return (point);
			(point.x)++;
		}
		(point.y)++;
	}
	return (point);
}

t_point	get_point_diff(int dir)
{
	const t_point diff[] = {
		{.x = 0, .y = -1},
		{.x = 0, .y = 1},
		{.x = -1, .y = 0},
		{.x = 1, .y = 0},
	};
	return (diff[dir]);
}

void	move_player(t_game *game, t_point current_p, t_point target_p)
{	
	char * const target = &game->map->map[target_p.y][target_p.x];
	char * const current = &game->map->map[current_p.y][current_p.x];
	
	if(*target == COLLECTIBLE_CHR)
		game->collectibles_count--;

	if (*target == EXIT_CHR)
	{
		if (!game->collectibles_count)
			end_game(game);
		*target = EXIT_W_PLAYER_CHR;
	}
	else
		*target = PLAYER_CHR;
	if (*current == EXIT_W_PLAYER_CHR)
		*current = EXIT_CHR;
	else
		*current = EMPTY_CHR;
	game->player_point = target_p;
}

int	is_moveable(char entity)
{	
	return (entity == EMPTY_CHR || entity == COLLECTIBLE_CHR || entity == EXIT_CHR);
}

void	move(t_game	*game, int dir)
{
	const t_point	current = game->player_point;
	const t_point	diff = get_point_diff(dir);
	
	if (is_moveable(game->map->map[current.y + diff.y][current.x + diff.x]))
		move_player(game, current, \
		(t_point){.x = current.x + diff.x, .y = current.y + diff.y});
}