/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_direct_link.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:55:58 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/24 20:04:16 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		chk_direct_link(t_bucket **ht, t_master *master, t_bfs *bfs, int i)
{
	t_bucket	*links;
	t_entry		*entry;

	entry = (i == 1 ? bfs->end : bfs->start);
	links = (i == 1 ? bfs->start->links : bfs->end->links);
	while (links)
	{
		if (ft_strequ(links->entry->name, entry->name))
			return (1);
		links = links->next;
	}
	return (0);
}
