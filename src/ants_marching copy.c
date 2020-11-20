// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ants_marching.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2020/10/31 13:23:00 by cphillip          #+#    #+#             */
// /*   Updated: 2020/11/17 12:54:38 by cphillip         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/lem_in.h"

// void	r2r(t_paths *paths, t_ants *ins)
// {
// 	t_bucket	*tmp;
// 	int			i;

// 	i = 0;
// 	tmp = NULL;
// 	while (i <= ins->max_index)
// 	{
// 		tmp = paths->c[i];
// 		while (tmp)
// 		{
// 			if (tmp->next && ft_strequ(tmp->next->entry->name, \
// 				paths->s_room->name))
// 				break ;
// 			else if (tmp->next && (!ft_strequ(tmp->entry->name,\
// 					paths->e_room->name) && tmp->next->entry->occ))
// 				write_r2r(tmp->entry, tmp->next->entry);
// 			tmp = tmp->next;
// 		}
// 		i++;
// 	}
// }

// void	r2e(t_paths *paths, t_ants *ins)
// {
// 	t_bucket	*tmp;
// 	int			i;

// 	i = 0;
// 	tmp = NULL;
// 	while (i <= ins->max_index)
// 	{
// 		tmp = paths->c[i];
// 		if (tmp->next->entry->occ)
// 		{
// 			write_r2e(paths, tmp->entry, tmp->next->entry);
// 			if (paths->nbr_ants_e < paths->max_id)
// 				write(1, " ", 1);
// 		}
// 		i++;
// 	}
// }

// void	s2r(t_paths *paths, t_ants *ins)
// {
// 	t_bucket	*tmp;
// 	int			i;

// 	tmp = NULL;
// 	i = 0;
// 	while (i <= ins->max_index)
// 	{
// 		if (ins->ant_arr[i] > 0)
// 		{
// 			tmp = paths->c[i];
// 			while (!ft_strequ(tmp->next->entry->name, paths->s_room->name))
// 				tmp = tmp->next;
// 			write_s2r(paths, tmp->entry);
// 			ins->ant_arr[i]--;
// 			if (i != ins->max_index && ins->ant_arr[i + 1] > 0)
// 				write(1, " ", 1);
// 		}
// 		i++;
// 	}
// }

// void	ants_marching_parse(t_paths *paths, t_ants *ins)
// {
// 	r2e(paths, ins);
// 	r2r(paths, ins);
// 	s2r(paths, ins);
// 	ft_printf("\n");
// 	// paths->nbr_moves++;
// }

// void	ants_marching(t_paths *paths, t_ants *ins)
// {
// 	int rounds;
// 	int	i;

// 	rounds = most_ants(ins->ant_arr);
// 	paths->max_id = paths->nbr_ants_s;
// 	i = 0;
// 	while (i < rounds)
// 	{
// 		ants_marching_parse(paths, ins);
// 		paths->nbr_moves++;
// 		i++;
// 	}
// 	while (1)
// 	{
// 		r2e(paths, ins);
// 		if (paths->nbr_ants_e == paths->max_id)
// 		{
// 			paths->nbr_moves++;
// 			break ;
// 		}
// 		r2r(paths, ins);
// 		paths->nbr_moves++;
// 		ft_printf("\n");
// 	}
// 	ft_printf("\nNumber of moves made: %d\n", paths->nbr_moves);
// }
