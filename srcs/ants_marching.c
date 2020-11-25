/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_marching.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:23:00 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/25 15:58:36 by cphillip         ###   ########.fr       */
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
			ft_printf("L%d-%s", tmp->next->entry->ant_id, tmp->entry->name);
			tmp->next->entry->occ = 0;
			tmp->entry->occ = 1;
			tmp->entry->ant_id = tmp->next->entry->ant_id;
			tmp->next->entry->ant_id = 0;
			if (bfs->moves[i + 1] != '\0' && (bfs->moves[i] > 0 && bfs->moves[i + 1] > 0))
				write(1, " ", 1);
			

			// if (bfs->moves[i] > 0 && (bfs->moves[i + 1] != '\0' || bfs->moves[0] > 0))
			// 	write(1, " ", 1);

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
		ft_printf("L%d-%s", tmp->next->entry->ant_id, tmp->entry->name);
		tmp->next->entry->ant_id = 0;
		tmp->next->entry->occ = 0;
		ins->ants_e++;
		if (bfs->moves[i] > 0 && (bfs->moves[i + 1] != '\0' || bfs->moves[0] > 0))
			write(1, " ", 1);
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
		ft_printf("L%d-%s", ins->ant_id, tmp->entry->name);
		tmp->entry->ant_id = ins->ant_id;
		tmp->entry->occ = 1;
		ins->ant_id++;
		if (bfs->moves[i + 1] && bfs->moves[i + 1] > 0)
			write(1, " ", 1);
	}
}

void	moves_parsing(t_bfs *bfs, t_lol *lol, t_ants *ins, int len)
{
	t_lol	*tmp;
	int		i;

	tmp = lol;
	i = 0;
	while (i < len)
	{
		if (bfs->moves[i] > 0)
		{
			r2e(bfs, tmp, ins, i);
			r2r(bfs, tmp, ins, i);
			if (bfs->s_distro[i] > 0)
				s2r(bfs, tmp, ins, i);
			bfs->moves[i]--;
		}
		i++;
		tmp = tmp->next;
	}
}

void	ants_marching(t_bfs *bfs, t_master *master)
{
	t_ants	*ins;
	t_lol	*tmp;
	int		len;

	ins = ft_memalloc(sizeof(t_ants));
	tmp = bfs->paths;
	init_ant_ins(bfs, master, &ins);
	len = ft_int_arr_len(bfs->moves);
	while (ins->ants_e != ins->max_ant)
	{
		moves_parsing(bfs, tmp, ins, len);
		ins->n_moves++;
		write(1, "\n", 1);
		tmp = bfs->paths;
	}
	ft_printf("Nbr of moves made: %d\n", ins->n_moves);
}
