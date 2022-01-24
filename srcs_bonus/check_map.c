/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:33:07 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/24 06:14:04 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_necessary_el(t_game *game)
{
	if (game->elements.exit == 0)
		game_free_and_error("Map must contain at least one exit", game);
	if (game->elements.coin_el == 0)
		game_free_and_error("Map must contain at least one collectible", game);
	if (game->elements.player == 0)
		game_free_and_error("Map must contain one starting position", game);
	else if (game->elements.player > 1)
		game_free_and_error(
			"Map must contain only one starting position", game);
}

static void	check_elements(t_game *game, int tmp_height, int tmp_width)
{
	if (game->map[tmp_height][tmp_width] == EMPTY_EL)
		game->elements.empty_el++;
	else if (game->map[tmp_height][tmp_width] == WALL_EL)
		game->elements.wall_el++;
	else if (game->map[tmp_height][tmp_width] == COIN_EL)
		game->elements.coin_el++;
	else if (game->map[tmp_height][tmp_width] == PLAYER_EL)
	{
		game->elements.player++;
		if (game->player_x_pos == 0 || game->player_y_pos == 0)
		{
			game->player_x_pos = tmp_width;
			game->player_y_pos = tmp_height;
		}
	}	
	else if (game->map[tmp_height][tmp_width] == EXIT_EL)
		game->elements.exit++;
	else if (game->map[tmp_height][tmp_width] == ENEMY_EL)
		game->elements.enemy++;
	else if (game->map[tmp_height][tmp_width] != '\n')
		game_free_and_error("Invalid element found in the map", game);
}

static void	check_map_symbols(t_game *game)
{
	int		tmp_height;
	int		tmp_width;

	tmp_height = game->map_height - 1;
	game->elements.empty_el = 0;
	game->elements.wall_el = 0;
	game->elements.coin_el = 0;
	game->elements.player = 0;
	game->elements.exit = 0;
	game->elements.enemy = 0;
	while (tmp_height >= 0)
	{
		tmp_width = 0;
		while (game->map[tmp_height][tmp_width])
		{
			check_elements(game, tmp_height, tmp_width);
			tmp_width++;
		}
		tmp_height--;
	}
	check_necessary_el(game);
	check_wall_closed(game);
}

static int	check_map_rect(t_game *game)
{
	int				tmp_height;
	unsigned int	comp_len;
	unsigned int	current_len;

	comp_len = 0;
	current_len = 0;
	tmp_height = game->map_height - 1;
	while (tmp_height >= 0)
	{
		if (ft_strrchr(game->map[tmp_height], '\n'))
			current_len = ft_strlen(game->map[tmp_height]) - 1;
		else
			current_len = ft_strlen(game->map[tmp_height]);
		if (comp_len == 0)
			comp_len = current_len;
		else
		{
			if (current_len != comp_len)
				return (0);
		}
		tmp_height--;
	}
	game->map_width = comp_len;
	return (1);
}

void	check_map_conditions(t_game *game)
{
	if (!check_map_rect(game))
		game_free_and_error(
			"The map has an irregular shape. It must be rectangular", game);
	check_map_symbols(game);
}
