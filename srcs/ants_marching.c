/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_marching.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:23:00 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/03 19:51:37 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
**	What does ins->i do? It is used to assist with printing whitespaces.
**	Basically, if i == 1, a whitespace will be printed BEFORE the solution.
**	Why before? If the logic triggers a move to be printed, there is
**	gauranteed to be a whitespace preceeding it. The exception to the rule
**	is the very first move in a new instruction set.
*/

void	r2r(t_lol *path, t_ants *ins)
{
	t_bucket	*tmp;

	tmp = path->list;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->next && tmp->next->entry->occ && !tmp->entry->occ &&\
		!ft_strequ(tmp->next->entry->name, ins->start->name))
		{
			cat_move(ins, tmp->next->entry->ant_id, tmp->entry->name);
			tmp->next->entry->occ = 0;
			tmp->entry->occ = 1;
			tmp->entry->ant_id = tmp->next->entry->ant_id;
			tmp->next->entry->ant_id = 0;
			ins->i = 1;
		}
		tmp = tmp->next;
	}
}

void	r2e(t_lol *path, t_ants *ins)
{
	t_bucket	*tmp;

	tmp = path->list;
	if (tmp->next->entry->occ)
	{
		cat_move(ins, tmp->next->entry->ant_id, tmp->entry->name);
		tmp->next->entry->ant_id = 0;
		tmp->next->entry->occ = 0;
		ins->ants_e++;
		ins->i = 1;
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
		cat_move(ins, ins->ant_id, tmp->entry->name);
		tmp->entry->ant_id = ins->ant_id;
		tmp->entry->occ = 1;
		ins->ant_id++;
		ins->i = 1;
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
			r2e(tmp, ins);
			r2r(tmp, ins);
			if (bfs->s_distro[i] > 0)
			{
				s2r(bfs, tmp, ins, i);
				ins->i = 1;
			}
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
		ft_strcat(ins->input, "\n");
		ins->l += 1;
		tmp = bfs->paths;
		ins->i = 0;
	}
	if (ins->l < LINEBUF)
	{
		ft_strcat(ins->input, "\0");
		append_move(ins, &ins->output);
	}
	print_output(master->output);
	print_moves(ins->output);
	free_ins(ins);
}
