/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_coin_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:46:21 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/24 22:47:16 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	add_coin_elem(t_game	*game, int tmp_height, int tmp_width)
{
	if (game->anim_count == 1)
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->img.orb.img01, IMGSIZE * tmp_width, IMGSIZE * tmp_height);
	else if (game->anim_count == 2)
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->img.orb.img02, IMGSIZE * tmp_width, IMGSIZE * tmp_height);
	else if (game->anim_count == 3)
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->img.orb.img03, IMGSIZE * tmp_width, IMGSIZE * tmp_height);
	else if (game->anim_count == 4)
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->img.orb.img04, IMGSIZE * tmp_width, IMGSIZE * tmp_height);
	else if (game->anim_count == 5)
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->img.orb.img05, IMGSIZE * tmp_width, IMGSIZE * tmp_height);
	else if (game->anim_count == 6)
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->img.orb.img06, IMGSIZE * tmp_width, IMGSIZE * tmp_height);
}
