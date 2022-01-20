/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 03:48:02 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/20 03:46:25 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../srcs/get_next_line/get_next_line.h"
# include "../mlx-linux/mlx.h"

# define IMGPATH "./images/"
# define GRASS "grass.xpm"
# define ROCK "rock.xpm"
# define EXIT "chest.xpm"
# define COLLECT "blue_orb.xpm"
# define PLAYER "player.xpm"
# define ENEMY "skelet.xpm"
# define COUNTER_COLOR 0xFFFFFF

typedef struct s_game {
	void	*mlx;
	void	*mlx_win;
	int 	map_height;
	char 	**map;
}				t_game;

typedef struct s_image {
	void	*grass;
	void	*rock;
	void	*exit;
	void	*orb;
	void	*player;
	void	*enemy;
	int		img_width;
	int		img_height;
}			t_image;

typedef struct s_data {
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void 	init_game_vars(t_game	*game);
void	game_error(char *message);
void	system_error(char *message);
int		check_map_path(char *str);
void	xwindow_init(t_game	*game);
void 	game_start(t_game *game, char *path);
int		close_window();

#endif