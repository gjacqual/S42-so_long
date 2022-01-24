/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:54:56 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/24 18:26:45 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	add_enemy_coo(t_game *game, int tmp_height, int tmp_width)
{
	t_list	*tmp;
	t_list	*head;

	game->elements.enemy++;
	head = game->en_coord;
	tmp = (t_list *)malloc(sizeof(*tmp));
	if (!tmp)
		system_error("Memory allocation error");
	tmp->x_pos = tmp_width;
	tmp->y_pos = tmp_height;
	tmp->next = head;
	game->en_coord = tmp;

}
