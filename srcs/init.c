/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 00:25:30 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/19 05:42:19 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Upload all images to the game */
void load_images(t_game	*game)
{
	t_image	img;

	img.grass = mlx_xpm_file_to_image(game->mlx, IMGPATH GRASS, &img.img_width, &img.img_height);
	img.rock = mlx_xpm_file_to_image(game->mlx, IMGPATH ROCK, &img.img_width, &img.img_height);
	img.exit = mlx_xpm_file_to_image(game->mlx, IMGPATH EXIT, &img.img_width, &img.img_height);
	img.orb = mlx_xpm_file_to_image(game->mlx, IMGPATH COLLECT, &img.img_width, &img.img_height);
	img.player = mlx_xpm_file_to_image(game->mlx, IMGPATH PLAYER, &img.img_width, &img.img_height);
	img.enemy = mlx_xpm_file_to_image(game->mlx, IMGPATH ENEMY, &img.img_width, &img.img_height);

	mlx_put_image_to_window(game->mlx, game->mlx_win, img.grass, 30, 0);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.rock, 50, 50);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.exit, 100, 100);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.orb, 150, 150);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.player, 200, 200);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.enemy, 250, 250);
	
}

static void find_map_size(char *path, t_game *game)
{
	int fd;
	int map_height;
	//int map_width;
	int reading_size;
	char c;
	
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error("ФАЙЛ НЕ ОТКРЫЛСЯ"); // ДОРАБОТАТЬ БЛОК ВЫВОДА ОШИБОК
	map_height = 0;
	reading_size = read(fd, &c, 1);
	if (reading_size > 0)
		map_height = 1;
	else
		error("Пустой Файл"); // ДОРАБОТАТЬ БЛОК ВЫВОДА ОШИБОК
	while(reading_size > 0)
	{
		reading_size = read(fd, &c, 1);
		if (reading_size < 0)
			error("Ошибка чтения файла"); // ДОРАБОТАТЬ БЛОК ВЫВОДА ОШИБОК
		if (c == '\n')
			map_height++;
	}
	game->map_height = map_height;
	printf("Высота карты: %i\n", game->map_height);
	close(fd);	
}


/* Reading data from a map file.ber and rendering of the game world */
void read_map(char *path, t_game *game)
{
	int fd;
	char **tmp_map;
	int i;

	find_map_size(path, game);
	
	tmp_map = malloc(sizeof(char *) * game->map_height + 1);
	if (tmp_map == NULL)
		error("Память не выделена"); // ДОРАБОТАТЬ БЛОК ВЫВОДА ОШИБОК
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error("ФАЙЛ НЕ ОТКРЫЛСЯ"); // ДОРАБОТАТЬ БЛОК ВЫВОДА ОШИБОК
	i = 0;
	tmp_map[i] = get_next_line(fd);
	while(tmp_map[i] != NULL)
	{	
		tmp_map[++i] = get_next_line(fd);
	}
	tmp_map[i] = NULL;
	game->map = tmp_map;
	free(tmp_map);
	printf("1 строка: %s\n", game->map[1]);
	printf("2 строка: %s\n", game->map[0]);
	printf("3 строка: %s\n", game->map[1]);
	printf("4 строка: %s\n", game->map[2]);
	printf("5 строка: %s\n", game->map[3]);
	printf("6 строка: %s\n", game->map[4]);
	printf("7 строка: %s\n", game->map[5]);
	printf("8 строка: %s\n", game->map[6]);
	close(fd);
}



/* Initializing the game window */
void	xwindow_init(t_game	*game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		error("Window initialization failed");
	game->mlx_win = mlx_new_window(game->mlx, 800, 600, "So_long - Gjacqual 2D Game");
}

void game_start(t_game	*game, char *path)
{
	game->map_height = 0;
	xwindow_init(game);
	load_images(game);
	read_map(path, game);
	mlx_string_put(game->mlx, game->mlx_win, 10, 15, COUNTER_COLOR, "Move count:");
	mlx_hook(game->mlx_win, 17, 0, close_window, &game);
	mlx_loop(game->mlx);
}
