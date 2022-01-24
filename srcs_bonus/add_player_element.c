/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_player_element.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:51:55 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/24 22:57:21 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	add_player_elem(t_game	*game, int tmp_height, int tmp_width)
{
	if (game->passed == 1)
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->img.win, IMGSIZE * tmp_width, IMGSIZE * tmp_height);
	else if (game->died == 1)
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->img.died, IMGSIZE * tmp_width, IMGSIZE * tmp_height);
	else
	{
		if (game->player_face == 1)
			mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->img.player, IMGSIZE * tmp_width, IMGSIZE * tmp_height);
		else if (game->player_face == 2)
			mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->img.player_up, IMGSIZE * tmp_width, IMGSIZE * tmp_height);
		else if (game->player_face == 3)
			mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->img.player_le, IMGSIZE * tmp_width, IMGSIZE * tmp_height);
		else if (game->player_face == 4)
			mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->img.player_ri, IMGSIZE * tmp_width, IMGSIZE * tmp_height);
	}
}
