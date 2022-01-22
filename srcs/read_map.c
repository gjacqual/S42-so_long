/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 03:29:42 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/22 17:21:52 by gjacqual         ###   ########.fr       */
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

static	void	find_map_size(char *path, t_game *game)
{
	int		fd;
	int		file_height;
	int		str_length;
	int		reading_size;
	char	buf;

	file_height = 0;
	str_length = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		system_error("Opening the file failed");
	reading_size = read(fd, &buf, 1);
	if (reading_size < 0)
		game_error("File reading error");
	else if (reading_size == 0)
		system_error("Empty File");
	else
	{
		if (valid_chars(buf))
			str_length++;
		else if (buf == '\n')
			;
		else
			game_error("Invalid first element found in the map");
	}		
	while (reading_size > 0)
	{
		reading_size = read(fd, &buf, 1);
		if (reading_size < 0)
			game_error("File reading error");
		else if (reading_size == 0 && str_length > 0)
		{
			file_height++;
			str_length = 0;
		}
		if (valid_chars(buf))
			str_length++;
		else if (buf == '\n' && str_length > 0)
		{
			file_height++;
			game->map_width = str_length;
			str_length = 0;
		}
		else if (buf == '\n' && str_length == 0)
			;
		else
			game_error("Invalid another element found in the map");
	}
	game->map_height = file_height;
	close(fd);
}

/* Reading data from a map file.ber and rendering of the game world */
int	read_map(char *path, t_game *game)
{
	int		fd;
	char	*tmp_line;
	int		i;

	find_map_size(path, game);
	tmp_line = NULL;
	game->map = NULL;
	game->map = malloc(sizeof(char *) * game->map_height + 1);
	if (game->map == NULL)
		system_error("No memory allocated");
	fd = open(path, O_RDONLY);
	if (fd == -1)
		system_error("Opening the file failed");
	i = 0;
	tmp_line = get_next_line(fd);
	if (tmp_line[0] != '\n')
		game->map[i] = tmp_line;
	while (tmp_line != NULL)
	{	
		tmp_line = get_next_line(fd);
		game->map[++i] = tmp_line;
	}
	free(tmp_line);
	game->map[i] = NULL;
	close(fd);
	return (1);
}
