/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_direct_link.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:55:58 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/21 14:32:42 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		chk_direct_link(t_bucket **ht, t_master *master, t_bfs *bfs)
{
	// t_entry 	*start;
	t_bucket	*links;

	links = bfs->end->links;
	while (links)
	{
		if (ft_strequ(links->entry->name, bfs->start->name))
			return (1);
		links = links->next;
	}
	return (0);
}