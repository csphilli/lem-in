/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_marching.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:23:00 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/31 16:55:03 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		most_ants(int *arr)
{
	int max;
	int i;

	i = 0;
	max = 0;
	while (arr[i])
	{
		if (arr[i] >= max)
			max = arr[i];
		i++;
	}
	return (max);
}

void	write_r2r(t_entry *entry1, t_entry *entry2)
{
	entry1->ant_id = entry2->ant_id;
	entry2->ant_id = 0;
	entry1->occ = 1;
	entry2->occ = 0;
	ft_printf("L%d-%s", entry1->ant_id, entry1->name);
}

void	write_r2e(t_paths *paths, t_entry *entry1, t_entry *entry2)
{
	ft_printf("L%d-%s", entry2->ant_id, entry1->name);
	entry2->ant_id = 0;
	entry2->occ = 0;
	paths->nbr_ants_e++;
}

void	write_s2r(t_paths *paths, t_entry *entry1)
{
	ft_printf("L%d-%s", paths->ant_id, entry1->name);
	entry1->ant_id = paths->ant_id;
	entry1->occ = 1;
	paths->ant_id++;
	paths->nbr_ants_s--;
}

void	r2r(t_paths *paths, t_ant_instrux *ins)
{
	t_bucket *tmp;
	int i;
	// int len;

	i = 0;
	// len = ft_int_arr_len(ins->ant_arr);
	tmp = NULL;
	while (i <= ins->max_index)
	{
		tmp = paths->c[i];
		while (tmp)
		{
			if (tmp->next && ft_strequ(tmp->next->entry->name, \
				paths->s_room->name))
				break ;
			else if (tmp->next && (!ft_strequ(tmp->entry->name,\
					paths->e_room->name) && tmp->next->entry->occ))
				write_r2r(tmp->entry, tmp->next->entry);
			tmp = tmp->next;
		}
		i++;
	}
}

void	r2e(t_paths *paths, t_ant_instrux *ins)
{
	t_bucket	*tmp;
	int 		i;
	// int			len;

	i = 0;
	// len = ft_int_arr_len(ins->ant_arr);
	// ft_printf("int array len: %d\n", len);
	tmp = NULL;
	while (i <= ins->max_index)
	{
		tmp = paths->c[i];
		if (tmp->next->entry->occ)
			write_r2e(paths, tmp->entry, tmp->next->entry);
		i++;
	}
}

void	s2r(t_paths *paths, t_ant_instrux *ins)
{
	t_bucket	*tmp;
	int			i;
	// int			len;

	tmp = NULL;
	i = 0;
	// len = ft_int_arr_len(ins->ant_arr);
	// ft_printf("max_index: %d\n", ins->max_index);
	while (i <= ins->max_index)
	{
		if (ins->ant_arr[i] > 0)
		{
			tmp = paths->c[i];
			while (!ft_strequ(tmp->next->entry->name, paths->s_room->name))
				tmp = tmp->next;
			write_s2r(paths, tmp->entry);
			ins->ant_arr[i]--;
		}
		i++;
	}
}

void	ants_marching(t_paths *paths, t_ant_instrux *ins)
{
	int rounds;
	int	i;

	rounds = most_ants(ins->ant_arr);
	paths->max_id = paths->nbr_ants_s;
	i = 0;
	while (i < rounds)
	{
		r2e(paths, ins);
		r2r(paths, ins);
		s2r(paths, ins);
		ft_printf("\n");
		paths->nbr_moves++;
		i++;
	}
	while (1)
	{
		r2e(paths, ins);
		if (paths->nbr_ants_e == paths->max_id)
		{
			paths->nbr_moves++;
			break ;
		}
		r2r(paths, ins);
		paths->nbr_moves++;
		ft_printf("\n");
	}
	ft_printf("\nnbr moves: %d\n", paths->nbr_moves);
}