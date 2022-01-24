/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:54:56 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/24 22:58:11 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_list_free(t_game *game)
{
	t_list	*lst;
	t_list	*tmp;

	lst = game->en_coord;

	while (lst != NULL)
	{
		if (lst->next)
			tmp = lst->next;
		else
			tmp = NULL;
		free(lst);
		if (!tmp)
			break ;
		else
			lst = tmp;
	}
	game->en_coord = NULL;
}


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
	tmp->orient = 1;
	tmp->next = head;
	game->en_coord = tmp;

}

int	enemy_step_conditions(t_game *game, int y_pos, int x_pos, t_list	*lst)
{
	char	*cur_pos;
	char	*step_pos;

	cur_pos = &game->map[y_pos][x_pos];
	step_pos = &game->map[y_pos][x_pos + 1];
	if (lst->orient == 1)
		step_pos = &game->map[y_pos][x_pos + 1];
	if (lst->orient == -1)
		step_pos = &game->map[y_pos][x_pos - 1];

	if (*step_pos == WALL_EL || *step_pos == EXIT_EL \
	|| *step_pos == COIN_EL || *step_pos == ENEMY_EL)
	{
		lst->orient *= -1;
		return (0);
	}
	if (*step_pos == PLAYER_EL)
	{
		game->died = 1;
		game->the_end = 1;
		return (0);
	}
	return (1);
}

void	enemy_steps(t_game *game, int y_pos, int x_pos, t_list	*lst)
{
	char	*cur_pos;
	char	*step_pos;

	cur_pos = &game->map[y_pos][x_pos];
	if (lst->orient == 1)
		step_pos = &game->map[y_pos][x_pos + 1];
	if (lst->orient == -1)
		step_pos = &game->map[y_pos][x_pos - 1];
	if (game->passed == 0)
	{
		*cur_pos = EMPTY_EL;
		*step_pos = ENEMY_EL;
		game->map[y_pos][x_pos] = *cur_pos;

		if (lst->orient == 1)
			lst->x_pos = x_pos + 1;
		if (lst->orient == -1)
			lst->x_pos = x_pos - 1;
		lst->y_pos = y_pos;
	}
	else if (game->passed == 1 || game->died == 1)
	{
		game->skelet.wait = 0;
	}
}

void	enemy_move(t_game *game)
{
	t_list	*lst;

	if (game->anim_count == game->skelet.wait)
	{
		lst = game->en_coord;
		while (lst != NULL)
		{
			if (lst->x_pos != 0 || lst->y_pos != 0)
			{
				if (enemy_step_conditions(game, lst->y_pos, lst->x_pos, lst))
					enemy_steps(game, lst->y_pos, lst->x_pos, lst);
				lst = lst -> next;
			}
			else
				break ;
		}
		game->skelet.wait++;
	}
}
