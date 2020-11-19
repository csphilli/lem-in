/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_distribution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:03:49 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/19 11:11:54 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		init_moves(t_lol *moves)
{
	t_lol *tmp;
	int		i;

	tmp = moves;
	i = 0;
	if (tmp)
	{
		while (tmp)
		{
			tmp->index = i;
			tmp->len = list_length(tmp->list);
			tmp->cap = tmp->len - 1;
			tmp = tmp->next;
			i++;
		}
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
	print_int_arr(arr);
	
	// while (1)
	// {
		
	// }
}
