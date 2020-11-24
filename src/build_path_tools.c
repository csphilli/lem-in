/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_path_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:29:55 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/24 12:00:50 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	reset_data(t_bucket **ht, t_master *master, int x)
{
	t_bucket	*tmp;
	size_t		i;

	i = 0;
	tmp = NULL;
	while (i < master->new_size)
	{
		if (ht[i])
		tmp = ht[i];
		while (tmp)
		{
			tmp->entry->visited = 0;
			if (x == 1)
				tmp->entry->used = 0;
			tmp = tmp->next;
		}
		i++;
	}
}

void	adj_cap(t_entry *fnd, t_entry *via, int cap)
{
	t_bucket *edge;

	edge = get_edge(fnd, via);
	edge->cap = cap;
	via->used = 1;
}

t_bucket 	*get_edge(t_entry *fnd, t_entry *via)
{
	t_bucket 	*links;

	links = NULL;
	links = via->links;
	while (links)
	{
		if (ft_strequ(links->entry->name, fnd->name))
			return (links);
		links = links->next;
	}
	return (NULL);
}

void	clear_data(t_bucket **ht, t_master *master, t_bfs *bfs, int i)
{
	while (bfs->map)
		pop_from_map(&bfs->map);
	reset_data(ht, master, i);
	while (bfs->q)
		pop_from_ll(&bfs->q);
}

// void	swap(t_lol *x, t_lol *y)
// {
// 	t_lol	tmp;

// 	tmp = *x;
// 	*x = *y;
// 	*y = tmp;
// }

// void	sort_paths(t_lol *paths)
// {
// 	t_lol 	*tmp;
// 	int		t;

// 	tmp = paths;
// 	// t = 0;
// 	while (tmp)
// 	{
		
// 	}
// }

// void	sort_paths(t_lol *paths)
// {
// 	int		len_list;
// 	int		len_next;
// 	t_lol 	*lol;

// 	lol = paths;
// 	len_list = 0;
// 	len_next = 0;
// 	while (lol)
// 	{
// 		if (lol->next)
// 		{
// 			len_list = list_length(lol->list);
// 			len_next = list_length(lol->next->list);
// 			if (len_next < len_list)
// 			{
// 				swap(lol->next, lol);
// 				lol = paths;
// 			}
// 			else
// 				lol = lol->next;
// 		}
// 		else
// 			break ;
// 	}
// }
