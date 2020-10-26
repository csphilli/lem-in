/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_coords.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 12:57:50 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/25 09:51:28 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	validate_coords(t_master *master, char *n1, char *n2)
{
	int i;

	i = 0;
	while (n1[i])
	{
		if (!ft_isdigit(n1[i]))
			exit_coord(master->line_nbr);
		i++;
	}
	i = 0;
	while (n2[i])
	{
		if (!ft_isdigit(n2[i]))
			exit_coord(master->line_nbr);
		i++;
	}
}

int		dup_coord(t_bucket **ht, t_master *master, t_entry *entry)
{
	size_t		i;
	t_bucket	*tmp;

	i = 0;
	tmp = NULL;
	while (i < master->new_size)
	{
		if (ht[i])
		{
			tmp = ht[i];
			while (tmp)
			{
				if (tmp->entry->x == entry->x && tmp->entry->y == entry->y)
					return (1);
				tmp = tmp->next;
			}
		}
		i++;
	}
	return (0);
}
