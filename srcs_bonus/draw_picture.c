/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_picture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 03:33:15 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/24 10:29:05 by gjacqual         ###   ########.fr       */
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

void	speed_manage(t_game *game)
{
	game->frame_count++;
	if (game->frame_count == FRAME_RATE)
	{	
		game->frame_count = 0;
		game->anim_count++;
		game->skelet.wait--;
	}
	if (game->anim_count == 6)
		game->anim_count = 1;

	if (game->skelet.wait == 0)
		game->skelet.wait = 4;
}

int	next_pict(t_game *game)
{
	symb_to_img(game);
	string_on_win(game);
	speed_manage(game);
	return (0);
}
