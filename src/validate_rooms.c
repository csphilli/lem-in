/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 10:17:02 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/25 10:08:28 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	scan_index(t_bucket *head, size_t index)
{
	t_bucket	*tmp;
	t_bucket	*test;

	tmp = head;
	while (tmp)
	{
		if (!tmp->next)
			break ;
		else
		{
			test = tmp;
			while (test->next)
			{
				test = test->next;
				if (ft_strequ(test->entry->name, tmp->entry->name))
					exit_dup(test->entry->name, index);
			}
		}
		tmp = tmp->next;
	}
}

void	validate_rooms(t_bucket **ht, t_master *master)
{
	size_t	i;

	i = 0;
	while (i < master->new_size)
	{
		if (ht[i])
			scan_index(ht[i], i);
		i++;
	}
	if (master->start_room == NULL || master->end_room == NULL)
		exit_no_solution();
}
