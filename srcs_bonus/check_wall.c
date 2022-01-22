/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 02:51:53 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/22 02:53:57 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	check_wall_closed(t_game *game)
{
	if (!check_g_wall(game->map[0])
		|| !check_g_wall(game->map[game->map_height - 1]))
		game_free_and_error(
			"The map must be closed. Check the horizontal walls", game);
	if (!check_v_wall(game))
		game_free_and_error(
			"The map must be closed. Check the veritcal walls", game);
}
