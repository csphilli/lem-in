/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:55:06 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/15 18:38:40 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	set_visited(t_bucket **paths, int visited)
{
	t_bucket	*tmp;

	tmp = *paths;
	while (tmp)
	{
		tmp->entry->visited = visited;
		tmp = tmp->next;
	}
}

// void	set_visited(t_bucket **ht, t_master *master, t_bucket *head, int toggle)
// {
// 	t_bucket 	*tmp;
// 	t_entry		*entry;

// 	tmp = head;
// 	entry = NULL;
// 	while (tmp)
// 	{
// 		entry = get_entry(ht, master, tmp->entry->name);
// 		entry->visited = (toggle == 1 ? 1 : 0);
// 		tmp = tmp->next;
// 	}
// }

// void	visited_count(t_bucket *head)
// {
// 	t_bucket *tmp;
// 	int		count;

// 	count = 0;
// 	tmp = head;
// 	while (tmp->next)
// 	{
// 		if (tmp->entry->visited)
// 			count++;
// 		tmp = tmp->next;
// 	}
// 	ft_printf("visited count: %d\n", count);
// }





// void	crawl_graph(t_bucket **bfsq, t_bucket **paths)
// {
// 	t_bucket	*links;

// 	(*bfsq)->entry->visited = 1;
// 	if (!dupe(paths, (*bfsq)->entry))
// 		append_to_ll(paths, (*bfsq)->entry);
// 	links = (*bfsq)->entry->links;
// 	while (links)
// 	{
// 		if (!links->entry->visited)
// 			append_to_ll(bfsq, links->entry);
// 		links = links->next;
// 	}
// 	pop_from_ll(bfsq);
// 	if (*bfsq)
// 		crawl_graph(bfsq, paths);
// }

void	crawl_graph(t_bucket **bfsq, t_bucket **paths, t_entry *goal)
{
	t_bucket	*links;
	int			chk;

	chk = 0;
	(*bfsq)->entry->visited = 1;
	if (!dupe(paths, (*bfsq)->entry))
		append_to_ll(paths, (*bfsq)->entry);
	if (ft_strequ((*bfsq)->entry->name, goal->name))
		chk = 1;
	links = (*bfsq)->entry->links;
	while (links)
	{
		if (!links->entry->visited)
			append_to_ll(bfsq, links->entry);
		links = links->next;
	}
	pop_from_ll(bfsq);
	if (chk == 1)
		while (*bfsq)
			pop_from_ll(bfsq);
	if (*bfsq)
		crawl_graph(bfsq, paths, goal);
}

void	do_bfs(t_master *master, t_bucket **ht)
{
	t_entry 	*end;
	t_entry		*start;
	t_bucket	*bfsq;
	t_bucket	*bfs;

	bfsq = NULL;
	bfs = NULL;
	start = get_entry(ht, master, master->start_room);
	end = get_entry(ht, master, master->end_room);
	append_to_ll(&bfsq, start);
	crawl_graph(&bfsq, &bfs, end);
	set_visited(&bfs, 0);
	weed_eating1(&bfs);
	weed_eating2(&bfs);
	// print_ll(paths);
	check_path_exists(start, end, bfs);
	// ft_printf("Room Count: %d\n", master->room_count);
	build_paths(&bfs, start, end);
	// while (1)
	// {
		
	// }
}
