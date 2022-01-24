/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 00:59:58 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/24 01:24:23 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
		if (game->the_end == 1)
			return (0);
		else if (keycode == UP)
			player_look_and_move(keycode, game);
		else if (keycode == DOWN)
			player_look_and_move(keycode, game);
		else if (keycode == LEFT)
			player_look_and_move(keycode, game);
		else if (keycode == RIGHT)
			player_look_and_move(keycode, game);
	}
	return (0);
}

void	hooks(t_game *game)
{
	mlx_key_hook (game->mlx_win, key_hook, game);
	mlx_hook(game->mlx_win, 17, 0L, close_window, game);
	mlx_loop_hook(game->mlx, next_pict, game);
}
