/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 04:00:52 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/25 04:50:17 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/* Clears the memory allocated for lines with map symbols */
void	map_free(t_game *game)
{
	int	tmp_height;
	int	i;

	i = 0;
	tmp_height = game->map_height;
	while (i < tmp_height)
	{
		free(game->map[i++]);
	}
	free(game->map);
}
