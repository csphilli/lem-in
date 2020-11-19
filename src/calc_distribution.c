/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_distribution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:03:49 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/19 12:40:35 by cphillip         ###   ########.fr       */
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

	tmp = bfs->paths;
	while (tmp && master->nbr_ants > 0)
	{
		while (tmp->index <= bfs->max_index && master->nbr_ants > 0)
		{
			tmp->nbr_ants++;
			master->nbr_ants--;
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


void			calc_distribution(t_master *master, t_bfs *bfs)
{
	t_lol 	*moves;
	int		*arr;

	arr = NULL;
	moves = bfs->paths;
	init_moves(moves);
	unlocks(bfs);
	cascade(bfs, master);
	calc_total_moves(bfs->paths);
	print_int_arr(arr);
	
	// while (1)
	// {
		
	// }
}
