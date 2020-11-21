/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:30:32 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/21 14:30:49 by cphillip         ###   ########.fr       */
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
			test = tmp->next;
			while (test->next)
			{
				if (ft_strequ(test->entry->name, tmp->entry->name))
					exit_dup(test->entry->name, index);
				test = test->next;
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
}
