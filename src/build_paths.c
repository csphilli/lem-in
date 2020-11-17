/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 09:38:45 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/17 10:04:05 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	reset_visited(t_bucket **ht, t_master *master)
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
			tmp = tmp->next;
		}
		i++;
	}
}

void	initialize_capacities(t_bucket **ht, t_master *master)
{
	t_bucket *tmp;
	t_bucket	*links;
	size_t		i;

	i = 0;
	tmp = NULL;
	links = NULL;
	while (i < master->new_size)
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
					links = links->next;
				}
				tmp = tmp->next;
			}
		}
		i++;
	}
}

void		print_map(t_pmap *map)
{
	t_pmap *tmp;

	tmp = map;
	while (tmp)
	{
		ft_printf("{f: %s | v: %s}", tmp->fnd->name, tmp->via->name);
		tmp->next ? write(1, "->", 2) : 1;
		tmp = tmp->next;
	}
	write(1, "\n", 1);
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

void	unshift_to_map(t_pmap **map, t_entry *found, t_entry *via)
{
	t_pmap	*head;
	t_pmap	*new;

	head = *map;
	new = ft_memalloc(sizeof(t_pmap));
	new->fnd = found;
	new->via = via;
	if (head == NULL)
		head = new;
	else
	{
		new->next = head;
		head = new;
	}
	*map = head;
}

void	adj_cap(t_entry *fnd, t_entry *via, int cap)
{
	t_bucket *edge;

	// ft_printf("adjust %s via %s\n", fnd->name, via->name);
	edge = get_edge(fnd, via);
	edge->cap = cap;
	via->used = 1;
}

void	map_to_paths(t_bfs *bfs)
{
	t_bucket	*ll;
	t_pmap 		*tmp;
	t_pmap 		*cur;

	ll = NULL;
	cur = bfs->map;
	tmp = bfs->map->next;
	append_to_ll(&ll, cur->fnd);
	append_to_ll(&ll, cur->via);
	adj_cap(cur->fnd, cur->via, 0);
	while (tmp)
	{
		if (ft_strequ(tmp->fnd->name, cur->via->name))
		{
			append_to_ll(&ll, tmp->via);
			// ft_printf("tmp->fnd: %s | tmp->via: %s\n", tmp->fnd->name, tmp->via->name);
			adj_cap(tmp->fnd, tmp->via, 0);
			// if (ft_strequ(tmp->via->name, bfs->start->name))
			if (ft_strequ(tmp->via->name, bfs->start->name))
			{
				// adj_cap(tmp->via, tmp->fnd, 0);
				break ;
			}
			cur->via = tmp->via;
		}
		tmp = tmp->next;
	}
	append_to_lol(&bfs->paths, ll);
}

void	pop_from_map(t_pmap **map)
{
	t_pmap *tmp;
	t_pmap *head;

	head = *map;
	tmp = head;
	if (!head->next)
	{
		free(head);
		head = NULL;
	}
	else
	{
		head = head->next;
		free(tmp);
		tmp = NULL;
	}
	*map = head;
}

void	clear_data(t_bucket **ht, t_master *master, t_bfs *bfs)
{
	while (bfs->map)
		pop_from_map(&bfs->map);
	reset_visited(ht, master);
	while (bfs->q)
		pop_from_ll(&bfs->q);
}

void	paths3(t_bucket **ht, t_master *master, t_bfs *bfs)
{
	t_entry 	*cur;
	t_bucket	*tmp;
	
	cur = get_entry(ht, master, bfs->cur->name);
	tmp = cur->links;
	while (tmp)
	{
		if (ft_strequ(tmp->entry->name, bfs->end->name))
		{
			unshift_to_map(&bfs->map, tmp->entry, cur);
			map_to_paths(bfs);
			clear_data(ht, master, bfs);
			return ;
		}
		else if (tmp->cap && !tmp->entry->visited && !tmp->entry->used)
		{
			append_to_ll(&bfs->q, tmp->entry);
			unshift_to_map(&bfs->map, tmp->entry, cur);
			tmp->entry->visited = 1;
		}
		tmp = tmp->next;
	}
}

int		paths_exist(t_bfs *bfs)
{
	t_bucket 	*tmp;

	tmp = bfs->start->links;
	while (tmp)
	{
		if (tmp->cap == 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	build_paths2(t_bucket **ht, t_master *master, t_bfs *bfs)
{
	int	len;
	len = list_length(bfs->start->links);
	while (len--)
	{
		// append_to_ll(&bfs->q, master->start_room);
		append_to_ll(&bfs->q, bfs->start);
		while (bfs->q)
		{
			bfs->cur = bfs->q->entry;
			pop_from_ll(&bfs->q);
			paths3(ht, master, bfs);
		}
		// print_lol(&bfs->paths);
		// ft_printf(RED"NEWLINE\n"RESET);
		// return ;
		// print_ht(ht, master->new_size);
		// clear_data(ht, master, bfs);
	}
}

void	build_paths(t_bucket **ht, t_master *master, t_bfs **bfs)
{
	// t_bfs	*bfs;

	// bfs = ft_memalloc(sizeof(t_bfs));
	// bfs->start = master->start_room;
	// bfs->end = master->end_room;
	// ft_printf("bfs start: %s | end: %s\n", bfs->start->name, bfs->end->name);
	initialize_capacities(ht, master);
	build_paths2(ht, master, *bfs);
	// print_lol(bfs->paths);
	// return (bfs);
	// exit(1);
}
