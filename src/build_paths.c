/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 09:38:45 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/16 20:12:51 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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

t_bucket 	*get_edge(t_bucket **ht, t_master *master,\
						t_entry *fnd, t_entry *via)
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

void	adj_cap(t_bucket **ht, t_master *master, t_entry *fnd, t_entry *via, int cap)
{
	// ft_printf("adjusting cap\n");
	t_bucket *edge;


	edge = get_edge(ht, master, fnd, via);
	// ft_printf("edge: %s\n", edge->entry->name);
	edge->cap = cap;
	// ft_printf("done adjusting cap\n");
}

void	map_to_paths(t_bucket **ht, t_master *master, t_bfs *bfs)
{
	t_bucket	*ll;
	t_pmap 		*tmp;
	t_pmap 		*cur;

	ll = NULL;
	cur = bfs->map;
	tmp = bfs->map->next;
	append_to_ll(&ll, cur->fnd);
	append_to_ll(&ll, cur->via);
	// ft_printf("cur->fnd %s | cur->via %s\n", cur->fnd->name, cur->via->name);
	adj_cap(ht, master, cur->fnd, cur->via, 0);
	// ft_printf("tmp->fnd %s | tmp->via %s\n", tmp->fnd->name, tmp->via->name);
	
	// bfs->edge = get_edge(ht, master, cur->via, cur->fnd);
	// bfs->edge->cap = 0;
	while (tmp)
	{
		if (ft_strequ(tmp->fnd->name, cur->via->name))
		{
			append_to_ll(&ll, tmp->via);
			if (ft_strequ(tmp->via->name, bfs->start->name))
				break ;
			// ft_printf("tmp->fnd: %s | cur->via %s\n", tmp->fnd->name, tmp->via->name);
			adj_cap(ht, master, tmp->fnd, tmp->via, 0);
			// bfs->edge = get_edge(ht, master, cur->via, cur->fnd);
			// bfs->edge->cap = 0;
			cur->via = tmp->via;
		}
		tmp = tmp->next;
	}
	append_to_lol(&bfs->paths, ll);
}

void	clear_data(t_bfs *bfs)
{
	print_lol(&bfs->paths);
	exit(1);
}

void	add_to_q_if(t_bucket **ht, t_master *master, t_bfs *bfs)
{
	// ft_printf("add to q if..\n");
	t_entry 	*cur;
	t_bucket	*tmp;
	
	cur = get_entry(ht, master, bfs->cur->name);
	tmp = cur->links;
	while (tmp)
	{
		// ft_printf("tmp name: %s\n", tmp->entry->name);
		if (ft_strequ(tmp->entry->name, bfs->goal->name))
		{
			unshift_to_map(&bfs->map, tmp->entry, cur);
			// print_map(bfs->map);
			map_to_paths(ht, master, bfs);
			clear_data(bfs);
		}
		else if (tmp->cap && !tmp->entry->visited)
		{
			append_to_ll(&bfs->q, tmp->entry);
			unshift_to_map(&bfs->map, tmp->entry, cur);
			// print_map(bfs->map);
			tmp->entry->visited = 1;
		}
		tmp = tmp->next;
	}
}

void	build_paths2(t_bucket **ht, t_master *master)
{
	t_bfs	*bfs;

	
	bfs = ft_memalloc(sizeof(t_bfs));
	append_to_ll(&bfs->q, master->start_room);
	bfs->goal = master->end_room;
	bfs->start = master->start_room;
	// print_ll(bfs->q);
	while (bfs->q)
	{
		bfs->cur = bfs->q->entry;
		pop_from_ll(&bfs->q);
		add_to_q_if(ht, master, bfs);
	}
	print_map(bfs->map);
	while (1)
	{
		
	}

}

void	build_paths(t_bucket **ht, t_master *master)
{
	initialize_capacities(ht, master);
	build_paths2(ht, master);
	// set_cap(&test, 0);

}