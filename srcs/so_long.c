/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 02:24:28 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/18 18:51:42 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char	**argv)
{
	if (argc != 2)
	{
		error("Enter the map file path (ex: maps/map.ber) after");
	}
	else if (check_map_path(argv[1]))
	{
		xwindow_init(argv[1]);
	}
	else
		return (0);
}
