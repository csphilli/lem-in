/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:55:06 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/02 15:58:15 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_bfs	*crawl_graph(t_master *master, t_bfs *bfs)
{
	int 	len;
	t_entry *entry;

	entry = bfs->q->entry;
	len = link_array_len(entry->link_arr);
	entry->visited = true;
	bfs->bfs = append_to_list_no_dupe(bfs->bfs, entry);
	while (len--)
		if (entry->link_arr[len]->visited == false)
			bfs->q = append_to_list_no_dupe(bfs->q, entry->link_arr[len]);
	bfs->q = unshift_from_list(bfs->q);
	if (bfs->q)
		bfs = crawl_graph(master, bfs);
	return (bfs);
}

void	do_bfs(t_master *master, t_bucket **ht)
{
	t_bfs	*bfs;
	t_entry *entry;

	entry = get_entry(ht, master, master->end_room);
	entry = copy_entry(entry);
	if (!(bfs = (t_bfs*)malloc(sizeof(t_bfs))))
		exit_malloc();
	init_bfs(bfs);
	bfs->q = append_to_list_no_dupe(bfs->q, entry);
	bfs = crawl_graph(master, bfs);
}
