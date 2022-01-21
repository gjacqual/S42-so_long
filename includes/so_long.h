/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 03:48:02 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/22 00:18:03 by gjacqual         ###   ########.fr       */
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

/* Images paths */
# define IMGPATH "./images/"
# define GRASS "grass.xpm"
# define ROCK "rock.xpm"
# define EXIT "chest.xpm"
# define COLLECT "blue_orb.xpm"
# define PLAYER "player.xpm"
# define ENEMY "skelet.xpm"
# define IMGSIZE 32

# define COUNTER_COLOR 0x00FFFF

/* Valid map symbols */
# define EMPTY_EL '0'
# define WALL_EL '1'
# define COIN_EL 'C'
# define EXIT_EL 'E'
# define PLAYER_EL 'P'

/* Key codes*/
# define ESC 65307
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100

/* Mac Keys */
# define M_ESC 53
# define M_UP 13
# define M_DOWN 1
# define M_LEFT 0
# define M_RIGHT 2


/* map elements */
typedef struct s_data {
	int empty_el;
	int wall_el;
	int coin_el;
	int player;
	int exit; 
}				t_data;

/* Images */
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

/* Game structure */
typedef struct s_game {
	void	*mlx;
	void	*mlx_win;
	int 	map_height;
	int		map_width;
	char 	**map;
	int		moves;
	int		collect;
	int		player_x_pos;
	int		player_y_pos;
	t_image img;
	t_data	elements;
}				t_game;


/* Initialization */
void 	init_game_vars(t_game	*game);
void	xwindow_init(t_game	*game);
void 	game_start(t_game *game, char *path);

/* Errors */
void	game_error(char *message);
void	system_error(char *message);
void	game_free_and_error(char *message, t_game *game);

/* Verifiers */
int		check_map_path(char *str);
void	check_map_conditions(t_game *game);
int		close_window(t_game *game);

#endif