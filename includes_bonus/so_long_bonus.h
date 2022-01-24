/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 03:48:02 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/24 22:37:55 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../srcs/get_next_line/get_next_line.h"
# include "../mlx-linux/mlx.h"

/* Images Bonus paths */
# define IMGSIZE 45
# define FRAME_RATE 5
# define IMGPATH "./images_bonus/"
# define GRASS "grass.xpm"
# define ROCK "tree.xpm"
# define EXIT "chest_open.xpm"
# define EXIT_CL "chest_closed.xpm"
# define PLAYER_F "player_face.xpm"
# define PLAYER_B "player_top.xpm"
# define PLAYER_L "player_left.xpm"
# define PLAYER_R "player_right.xpm"
# define ENEMY "skelet.xpm"
# define PLAYER_WIN "winner.xpm"
# define PLAYER_DIED "died.xpm"

/* Coin images */
# define COLLECT1 "coin1.xpm"
# define COLLECT2 "coin2.xpm"
# define COLLECT3 "coin3.xpm"
# define COLLECT4 "coin4.xpm"
# define COLLECT5 "coin5.xpm"
# define COLLECT6 "coin6.xpm"

/* Enemy Images */
# define ENEMY1 "skel01.xpm"
# define ENEMY2 "skel02.xpm"
# define ENEMY3 "skel03.xpm"
# define ENEMY4 "skel04.xpm"

/* Mover counter */
# define MOVES_TEXT "MOVES COUNT: "
# define IF_WIN_TEXT "*** You Win! ***"
# define IF_LOSE_TEXT "*** You lose! ***"
# define COUNTER_COLOR 0xFFFFFF
# define RESULT_COLOR 0xFF00000
/* Valid map symbols */
# define EMPTY_EL '0'
# define WALL_EL '1'
# define COIN_EL 'C'
# define EXIT_EL 'E'
# define PLAYER_EL 'P'

/* Enemy */
# define ENEMY_EL 'S'

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


typedef struct s_list
{
	int				x_pos;
	int				y_pos;
	int				orient;
	struct s_list	*next;
}	t_list;


/* map elements */
typedef struct s_data {
	int		empty_el;
	int		wall_el;
	int		coin_el;
	int		player;
	int		exit;
	int		enemy;
}			t_data;

/* Enemy Profile */
typedef struct s_skelet {
	int		face;
	int		wait;
}			t_skelet;


/* Animations */
typedef struct s_anima {
	void	*img01;
	void	*img02;
	void	*img03;
	void	*img04;
	void	*img05;
	void	*img06;
}			t_anima;

/* Images */
typedef struct s_image {
	void		*grass;
	void		*rock;
	void		*exit;
	void		*exit_cl;
	t_anima		orb;
	void		*player;
	void		*player_up;
	void		*player_le;
	void		*player_ri;
	void		*win;
	int			img_width;
	int			img_height;
	t_anima		enemy;
	void		*died;
}			t_image;

/* Game structure */
typedef struct s_game {
	void		*mlx;
	void		*mlx_win;
	int			map_height;
	int			map_width;
	char		**map;
	int			moves;
	int			collect;
	int			player_x_pos;
	int			player_y_pos;
	int			passed;
	int			died;
	int			the_end;
	t_image		img;
	t_data		elements;
	int			player_face;
	int			map_begin;
	int			map_end;
	int			frame_count;
	int			anim_count;
	t_skelet	skelet;
	t_list		*en_coord;
}			t_game;

/* Initialization */
void	init_game_vars(t_game	*game);
void	xwindow_init(t_game	*game);
void	game_start(t_game *game, char *path);
void	load_images(t_game	*game);
void	find_map_size(char *path, t_game *game);
int		read_map(char *path, t_game *game);
int		next_pict(t_game *game);

/* Draw Map Picture */
void	symb_to_img(t_game	*game);

/* Errors */
void	game_error(char *message);
void	system_error(char *message);
void	game_free_and_error(char *message, t_game *game);

/* Verifiers */
int		check_map_path(char *str);
void	check_map_conditions(t_game *game);
void	check_wall_closed(t_game *game);
void	check_diff_map_obj(char *path);

/*Hooks and moves*/
void	hooks(t_game *game);
int		step_conditions(t_game *game, int y_pos, int x_pos);
void	player_steps(t_game *game, int y_pos, int x_pos);
void	player_look_and_move(int keycode, t_game *game);

/* Free and close */
int		close_window(t_game *game);
void	winner(t_game *game);

void	add_enemy_coo(t_game *game, int tmp_height, int tmp_width);
void	enemy_move(t_game	*game);
void	enemy_list_free(t_game *game);

#endif