/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 14:51:07 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/31 15:20:36 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_moves(t_distro *moves)
{
	t_distro	*tmp;
	int		i;

	tmp = moves;
	i = 0;
	if (tmp)
	{
		while (tmp)
		{
			tmp->index = i;
			tmp->len = list_length(tmp->list);
			tmp->cap = tmp->len - 1;
			tmp = tmp->next;
			i++;
		}
	}
}

void	init_caps(t_bucket **ht)
{
	t_bucket	*tmp;
	t_bucket	*links;
	size_t		i;

	i = 0;
	tmp = NULL;
	links = NULL;
	while (i < TABLE_SIZE)
	{
		if (ht[i])
		{
			tmp = ht[i];
			while (tmp)
			{
				links = tmp->entry->links;
				while (links)
				{
					links->cap = 1;
					links->edge_flow = 0;
					links = links->next;
				}
				tmp = tmp->next;
			}
		}
		i++;
	}
}
// Needed?


