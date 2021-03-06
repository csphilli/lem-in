/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_distribution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:03:49 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/02 14:50:06 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	calc_total_moves(t_master *master, t_distro *paths, int set_id)
{
	t_distro	*tmp;
	int			max;
	static int	min;

	max = 0;
	tmp = paths;
	while (tmp)
	{
		tmp->total_moves = tmp->nbr_ants + tmp->cap - 1;
		if (tmp->total_moves > max)
			max = tmp->total_moves;
		tmp->ants_left = tmp->nbr_ants;
		tmp = tmp->next;
	}
	if (max > 0)
	{
		if (min == 0)
			min = max;
		else if (max < min)
		{
			min = max;
			master->best_set = set_id;
		}
	}
}

void	chk_unlock(t_master **master, t_distro **tmp)
{
	if ((*tmp)->nbr_ants == (*tmp)->unlock && !(*tmp)->done)
	{
		(*master)->bfs->max_index++;
		(*tmp)->done = 1;
	}
}

void	cascade(t_master *master, t_distro *paths)
{
	t_distro	*tmp;
	int			ant_count;

	tmp = paths;
	ant_count = master->nbr_ants;
	while (tmp && ant_count > 0)
	{
		while (tmp->index <= master->bfs->max_index && ant_count > 0)
		{
			tmp->nbr_ants++;
			ant_count--;
			chk_unlock(&master, &tmp);
			tmp = (tmp->index == master->bfs->max_index ? paths : tmp->next);
		}
		tmp = paths;
	}
}

void	unlocks(t_master *master, t_distro *paths)
{
	t_distro	*tmp;

	tmp = paths;
	master->bfs->max_index = 0;
	while (tmp)
	{
		if (tmp->next)
			tmp->unlock = tmp->next->len - tmp->len + 1;
		else
			tmp->unlock = 2147483647;
		tmp = tmp->next;
	}
}

void	calc_distro(t_master *master)
{
	t_distro	*moves;
	int			*arr;
	int			i;

	arr = NULL;
	i = 0;
	moves = NULL;
	while (i < MAX_SETS)
	{
		moves = master->paths[i];
		init_moves(moves);
		unlocks(master, moves);
		cascade(master, moves);
		calc_total_moves(master, moves, i);
		i++;
	}
}
