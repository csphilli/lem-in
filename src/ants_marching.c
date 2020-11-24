/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_marching.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:23:00 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/24 12:58:17 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	r2r(t_bfs *bfs, t_lol *path, t_ants *ins, int i)
{
	t_bucket	*tmp;

	tmp = path->list;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->next && tmp->next->entry->occ && !tmp->entry->occ &&\
		!ft_strequ(tmp->next->entry->name, ins->start->name))
		{
			ft_printf("L%d-%s ", tmp->next->entry->ant_id, tmp->entry->name);
			tmp->next->entry->occ = 0;
			tmp->entry->occ = 1;
			tmp->entry->ant_id = tmp->next->entry->ant_id;
			tmp->next->entry->ant_id = 0;
		}
		tmp = tmp->next;
	}
}

void	r2e(t_bfs *bfs, t_lol *path, t_ants *ins, int i)
{
	t_bucket	*tmp;

	tmp = path->list;
	if (tmp->next->entry->occ)
	{
		ft_printf("L%d-%s ", tmp->next->entry->ant_id, tmp->entry->name);
		tmp->next->entry->ant_id = 0;
		tmp->next->entry->occ = 0;
		ins->ants_e++;
		// ft_printf("|   %d   |", ins->ants_e);
		// bfs->moves[i]--; // added the [i]
	}
}

void	s2r(t_bfs *bfs, t_lol *path, t_ants *ins, int i)
{	
	t_bucket	*tmp;

	tmp = path->list;
	while (!ft_strequ(tmp->next->entry->name, ins->start->name))
		tmp = tmp->next;
	if (!tmp->entry->occ)
	{
		bfs->s_distro[i]--;
		ft_printf("L%d-%s ", ins->ant_id, tmp->entry->name);
		tmp->entry->ant_id = ins->ant_id;
		tmp->entry->occ = 1;
		ins->ant_id++;
	}
}

void	init_ant_ins(t_bfs *bfs, t_master *master, t_ants **ins)
{
	(*ins)->ants_s = master->nbr_ants;
	(*ins)->max_ant = (*ins)->ants_s;
	(*ins)->start = bfs->start;
	(*ins)->end = bfs->end;
	(*ins)->ant_id = 1;
}

void	ants_marching(t_bfs *bfs, t_master *master)
{
	t_ants 	*ins;
	t_lol	*tmp;
	int		i;
	int		len;
	int		trigger;

	ins = ft_memalloc(sizeof(t_ants));
	i = 0;
	trigger = 0;
	tmp = bfs->paths;
	init_ant_ins(bfs, master, &ins);
	len = ft_int_arr_len(bfs->moves);
	while (ins->ants_e != ins->max_ant)
	{
		while (i < len)
		{
			if (bfs->moves[i] > 0)
			{
				// ft_printf("BEFORE: ");
				// print_int_arr(bfs->moves);
				// ft_printf("  [%d]:   ", i);
				r2e(bfs, tmp, ins, i);

				r2r(bfs, tmp, ins, i);
				// ft_printf("AND LEFT: ");
				// print_int_arr(bfs->s_distro);
				if (bfs->s_distro[i] > 0)
					s2r(bfs, tmp, ins, i);
				bfs->moves[i]--;
				// write(1, "\n", 1);
			}
			i++;
			tmp = tmp->next;
		}
		
		// ft_printf("ins->ants: %d\n", ins->ants_e);
		ins->n_moves++;
		write(1, "\n", 1);
		i = 0;
		tmp = bfs->paths;
	}
	ft_printf("Ants end: %d | Ants start: %d\n", ins->ants_e, ins->max_ant);
	ft_printf("Nbr of moves made: %d\n", ins->n_moves);
}
