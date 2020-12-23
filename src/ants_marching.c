/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_marching.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:23:00 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/22 15:35:04 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	r2r(t_master *master, t_lol *path)
{
	t_bucket	*tmp;

	tmp = path->list;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->next && tmp->next->entry->occ && !tmp->entry->occ &&\
		!ft_strequ(tmp->next->entry->name, master->start_room->name))
		{
			cat_move(master, tmp->next->entry->ant_id, tmp->entry->name);
			tmp->next->entry->occ = 0;
			tmp->entry->occ = 1;
			tmp->entry->ant_id = tmp->next->entry->ant_id;
			tmp->next->entry->ant_id = 0;
			master->ants->i = 1;
		}
		tmp = tmp->next;
	}
}

void	r2e(t_master *master, t_lol *path)
{
	t_bucket	*tmp;

	tmp = path->list;
	if (tmp->next->entry->occ)
	{
		cat_move(master, tmp->next->entry->ant_id, tmp->entry->name);
		tmp->next->entry->ant_id = 0;
		tmp->next->entry->occ = 0;
		master->ants->ants_e++;
		master->ants->i = 1;
	}
}

void	s2r(t_master *master, t_lol *path, int i)
{
	t_bucket	*tmp;

	tmp = path->list;
	while (!ft_strequ(tmp->next->entry->name, master->start_room->name))
		tmp = tmp->next;
	if (!tmp->entry->occ)
	{
		master->bfs->s_distro[i]--;
		cat_move(master, master->ants->ant_id, tmp->entry->name);
		tmp->entry->ant_id = master->ants->ant_id;
		tmp->entry->occ = 1;
		master->ants->ant_id++;
		master->ants->i = 1;
	}
}

void	moves_parsing(t_master *master, t_lol *lol, int len)
{
	t_lol	*tmp;
	int		i;

	tmp = lol;
	i = 0;
	while (i < len)
	{
		if (master->bfs->moves[i] > 0)
		{
			r2e(master, tmp);
			r2r(master, tmp);
			if (master->bfs->s_distro[i] > 0)
			{
				s2r(master, tmp, i);
				master->ants->i = 1;
			}
			master->bfs->moves[i]--;
		}
		i++;
		tmp = tmp->next;
	}
}

void	ants_marching(t_master *master)
{
	t_lol	*tmp;
	int		len;

	tmp = master->bfs->paths;
	len = ft_int_arr_len(master->bfs->moves);
	while (master->ants->ants_e != master->nbr_ants)
	{
		moves_parsing(master, tmp, len);
		master->ants->n_moves++;
		ft_strcat(master->moves->buf, "\n");
		master->moves->b_len += 1;
		tmp = master->bfs->paths;
		master->ants->i = 0;
	}
	if (master->moves->b_len < IO_BUF)
	{
		ft_strcat(master->moves->buf, "\0");
		buf_to_output(&master->moves);
	}
	// print_io(master->map, 1);
	print_io(master->moves, 0);
	free(master->ants);
}
