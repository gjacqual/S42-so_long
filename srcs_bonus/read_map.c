/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 03:29:42 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/23 18:19:04 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	diff_recta_check(t_game *game, int i)
{
	if ((game->map_begin && game->map_end) && i < game->map_height)
		game_error("It looks like there are several maps in the file");
}

static void	getline_loop(t_game *game, char *tmp_line, int fd)
{
	int		i;

	i = 0;
	while (1)
	{	
		diff_recta_check(game, i);
		tmp_line = get_next_line(fd);
		if (tmp_line != NULL)
		{
			if (tmp_line[0] != '\n')
			{
				game->map_begin = 1;
				game->map[i++] = tmp_line;
			}
			else
			{
				if (game->map_begin == 1)
					game->map_end = 1;
				free(tmp_line);
			}
		}
		else
			break ;
	}
	free(tmp_line);
}

/* Reading data from a map file.ber and rendering of the game world */
int	read_map(char *path, t_game *game)
{
	int		fd;
	char	*tmp_line;

	check_diff_map_obj(path);
	find_map_size(path, game);
	tmp_line = NULL;
	game->map = malloc(sizeof(char *) * game->map_height + 1);
	if (game->map == NULL)
		system_error("No memory allocated");
	fd = open(path, O_RDONLY);
	if (fd == -1)
		system_error("Opening the file failed");
	getline_loop(game, tmp_line, fd);
	close(fd);
	return (1);
}
