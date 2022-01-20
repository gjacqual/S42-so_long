/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 02:24:28 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/20 02:13:32 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char	**argv)
{
	t_game	game;
	
	if (argc < 2)
		game_error("Enter the map file path (ex: maps/map.ber) after");
	else if (check_map_path(argv[1]))
	{
		game_start(&game, argv[1]);
		return (0);
	}
	else
		return (0);
}
