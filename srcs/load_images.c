/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 03:23:04 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/22 05:54:00 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Upload all images to the game */
void	load_images(t_game	*game)
{
	game->img.grass = mlx_xpm_file_to_image(\
	game->mlx, IMGPATH GRASS, &game->img.img_width, &game->img.img_height);
	game->img.rock = mlx_xpm_file_to_image(\
	game->mlx, IMGPATH ROCK, &game->img.img_width, &game->img.img_height);
	game->img.exit = mlx_xpm_file_to_image(\
	game->mlx, IMGPATH EXIT, &game->img.img_width, &game->img.img_height);
	game->img.orb = mlx_xpm_file_to_image(\
	game->mlx, IMGPATH COLLECT, &game->img.img_width, &game->img.img_height);
	game->img.player = mlx_xpm_file_to_image(\
	game->mlx, IMGPATH PLAYER, &game->img.img_width, &game->img.img_height);
	game->img.win = mlx_xpm_file_to_image(\
	game->mlx, IMGPATH PLAYER_WIN, &game->img.img_width, &game->img.img_height);
}
