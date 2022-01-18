/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 03:48:02 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/18 16:22:09 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "../libft/libft.h"
# include "../mlx-linux/mlx.h"

typedef struct s_vars {
	void	*mlx;
	void	*mlx_win;
}				t_vars;

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

void	error(char *message);
int		check_map_path(char *str);
void	xwindow_init(void);

#endif