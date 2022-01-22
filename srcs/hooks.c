/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 00:59:58 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/22 04:48:47 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	int	x_pos;
	int	y_pos;

	x_pos = game->player_x_pos;
	y_pos = game->player_y_pos;
	if (keycode == ESC || keycode == UP || keycode == DOWN \
	|| keycode == LEFT || keycode == RIGHT)
	{
		if (keycode == ESC)
			close_window(game);
		else if (keycode == UP)
			y_pos = y_pos - 1;
		else if (keycode == DOWN)
			y_pos = y_pos + 1;
		else if (keycode == LEFT)
			x_pos = x_pos - 1;
		else if (keycode == RIGHT)
			x_pos = x_pos + 1;
		if (step_conditions(game, y_pos, x_pos))
			player_steps(game, y_pos, x_pos);
	}
	return (0);
}

void	hooks(t_game *game)
{
	mlx_key_hook (game->mlx_win, key_hook, game);
	mlx_hook(game->mlx_win, 17, 0L, close_window, game);
	mlx_loop_hook(game->mlx, &next_pict, game);
}
