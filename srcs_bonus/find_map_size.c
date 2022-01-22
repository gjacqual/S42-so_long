/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:33:16 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/23 00:42:39 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_chars(char c)
{
	if (c == EMPTY_EL || c == WALL_EL \
	|| c == COIN_EL || c == EXIT_EL || c == PLAYER_EL)
		return (1);
	else
		return (0);
}

void	check_diff_map_obj(char *path)
{
	int		fd;
	int		r_size;
	char	buf;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		system_error("Opening the file failed");
	while (1)
	{
		r_size = read(fd, &buf, 1);
		if (r_size == -1)
			game_error("File reading error");
		if (!valid_chars(buf) && (buf != '\n'))
			game_error("Invalid symbol found in the file.");
		if (r_size == 0)
			break ;
	}
	close(fd);
}

void	map_size_loop(t_game *game, int fd, int str_length )
{
	int		r_size;
	char	buf;

	while (1)
	{
		r_size = read(fd, &buf, 1);
		if (r_size == -1)
			game_error("File reading error");
		if ((r_size == 0 && str_length > 0) || (buf == '\n' && str_length > 0))
		{
			game->map_height++;
			str_length = 0;
		}
		else if (r_size == 0 && str_length == 0 && game->map_height == 0)
			game_error("Empty file");
		if (r_size == 0)
			break ;
		if (valid_chars(buf))
			str_length++;
	}
}

void	find_map_size(char *path, t_game *game)
{
	int		fd;
	int		str_length;

	str_length = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		system_error("Opening the file failed");
	map_size_loop(game, fd, str_length);
	close(fd);
}
