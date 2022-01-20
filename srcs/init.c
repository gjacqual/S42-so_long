/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 00:25:30 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/20 18:54:52 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Upload all images to the game */
void	load_images(t_game	*game)
{
	t_image	img;

	img.grass = mlx_xpm_file_to_image(
			game->mlx, IMGPATH GRASS, &img.img_width, &img.img_height);
	img.rock = mlx_xpm_file_to_image(
			game->mlx, IMGPATH ROCK, &img.img_width, &img.img_height);
	img.exit = mlx_xpm_file_to_image(
			game->mlx, IMGPATH EXIT, &img.img_width, &img.img_height);
	img.orb = mlx_xpm_file_to_image(
			game->mlx, IMGPATH COLLECT, &img.img_width, &img.img_height);
	img.player = mlx_xpm_file_to_image(
			game->mlx, IMGPATH PLAYER, &img.img_width, &img.img_height);
	img.enemy = mlx_xpm_file_to_image(
			game->mlx, IMGPATH ENEMY, &img.img_width, &img.img_height);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.grass, 30, 0);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.rock, 50, 50);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.exit, 100, 100);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.orb, 150, 150);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.player, 200, 200);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.enemy, 250, 250);
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
	game->mlx_win = mlx_new_window(\
	game->mlx, 800, 600, "So_long - Gjacqual 2D Game");
}

void	init_game_vars(t_game	*game)
{
	game->map_height = 0;
}

/* The game starts In this function */
void	game_start(t_game	*game, char *path)
{
	init_game_vars(game);
	if (read_map(path, game))
	{
		chech_map_conditions(game);
		
		// Проверка валидности карты ( 
			// Разная длинна линий, - проверка на прямоугольник
			// неверные символы, 
		// не окружена полностью препятствиями, 
		// нет всех нужных символов )

		// Инициализация всех параметров (обновить списко init_game_vars(game); )
		xwindow_init(game);
		load_images(game);

		// рендеринг карты и добавление на нее картинок
		//  хуки перехвата событий клавиатуры лево прово верх ни 
		//  mlx_loop_hook - рендеринг следующего кардра и анимация

		
	}

	// test 
	printf("-------\n");
	int j;
	j = 0;
	while(game->map[j])
	{
		printf("%i - строка: %s\n", j, game->map[j]);
		j++;
	}
	// end - test
	
	mlx_string_put(game->mlx, game->mlx_win, 10, 15, COUNTER_COLOR, "Move count:");
	mlx_hook(game->mlx_win, 17, 0, close_window, &game);
	mlx_loop(game->mlx);
}
