/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 00:25:30 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/22 02:42:13 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Upload all images to the game */
void	load_images(t_game	*game)
{

	game->img.grass = mlx_xpm_file_to_image(
			game->mlx, IMGPATH GRASS, &game->img.img_width, &game->img.img_height);
	game->img.rock = mlx_xpm_file_to_image(
			game->mlx, IMGPATH ROCK, &game->img.img_width, &game->img.img_height);
	game->img.exit = mlx_xpm_file_to_image(
			game->mlx, IMGPATH EXIT, &game->img.img_width, &game->img.img_height);
	game->img.orb = mlx_xpm_file_to_image(
			game->mlx, IMGPATH COLLECT, &game->img.img_width, &game->img.img_height);
	game->img.player = mlx_xpm_file_to_image(
			game->mlx, IMGPATH PLAYER, &game->img.img_width, &game->img.img_height);
	game->img.enemy = mlx_xpm_file_to_image(
			game->mlx, IMGPATH ENEMY, &game->img.img_width, &game->img.img_height);
}
static	void	find_map_size(char *path, t_game *game)
{
	int		fd;
	int		map_height;
	int		reading_size;
	char	c;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		system_error("Opening the file failed");
	map_height = 0;
	reading_size = read(fd, &c, 1);
	if (reading_size > 0)
		map_height = 1;
	else
		system_error("Empty File");
	while (reading_size > 0)
	{
		reading_size = read(fd, &c, 1);
		if (reading_size < 0)
			game_error("File reading error");
		if (c == '\n')
			map_height++;
	}
	game->map_height = map_height;
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

/* Initializing the game window */
void	xwindow_init(t_game	*game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		game_error("Window initialization failed");
}

void	init_game_vars(t_game	*game)
{
	game->map_height = 0;
	game->map_width = 0;
	game->moves = 0;
	game->collect = 0;
	game->player_x_pos = 0;
	game->player_y_pos = 0;
	game->passed = 0;
}


void symb_to_img(t_game	*game)
{
	int tmp_height;
	int tmp_width;

	tmp_height = game->map_height - 1;
	while(tmp_height >= 0)
	{
		tmp_width = 0;
		while (game->map[tmp_height][tmp_width])
		{
			if (game->map[tmp_height][tmp_width] == EMPTY_EL)
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.grass, IMGSIZE * tmp_width, IMGSIZE * tmp_height);
			else if (game->map[tmp_height][tmp_width] == WALL_EL)
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.rock, IMGSIZE * tmp_width, IMGSIZE * tmp_height);
			else if (game->map[tmp_height][tmp_width] == COIN_EL)
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.orb, IMGSIZE * tmp_width, IMGSIZE * tmp_height);
			else if (game->map[tmp_height][tmp_width] == PLAYER_EL)
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.player, IMGSIZE * tmp_width, IMGSIZE * tmp_height);
			else if (game->map[tmp_height][tmp_width] == EXIT_EL)
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.exit, IMGSIZE * tmp_width, IMGSIZE * tmp_height);
			tmp_width++;
		}

		tmp_height--;
	}
	tmp_height = game->map_height - 1;
}

void draw_pict(t_game *game)
{
	symb_to_img(game);
	mlx_string_put(
		game->mlx, game->mlx_win, 10, 15, COUNTER_COLOR, "Move count:");
}

int	next_pict(t_game *game)
{
	 draw_pict(game);
	return (0);
}

int step_conditions(t_game *game, int y_pos, int x_pos)
{
	char *cur_pos;
	char *step_pos;

	cur_pos = &game->map[game->player_y_pos][game->player_x_pos];
	step_pos = &game->map[y_pos][x_pos];

	if (*step_pos == WALL_EL)
		return (0);
	if (*step_pos == EXIT_EL)
	{
		if (game->collect != game->elements.coin_el)
			return (0);
		else
		{	
			game->passed = 1;
			return (1);
		}
	}
	
	return (1);
}

void player_steps(t_game *game, int y_pos, int x_pos)
{
	char *cur_pos;
	char *step_pos;

	cur_pos = &game->map[game->player_y_pos][game->player_x_pos];
	step_pos = &game->map[y_pos][x_pos];
	
	*cur_pos = EMPTY_EL;
	if (*step_pos == COIN_EL)
		game->collect++;
	*step_pos = PLAYER_EL;
	game->player_x_pos = x_pos;
	game->player_y_pos = y_pos;
	game->moves++;
	printf("Moves: %i\n", game->moves);
}

void winner(t_game *game)
{
	printf("\033[1;34mYou Win!\033[0m Result: \033[1;32m%i\033[0m moves and \033[1;33m%i\033[0m coins\n", game->moves, game->collect);
	close_window(game);
}


int key_hook(int keycode, t_game *game)
{
	int x_pos;
	int y_pos;
	
	x_pos = game->player_x_pos;
	y_pos = game->player_y_pos;
	
	if (keycode == ESC || keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
	{
		if (keycode == ESC)
			close_window(game);
		else if (keycode == UP)
			y_pos = y_pos - 1;
		else if (keycode == DOWN)
			y_pos = y_pos + 1;
		else if (keycode == LEFT)
			x_pos = x_pos - 1;
		else if (keycode == RIGHT)
			x_pos = x_pos + 1;
		if (step_conditions(game, y_pos, x_pos)) 
		{
			if (game->passed == 1)
				winner(game);
			player_steps(game, y_pos, x_pos);
		}
	}
	return (0);
}


void hooks(t_game *game)
{
	mlx_key_hook (game->mlx_win, key_hook, game);
	mlx_hook(game->mlx_win, 17, 0L, close_window, game);
	mlx_loop_hook(game->mlx, &next_pict, game);
}

/* The game starts In this function */
void	game_start(t_game *game, char *path)
{
	init_game_vars(game);
	if (read_map(path, game))
	{
		check_map_conditions(game);
		xwindow_init(game);
		load_images(game);
		game->mlx_win = mlx_new_window(game->mlx, IMGSIZE * game->map_width, IMGSIZE * game->map_height, "so_long");
		hooks(game);
		mlx_loop(game->mlx);
	}
	
}
