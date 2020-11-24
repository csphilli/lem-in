// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ants_marching.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2020/10/31 13:23:00 by cphillip          #+#    #+#             */
// /*   Updated: 2020/11/23 11:47:39 by cphillip         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/lem_in.h"

// void	r2r(t_lol *path, t_ants *ins)
// {
// 	t_bucket	*tmp;

// 	tmp = path->list;
// 	tmp = tmp->next;
// 	while (tmp)
// 	{
// 		if (tmp->next && tmp->next->entry->occ && \
// 			!ft_strequ(tmp->next->entry->name, ins->start->name))
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
// 	// ft_printf("path nbr ants: %d\n", path->nbr_ants);
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
// 	// ft_printf("beginning with %s\n", tmp->list->entry->name);
// 	while (tmp)
// 	{
// 		if (tmp->ants_left > 0)
// 		{
// 			r2e(tmp, ins);
// 			// ft_printf("1\n");
// 			r2r(tmp, ins);
// 			// ft_printf("2\n");
// 			if (tmp->nbr_ants > 0)
// 			{
// 				s2r(tmp, ins);
// 				// ft_printf("3\n");
// 			}
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
// 	// ft_printf("starting: %s | ending: %s\n", bfs->start->name, bfs->end->name);
// 	// ft_printf("Ins start: %s | ins end: %s\n", ins->start->name, ins->end->name);
// 	// print_distro(&bfs->paths);
// 	// print_lol(&bfs->paths);
// 	while (1)
// 	{
// 		ants_marching_parse(bfs, ins);
// 		// ft_printf(RED"TESTING\n"RESET);
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
// 		// if (ins->i == 40)
// 		// {
// 		// 	while (1)
// 		// 	{
				
// 		// 	}
// 		// }
// 		if (ins->ants_e == ins->max_ant)
// 			break ;
// 		ins->i++;
// 	}
// 	while (1)
// 	{
		
// 	}
// 	ft_printf("Number of moves made: %d\n", ins->n_moves);
// }
