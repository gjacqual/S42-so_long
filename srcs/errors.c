/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:34:26 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/20 23:42:27 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	game_free_and_error(char *message, t_game *game)
{	
	int i;
	i = 0;
	while(game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	ft_putendl_fd("\033[1;31mError\033[0m", 2);
	ft_putstr_fd("\033[31m>>>", 2);
	ft_putstr_fd(message, 2);
	ft_putendl_fd("\033[0m", 2);
	exit(EXIT_FAILURE);
}

void	game_error(char *message)
{	
	ft_putendl_fd("\033[1;31mError\033[0m", 2);
	ft_putstr_fd("\033[31m>>>", 2);
	ft_putstr_fd(message, 2);
	ft_putendl_fd("\033[0m", 2);
	exit(EXIT_FAILURE);
}

void	system_error(char *message)
{	
	ft_putendl_fd("\033[1;31mError\033[0m", 2);
	perror(message);
	exit(EXIT_FAILURE);
}
