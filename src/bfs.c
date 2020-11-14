/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:55:06 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/14 13:54:16 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	set_paths(t_bucket **paths, int visited)
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


int		count_vis(t_bucket **links)
{
	t_bucket	*tmp;
	int			count;

	tmp = *links;
	count = 0;
	while (tmp)
	{
		if (tmp->entry->visited)
			count++;
		tmp = tmp->next;
	}
	return (count);
}



int		same_links(t_bucket **ll1, t_bucket **ll2)
{
	t_bucket	*tmp1;
	t_bucket	*tmp2;

	tmp1 = *ll1;
	tmp2 = *ll2;
	while ((tmp1 && tmp2) && \
			ft_strequ(tmp1->entry->name, tmp2->entry->name))
	{
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	if (!tmp1 && !tmp2)
		return (1);
	return (0);
}

void	que_visited(t_bucket **que, t_bucket **paths)
{
	t_bucket *tmp;

	tmp = *paths;
	while (tmp)
	{
		if (tmp->entry->visited)
			append_to_ll(que, tmp->entry);
		tmp = tmp->next;
	}
}

void	weed_eating2(t_bucket **paths)
{
	t_bucket	*tmp;
	t_bucket	*que;

	tmp = NULL;
	que = NULL;
	que_visited(&que, paths);
	while (que)
	{
		tmp = que->entry->links;
		while (tmp)
		{
			if (list_length(tmp->entry->links) - \
				count_vis(&tmp->entry->links) == 1)
			{
				append_to_ll(&que, tmp->entry);
				tmp->entry->visited = 1;
			}
			tmp = tmp->next;
		}
		pop_from_ll(&que);		
	}
}

void	weed_eating1(t_bucket **paths)
{
	t_bucket 	*tmp;
	t_bucket	*cur;
	t_bucket	*head;

	head = *paths;
	cur = head;
	while (cur)
	{
		tmp = cur->next;
		list_length(cur->entry->links) == 1 ? cur->entry->visited = 1 : 1;
		while (tmp)
		{
			if (same_links(&cur->entry->links, &tmp->entry->links))
				cur->entry->visited = 1;
			tmp = tmp->next;
		}
		cur = cur->next;
	}
	*paths = head;
}


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
	t_bucket	*paths;

	bfsq = NULL;
	paths = NULL;
	start = get_entry(ht, master, master->start_room);
	end = get_entry(ht, master, master->end_room);
	append_to_ll(&bfsq, start);
	crawl_graph(&bfsq, &paths, end);
	set_paths(&paths, 0);
	weed_eating1(&paths);
	weed_eating2(&paths);
	print_ll(paths);
	check_path_exists(start, end, paths);
	ft_printf("Room Count: %d\n", master->room_count);
	// build_paths(ht, master, bfs);
	// while (1)
	// {
		
	// }
}
