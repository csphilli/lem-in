/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_distribution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:03:49 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/22 11:24:07 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	calc_total_moves(t_lol *paths)
{
	t_lol *tmp;

	tmp = paths;
	while (tmp)
	{
		tmp->total_moves = tmp->nbr_ants + tmp->cap - 1;
		tmp->ants_left = tmp->nbr_ants;
		tmp = tmp->next;
	}
}

void	chk_unlock(t_master **master, t_lol **tmp)
{
	if ((*tmp)->nbr_ants == (*tmp)->unlock && !(*tmp)->done)
	{
		(*master)->bfs->max_index++;
		(*tmp)->done = 1;
	}
}

void	cascade(t_master *master, t_lol *paths)
{
	t_lol	*tmp;
	int		ant_count;

	tmp = paths;
	ant_count = master->nbr_ants;
	while (tmp && ant_count > 0)
	{
		while (tmp->index <= master->bfs->max_index && ant_count > 0)
		{
			tmp->nbr_ants++;
			ant_count--;
			chk_unlock(&master, &tmp);
			if (master->flags.vis_distro)
			{
				system("clear");
				print_distro(&paths);
				calc_total_moves(paths);
				usleep(100000);
			}
			tmp = (tmp->index == master->bfs->max_index ? paths : tmp->next);
		}
		tmp = paths;
	}
}

void	unlocks(t_master *master, t_lol *paths)
{
	t_lol	*tmp;

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
	t_lol	*moves;
	int		*arr;
	int		i;

	arr = NULL;
	i = 0;
	moves = NULL;
	while (i < 2)
	{
		moves = (i == 1 ? master->bfs->s2e : master->bfs->e2s);
		init_moves(moves);
		unlocks(master, moves);
		cascade(master, moves);
		calc_total_moves(moves);
		i++;
	}
}
