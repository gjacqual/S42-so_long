/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 03:23:04 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/24 06:00:01 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


static void	load_enemy_images(t_game *game)
{
	game->img.enemy.img01 = mlx_xpm_file_to_image(\
	game->mlx, IMGPATH ENEMY1, &game->img.img_width, &game->img.img_height);
	game->img.enemy.img02 = mlx_xpm_file_to_image(\
	game->mlx, IMGPATH ENEMY2, &game->img.img_width, &game->img.img_height);
	game->img.enemy.img03 = mlx_xpm_file_to_image(\
	game->mlx, IMGPATH ENEMY3, &game->img.img_width, &game->img.img_height);
	game->img.enemy.img04 = mlx_xpm_file_to_image(\
	game->mlx, IMGPATH ENEMY4, &game->img.img_width, &game->img.img_height);
	if (!game->img.enemy.img01 || !game->img.enemy.img02 \
	|| !game->img.enemy.img03 || !game->img.enemy.img04)
		system_error("Loading enemy images failed. Check the folder");
}

static void	load_coin_images(t_game	*game)
{
	game->img.orb.img01 = mlx_xpm_file_to_image(\
	game->mlx, IMGPATH COLLECT1, &game->img.img_width, &game->img.img_height);
	game->img.orb.img02 = mlx_xpm_file_to_image(\
	game->mlx, IMGPATH COLLECT2, &game->img.img_width, &game->img.img_height);
	game->img.orb.img03 = mlx_xpm_file_to_image(\
	game->mlx, IMGPATH COLLECT3, &game->img.img_width, &game->img.img_height);
	game->img.orb.img04 = mlx_xpm_file_to_image(\
	game->mlx, IMGPATH COLLECT4, &game->img.img_width, &game->img.img_height);
	game->img.orb.img05 = mlx_xpm_file_to_image(\
	game->mlx, IMGPATH COLLECT5, &game->img.img_width, &game->img.img_height);
	game->img.orb.img06 = mlx_xpm_file_to_image(\
	game->mlx, IMGPATH COLLECT6, &game->img.img_width, &game->img.img_height);
	if (!game->img.orb.img01 || !game->img.orb.img02 \
	|| !game->img.orb.img03 || !game->img.orb.img04 \
	|| !game->img.orb.img05 || !game->img.orb.img06)
		system_error("Loading coins images failed. Check the folder");
}



static void	load_player_images(t_game	*game)
{
	game->img.player = mlx_xpm_file_to_image(\
	game->mlx, IMGPATH PLAYER_F, &game->img.img_width, &game->img.img_height);
	game->img.player_up = mlx_xpm_file_to_image(\
	game->mlx, IMGPATH PLAYER_B, &game->img.img_width, &game->img.img_height);
	game->img.player_le = mlx_xpm_file_to_image(\
	game->mlx, IMGPATH PLAYER_L, &game->img.img_width, &game->img.img_height);
	game->img.player_ri = mlx_xpm_file_to_image(\
	game->mlx, IMGPATH PLAYER_R, &game->img.img_width, &game->img.img_height);
	game->img.win = mlx_xpm_file_to_image(\
	game->mlx, IMGPATH PLAYER_WIN, &game->img.img_width, &game->img.img_height);
	if (!game->img.player || !game->img.player_up \
	|| !game->img.player_le || !game->img.player_ri || !game->img.win)
		system_error("Loading player images failed. Check the folder");
}

/* Upload all images to the game */
void	load_images(t_game	*game)
{
	load_player_images(game);
	load_coin_images(game);
	load_enemy_images(game);
	game->img.grass = mlx_xpm_file_to_image(\
	game->mlx, IMGPATH GRASS, &game->img.img_width, &game->img.img_height);
	game->img.rock = mlx_xpm_file_to_image(\
	game->mlx, IMGPATH ROCK, &game->img.img_width, &game->img.img_height);
	game->img.exit = mlx_xpm_file_to_image(\
	game->mlx, IMGPATH EXIT, &game->img.img_width, &game->img.img_height);
	game->img.exit_cl = mlx_xpm_file_to_image(\
	game->mlx, IMGPATH EXIT_CL, &game->img.img_width, &game->img.img_height);
	if (!game->img.grass || !game->img.rock \
	|| !game->img.exit || !game->img.exit_cl)
		system_error("Loading images failed. Check the folder");
}
