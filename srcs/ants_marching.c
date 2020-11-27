/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_marching.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:23:00 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/27 10:22:24 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
**	What does ins->i do? It is used to assist with printing whitespaces.
**	Basically, if p is 1, a whitespace will be printed BEFORE the solution.
**	Why before? If the logic triggers a move to be printed, there is
**	gauranteed to be a whitespace preceeding it. The exception to the rule
**	is the very first move in a new instruction set.
*/

void	write_move(int id, char *name)
{
	write(1, "L", 1);
	ft_putnbr(id);
	write(1, "-", 1);
	write(1, name, ft_strlen(name));
}

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
			ins->i == 1 ? write(1, " ", 1) : 1;
			write_move(tmp->next->entry->ant_id, tmp->entry->name);
			// ft_printf("L%d-%s", tmp->next->entry->ant_id, tmp->entry->name);
			tmp->next->entry->occ = 0;
			tmp->entry->occ = 1;
			tmp->entry->ant_id = tmp->next->entry->ant_id;
			tmp->next->entry->ant_id = 0;
			ins->i = 1;
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
		ins->i == 1 ? write(1, " ", 1) : 1;
		write_move(tmp->next->entry->ant_id, tmp->entry->name);
		// ft_printf("L%d-%s", tmp->next->entry->ant_id, tmp->entry->name);
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
		ins->i == 1 ? write(1, " ", 1) : 1;
		bfs->s_distro[i]--;
		write_move(ins->ant_id, tmp->entry->name);
		// ft_printf("L%d-%s", ins->ant_id, tmp->entry->name);
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
			r2e(bfs, tmp, ins, i);
			r2r(bfs, tmp, ins, i);
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
		write(1, "\n", 1);
		tmp = bfs->paths;
		ins->i = 0;
	}
}
