/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 00:07:41 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/24 23:02:23 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	add_enemy_elem(t_game	*game, int tmp_height, int tmp_width)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
				game->img.enemy.img01, IMGSIZE * tmp_width, \
				IMGSIZE * tmp_height);
}

static void	add_grass_elem(t_game	*game, int tmp_height, int tmp_width)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
	game->img.grass, IMGSIZE * tmp_width, IMGSIZE * tmp_height);
}

static void	add_wall_elem(t_game	*game, int tmp_height, int tmp_width)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
	game->img.rock, IMGSIZE * tmp_width, IMGSIZE * tmp_height);
}

static void	add_exit_elem(t_game	*game, int tmp_height, int tmp_width)
{
	if (game->collect != game->elements.coin_el)
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->img.exit_cl, IMGSIZE * tmp_width, IMGSIZE * tmp_height);
	else
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->img.exit, IMGSIZE * tmp_width, IMGSIZE * tmp_height);
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
				add_grass_elem(game, tmp_height, tmp_width);
			else if (game->map[tmp_height][tmp_width] == WALL_EL)
				add_wall_elem(game, tmp_height, tmp_width);
			else if (game->map[tmp_height][tmp_width] == COIN_EL)
				add_coin_elem(game, tmp_height, tmp_width);
			else if (game->map[tmp_height][tmp_width] == PLAYER_EL)
				add_player_elem(game, tmp_height, tmp_width);
			else if (game->map[tmp_height][tmp_width] == EXIT_EL)
				add_exit_elem(game, tmp_height, tmp_width);
			else if (game->map[tmp_height][tmp_width] == ENEMY_EL)
				add_enemy_elem(game, tmp_height, tmp_width);
			tmp_width++;
		}
		tmp_height--;
	}
}
