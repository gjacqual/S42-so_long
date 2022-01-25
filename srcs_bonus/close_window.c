/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:47:00 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/25 05:48:02 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_window(t_game *game)
{
	if (game->map != NULL)
		map_free(game);
	if (game->en_coord)
		enemy_list_free(game);
	if (game->mlx_win)
	{	
		mlx_destroy_window(game->mlx, game->mlx_win);
	}
	exit(EXIT_SUCCESS);
}
