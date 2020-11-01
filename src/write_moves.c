/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 10:47:43 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/01 13:15:09 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	write_r2r(t_entry *entry1, t_entry *entry2)
{
	entry1->ant_id = entry2->ant_id;
	entry2->ant_id = 0;
	entry1->occ = 1;
	entry2->occ = 0;
	ft_printf("L%d-%s ", entry1->ant_id, entry1->name);
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
