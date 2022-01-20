/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:33:07 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/21 01:17:28 by gjacqual         ###   ########.fr       */
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

static int check_map_symbols(game)
{
	t_data elements;
	int tmp_height;
	
	tmp_height = game->map_height - 1;
	elements.empty_el = 0;
	elements.wall_el = 0;
	elements.coin_el = 0;
	elements.player = 0;
	elements.exit = 0;
	
	while (tmp_height >= 0)
	{
		
		
		tmp_height--;
	}
	 

	
	return (1);
}


static int	check_map_rect(t_game *game)
{
	int tmp_height;
	unsigned int comp_len;
	unsigned int current_len;
	

	comp_len = 0;
	current_len = 0;
	tmp_height = game->map_height - 1;
	while(tmp_height >= 0)
	{
		printf("Y позиция карты: %i\n", tmp_height);
		if (ft_strrchr(game->map[tmp_height], '\n'))
		{
			current_len = ft_strlen(game->map[tmp_height]) - 1;
		}
		else
			current_len = ft_strlen(game->map[tmp_height]);
		printf("Ширина X строки: %u\n", current_len);
		if (comp_len == 0)
			comp_len = current_len;
		else
		{
			if (current_len != comp_len)
				return (0);
		}
		tmp_height--;
	}
	game->map_width = comp_len;
	return (1);
}

void	check_map_conditions(t_game *game)
{
	if (!check_map_rect(game))
		game_free_and_error("The map has an irregular shape. It must be rectangular", game);
	if(!check_map_symbols(game))
		game_free_and_error("The map contains incorrect or extra characters. Use only 0,1,C,E,P(1 times)", game);
	
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
