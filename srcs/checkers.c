/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:33:07 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/20 19:00:51 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_ext_ber(char *str)
{
	int		str_length;
	char	*ext_ber;
	int		ext_ber_length;

	ext_ber = "ber";
	ext_ber_length = 3;
	str_length = ft_strlen(str);
	while (ext_ber_length > 0)
	{
		if (str[str_length] != ext_ber[ext_ber_length])
			return (0);
		ext_ber_length--;
		str_length--;
	}	
	return (1);
}

void	chech_map_conditions(t_game game)
{
	if (!check_map_rect(game))
		game_error("The map has an irregular shape. It must be rectangular");
}

int	check_map_path(char *str)
{
	if (!ft_strrchr(str, '.'))
	{
		game_error("Invalid file name, missing extension");
	}
	else if (!check_ext_ber(str))
	{
		game_error("Unsupported file type. Please, use only .ber extension.");
	}
	return (1);
}
