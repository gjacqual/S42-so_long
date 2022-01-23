/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_picture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 03:33:15 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/23 21:16:04 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	string_on_win(t_game	*game)
{
	char	*text;
	int		player_moves;
	char	*score;
	int		space;

	player_moves = game->moves;
	score = ft_itoa(player_moves);
	if (score == NULL)
		game_free_and_error("Error creating a line for counting steps", game);
	text = MOVES_TEXT;
	space = ft_strlen(text) * 6;
	mlx_string_put(game->mlx, game->mlx_win, 10, 20, \
	COUNTER_COLOR, text);
	mlx_string_put(game->mlx, game->mlx_win, 100, 20, \
	COUNTER_COLOR, score);
	free(score);
	if (game->passed == 1 || game->died == 1)
	{	
		if (game->passed == 1)
			text = IF_WIN_TEXT;
		else if (game->died == 1)
			text = IF_LOSE_TEXT;
		mlx_string_put(game->mlx, game->mlx_win, 125, 20, \
		RESULT_COLOR, text);
	}
}

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
	string_on_win(game);
	return (0);
}
