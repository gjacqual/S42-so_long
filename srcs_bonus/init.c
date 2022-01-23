/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 00:25:30 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/23 00:12:04 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Initializing the game window */
void	xwindow_init(t_game	*game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		game_error("Window initialization failed");
}

void	init_game_vars(t_game	*game)
{
	game->map_height = 0;
	game->map_width = 0;
	game->moves = 0;
	game->collect = 0;
	game->player_x_pos = 0;
	game->player_y_pos = 0;
	game->passed = 0;
	game->the_end = 0;
	game->map = NULL;
	game->map_begin = 0;
	game->map_end = 0;
}

/* The game starts In this function */
void	game_start(t_game *game, char *path)
{
	init_game_vars(game);
	if (read_map(path, game))
	{
		check_map_conditions(game);
		xwindow_init(game);
		load_images(game);
		game->mlx_win = mlx_new_window(game->mlx, \
		IMGSIZE * game->map_width, IMGSIZE * game->map_height, "so_long");
		hooks(game);
		mlx_loop(game->mlx);
	}
}