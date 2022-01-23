/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 02:24:28 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/23 06:59:51 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char	**argv)
{
	t_game	game;

	if (argc != 2)
		game_error("Enter one map file path (ex: ./so_long maps/map.ber)");
	else if (check_map_path(argv[1]))
	{
		game_start(&game, argv[1]);
		return (0);
	}
	else
		return (0);
}
