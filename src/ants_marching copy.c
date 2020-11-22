// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ants_marching.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2020/10/31 13:23:00 by cphillip          #+#    #+#             */
// /*   Updated: 2020/11/21 14:39:28 by cphillip         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/lem_in.h"

// void	r2r(t_lol *path, t_ants *ins)
// {
// 	t_bucket	*tmp;

// 	tmp = path->list;
// 	while (tmp)
// 	{
// 		if (!ft_strequ(tmp->entry->name, ins->end->name) && \
// 			(tmp->next && tmp->next->entry->occ && \
// 			!ft_strequ(tmp->next->entry->name, ins->start->name)))
// 				write_r2r(ins, tmp->entry, tmp->next->entry);
// 		tmp = tmp->next;
// 	}
// }

// void	r2e(t_lol *path, t_ants *ins)
// {
// 	t_bucket	*tmp;

// 	tmp = path->list;
// 	if (tmp->next->entry->occ)
// 	{
// 		write_r2e(ins, tmp->entry, tmp->next->entry);
// 		path->ants_left--;
// 	}
// }

// void	s2r(t_lol *path, t_ants *ins)
// {
// 	t_bucket	*tmp;

// 	tmp = path->list;
// 	path->nbr_ants--;
// 	while (!ft_strequ(tmp->next->entry->name, ins->start->name))
// 		tmp = tmp->next;
// 	if (!tmp->entry->occ)
// 		write_s2r(ins, tmp->entry);
// }

// void	ants_marching_parse(t_bfs *bfs, t_ants *ins)
// {
// 	t_lol 	*tmp;

// 	tmp = bfs->paths;
// 	while (tmp)
// 	{
// 		if (tmp->ants_left > 0)
// 		{
// 			r2e(tmp, ins);
// 			r2r(tmp, ins);
// 			if (tmp->nbr_ants > 0)
// 				s2r(tmp, ins);
// 		}		
// 		tmp = tmp->next;
// 	}
// }

// void	init_ant_ins(t_bfs *bfs, t_master *master, t_ants **ins)
// {
// 	(*ins)->ants_s = master->nbr_ants;
// 	(*ins)->max_ant = (*ins)->ants_s;
// 	(*ins)->start = bfs->start;
// 	(*ins)->end = bfs->end;
// 	(*ins)->ant_id = 1;
// }


// void	ants_marching(t_bfs *bfs, t_master *master)
// {
// 	t_ants *ins;
// 	char	*tmp;

// 	ins = ft_memalloc(sizeof(t_ants));
// 	ins->i = 0;
// 	tmp = NULL;
// 	init_ant_ins(bfs, master, &ins);
// 	while (1)
// 	{
// 		ants_marching_parse(bfs, ins);
// 		tmp = ft_strnew(ft_strlen(ins->output) - 1);
// 		ft_strncat(tmp, ins->output, ft_strlen(ins->output) - 1);
// 		ft_strdel(&ins->output);
// 		ins->output = NULL;
// 		ft_printf("%s\n", tmp);
// 		ft_strdel(&tmp);

// 		// free(tmp);
// 		tmp = NULL;
// 		// ft_strdel(&ins->output);
// 		ins->n_moves++;
// 		if (ins->ants_e == ins->max_ant)
// 			break ;
// 		ins->i++;
// 	}
// 	// while (1)
// 	// {
		
// 	// }
// 	ft_printf("Number of moves made: %d\n", ins->n_moves);
// }
