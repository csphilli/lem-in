/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_distribution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:03:49 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/21 14:37:21 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		calc_total_moves(t_lol *paths)
{
	t_lol *tmp;

	tmp = paths;
	while (tmp)
	{
		tmp->total_moves = tmp->nbr_ants +\
		(list_length(tmp->list) - 2);
		tmp->ants_left = tmp->nbr_ants;
		tmp = tmp->next;
	}
}

void		chk_unlock(t_bfs **bfs, t_lol **tmp)
{
	if ((*tmp)->nbr_ants == (*tmp)->unlock && !(*tmp)->done)
	{
		(*bfs)->max_index++;
		(*tmp)->done = 1;
	}
}

void	cascade(t_bfs *bfs, t_master *master)
{
	t_lol 	*tmp;
	int		ant_count;

	tmp = bfs->paths;
	ant_count = master->nbr_ants;
	while (tmp && ant_count > 0)
	{
		while (tmp->index <= bfs->max_index && ant_count > 0)
		{
			tmp->nbr_ants++;
			ant_count--;
			chk_unlock(&bfs, &tmp);
			if (master->vis_distro)
			{
				system("clear");
				print_distro(&bfs->paths);
				usleep(250000);
			}
			tmp = (tmp->index == bfs->max_index ? bfs->paths : tmp->next);
		}
		tmp = bfs->paths;
	}
}

void	unlocks(t_bfs *bfs)
{
	t_lol	*tmp;

	tmp = bfs->paths;
	while (tmp)
	{
		if (tmp->next)
			tmp->unlock = tmp->next->len - tmp->len + 1;
		else
			tmp->unlock = 1000000;
		tmp = tmp->next;
	}
}


void			calc_distro(t_bucket **ht, t_master *master, t_bfs *bfs)
{
	t_lol 	*moves;
	int		*arr;

	arr = NULL;
	moves = bfs->paths;
	init_moves(moves);
	if (!chk_direct_link(ht, master, bfs))
	{
		unlocks(bfs);
		cascade(bfs, master);
		calc_total_moves(bfs->paths);
	}
	else
		ft_error("Going to do one move soon.");
	// print_int_arr(arr);
	
	// while (1)
	// {
		
	// }
}
