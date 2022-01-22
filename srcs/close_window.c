/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:47:00 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/22 04:29:38 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(EXIT_SUCCESS);
}

void	winner(t_game *game)
{
	printf("\033[1;34mYou Win! \033[0m");
	printf("Result: \033[1;32m%i\033[0m moves and \033[1;33m%i\033[0m coins\n", \
	game->moves, game->collect);
	close_window(game);
}
