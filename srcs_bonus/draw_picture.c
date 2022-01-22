/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_picture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 03:33:15 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/23 01:36:12 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_active_elem(t_game	*game, int tmp_height, int tmp_width)
{
	if (game->map[tmp_height][tmp_width] == PLAYER_EL)
	{
		if (game->passed == 1)
			mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->img.win, IMGSIZE * tmp_width, IMGSIZE * tmp_height);
		else
			mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->img.player, IMGSIZE * tmp_width, IMGSIZE * tmp_height);
	}
	if (game->map[tmp_height][tmp_width] == EXIT_EL)
	{
		if (game->collect != game->elements.coin_el)
			mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->img.exit_cl, IMGSIZE * tmp_width, IMGSIZE * tmp_height);
		else
			mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->img.exit, IMGSIZE * tmp_width, IMGSIZE * tmp_height);
	}
}

void	symb_to_img(t_game	*game)
{
	int	tmp_height;
	int	tmp_width;

	tmp_height = game->map_height - 1;
	while (tmp_height >= 0)
	{
		tmp_width = 0;
		while (game->map[tmp_height][tmp_width])
		{
			if (game->map[tmp_height][tmp_width] == EMPTY_EL)
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
				game->img.grass, IMGSIZE * tmp_width, IMGSIZE * tmp_height);
			else if (game->map[tmp_height][tmp_width] == WALL_EL)
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
				game->img.rock, IMGSIZE * tmp_width, IMGSIZE * tmp_height);
			else if (game->map[tmp_height][tmp_width] == COIN_EL)
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
				game->img.orb, IMGSIZE * tmp_width, IMGSIZE * tmp_height);
			else
				add_active_elem(game, tmp_height, tmp_width);
			tmp_width++;
		}
		tmp_height--;
	}
	tmp_height = game->map_height - 1;
}

int	next_pict(t_game *game)
{
	symb_to_img(game);
	return (0);
}
