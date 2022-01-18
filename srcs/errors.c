/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:34:26 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/17 23:36:19 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *message)
{	
	ft_putendl_fd("\033[1;31mError\033[0m", 2);
	ft_putstr_fd("\033[31m>>>", 2);
	// printf("%s: \n", strerror(22));
	ft_putstr_fd(message, 2);
	// perror(strerror(22));
	ft_putendl_fd("\033[0m", 2);
	exit(EXIT_FAILURE);
}
