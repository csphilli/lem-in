/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:55:06 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/12 15:10:12 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

// void	set_visited(t_bucket *head, int toggle)
// {
// 	t_bucket *tmp;

// 	tmp = head;
// 	while (tmp)
// 	{
// 		tmp->entry->visited = (toggle == 1 ? true : false);
// 		tmp = tmp->next;
// 	}
// }

void	set_visited(t_bucket **ht, t_master *master, t_bucket *head, int toggle)
{
	t_bucket 	*tmp;
	t_entry		*entry;

	tmp = head;
	entry = NULL;
	while (tmp)
	{
		entry = get_entry(ht, master, tmp->entry->name);
		entry->visited = (toggle == 1 ? true : false);
		tmp = tmp->next;
	}
}

void	visited_count(t_bucket *head)
{
	t_bucket *tmp;
	int		count;

	count = 0;
	tmp = head;
	while (tmp->next)
	{
		if (tmp->entry->visited)
			count++;
		tmp = tmp->next;
	}
	ft_printf("visited count: %d\n", count);
}

void	set_blocks(t_bucket *head, t_entry *start)
{
	t_bucket	*tmp;

	tmp = head;
	if (tmp->next)
	{
		while (tmp->next)
		{
			if (ft_strequ(start->name, tmp->entry->name))
				break ;
			tmp = tmp->next;
		}
	}
	if (tmp->next)
	{
		tmp = tmp->next;
		while (tmp->next)
		{
			tmp->entry->no = true;
			tmp = tmp->next;
		}
	}
}

void	weed_eating(t_bucket **ht, t_master *master)
{
	bool	chk;

	chk = false;
	while (!chk)
	{
		chk = true;

	}
}

void	crawl_graph(t_master *master, t_bucket **ht, t_bfs *bfs)
{
	int 	len;
	t_entry *entry;

	entry = get_entry(ht, master, bfs->bfsq->entry->name);
	entry->visited = true;
	len = link_array_len(entry->link_arr);
	append_to_bfs(bfs, bfs->bfsq->entry);
	while (len--)
	{
		entry = get_entry(ht, master, bfs->bfsq->entry->link_arr[len]->name);
		if (!entry->visited)
			append_to_bfsq(bfs, entry);
		entry = NULL;
	}
	pop_bfsq(bfs);
	if (bfs->bfsq)
		crawl_graph(master, ht, bfs);
}

void	do_bfs(t_master *master, t_bucket **ht)
{
	t_bfs	*bfs;
	t_entry *end;
	t_entry	*start;

	start = get_entry(ht, master, master->start_room);
	end = get_entry(ht, master, master->end_room);
	if (!(bfs = ft_memalloc(sizeof(t_bfs))))
		exit_malloc();
	bfs->end = get_entry(ht, master, end->name);
	bfs->start = get_entry(ht, master, start->name);
	append_to_bfsq(bfs, end);
	crawl_graph(master, ht, bfs);
	check_path_exists(start, end, bfs);
	set_visited(ht, master, bfs->bfs, 0);
	visited_count(bfs->bfs);
	set_blocks(bfs->bfs, bfs->end);
	visited_count(bfs->bfs);
	print_path(bfs->bfs);
	ft_printf("Room Count: %d\n", master->room_count);
	// build_paths(ht, master, bfs);
	while (1)
	{
		
	}
}