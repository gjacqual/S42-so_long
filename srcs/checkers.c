/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:33:07 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/17 23:44:32 by gjacqual         ###   ########.fr       */
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

int	check_map_path(char *str)
{
	if (!ft_strrchr(str, '.'))
	{
		error("Invalid file name, missing extension");
	}
	else if (!check_ext_ber(str))
	{
		error("Unsupported file type. Please, use only .ber extension.");
	}
	return (1);
}
