/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_look.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 00:31:52 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/24 06:32:27 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	player_move_y(int keycode, t_game *game, int y_pos)
{
	if (keycode == UP)
	{
		y_pos = y_pos - 1;
		game->player_face = 2;
	}
	else if (keycode == DOWN)
	{	
		game->player_face = 1;
		y_pos = y_pos + 1;
	}
	return (y_pos);
}

static int	player_move_x(int keycode, t_game *game, int x_pos)
{
	if (keycode == LEFT)
	{
		game->player_face = 3;
		x_pos = x_pos - 1;
	}	
	else if (keycode == RIGHT)
	{
		game->player_face = 4;
		x_pos = x_pos + 1;
	}
	return (x_pos);
}

void	player_look_and_move(int keycode, t_game *game)
{
	int	x_pos;
	int	y_pos;

	x_pos = game->player_x_pos;
	y_pos = game->player_y_pos;
	if (keycode == UP || keycode == DOWN)
		y_pos = player_move_y(keycode, game, y_pos);
	else if (keycode == LEFT || keycode == RIGHT)
		x_pos = player_move_x(keycode, game, x_pos);
	if (step_conditions(game, y_pos, x_pos))
		player_steps(game, y_pos, x_pos);
}
