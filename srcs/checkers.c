/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:33:07 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/21 06:01:33 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_ext_ber(char *str)
{
	int		str_length;
	char	*ext_ber;
	int		ext_ber_length;

	ext_ber = "ber";
	ext_ber_length = 3;
	str_length = ft_strlen(str);
	while (ext_ber_length > 0)
	{
		if (str[str_length] != ext_ber[ext_ber_length])
			return (0);
		ext_ber_length--;
		str_length--;
	}	
	return (1);
}

static int	check_g_wall(char *wall)
{
	while (*wall)
	{
		if (*wall != WALL_EL && *wall != '\n')
			return (0);
		wall++;
	}
	return (1);
}

static int	check_v_wall(t_game *game)
{
	int	tmp_width;
	int	tmp_height;
	int	i;

	tmp_height = game->map_height - 1;
	while (tmp_height >= 0)
	{
		if (game->map[tmp_height][0] != WALL_EL)
			return (0);
		tmp_width = ft_strlen(game->map[tmp_height]);
		if (ft_strrchr(game->map[tmp_height], '\n'))
			i = 2;
		else
			i = 1;
		if (game->map[tmp_height][tmp_width - i] != WALL_EL)
			return (0);
		tmp_height--;
	}
	return (1);
}

static void	check_wall_closed(t_game *game)
{
	if (!check_g_wall(game->map[0])
		|| !check_g_wall(game->map[game->map_height - 1]))
		game_free_and_error(
			"The map must be closed. Check the horizontal walls", game);
	if (!check_v_wall(game))
		game_free_and_error(
			"The map must be closed. Check the veritcal walls", game);
}

static void	check_necessary_el(t_data *elements, t_game *game)
{
	if (elements->exit == 0)
		game_free_and_error("Map must contain at least one exit", game);
	if (elements->coin_el == 0)
		game_free_and_error("Map must contain at least one collectible", game);
	if (elements->player == 0)
		game_free_and_error("Map must contain one starting position", game);
	else if (elements->player > 1)
		game_free_and_error(
			"Map must contain only one starting position", game);
}


static void check_map_symbols(t_game *game)
{
	t_data	elements;
	int		tmp_height;
	int		tmp_width;

	tmp_height = game->map_height - 1;
	elements.empty_el = 0;
	elements.wall_el = 0;
	elements.coin_el = 0;
	elements.player = 0;
	elements.exit = 0;

	while (tmp_height >= 0)
	{
		tmp_width = 0;
		while (game->map[tmp_height][tmp_width])
		{
			if (game->map[tmp_height][tmp_width] == EMPTY_EL)
				elements.empty_el++;
			else if (game->map[tmp_height][tmp_width] == WALL_EL)
				elements.wall_el++;
			else if (game->map[tmp_height][tmp_width] == COIN_EL)
				elements.coin_el++;
			else if (game->map[tmp_height][tmp_width] == PLAYER_EL)
				elements.player++;
			else if (game->map[tmp_height][tmp_width] == EXIT_EL)
				elements.exit++;
			else if (game->map[tmp_height][tmp_width] != '\n')
				game_free_and_error("Invalid element found in the map", game);
			tmp_width++;
		}
		tmp_height--;
	}
	check_necessary_el(&elements, game);
	check_wall_closed(game);
}


static int	check_map_rect(t_game *game)
{
	int tmp_height;
	unsigned int comp_len;
	unsigned int current_len;
	

	comp_len = 0;
	current_len = 0;
	tmp_height = game->map_height - 1;
	while(tmp_height >= 0)
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
		game_free_and_error("The map has an irregular shape. It must be rectangular", game);
	check_map_symbols(game);
	
}

int	check_map_path(char *str)
{
	if (!ft_strrchr(str, '.'))
	{
		game_error("Invalid file name, missing extension");
	}
	else if (!check_ext_ber(str))
	{
		game_error("Unsupported file type. Please, use only .ber extension.");
	}
	return (1);
}
