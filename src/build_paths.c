/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 09:38:45 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/22 19:24:44 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	init_caps2(t_bucket *head)
{
	t_bucket 	*tmp;
	t_bucket	*links;

	tmp = head;
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

void	init_caps(t_bucket **ht, t_master *master)
{
	t_bucket 	*tmp;
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
			init_caps2(tmp);
		}
		i++;
	}
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
			adj_cap(tmp->fnd, tmp->via, 0);
			adj_cap(tmp->via, tmp->fnd, 0); // added this
			// if (ft_strequ(tmp->via->name, bfs->start->name))
			if (ft_strequ(tmp->via->name, bfs->end->name))
				break ;
			cur->via = tmp->via;
		}
		tmp = tmp->next;
	}
	append_to_lol(&bfs->paths, ll);
}

void	build_paths2(t_bucket **ht, t_master *master, t_bfs *bfs)
{
	t_entry 	*cur;
	t_bucket	*tmp;
	
	cur = get_entry(ht, master, bfs->cur->name);
	tmp = cur->links;
	cur->visited = 1; // added this
	while (tmp)
	{
		// if (tmp->cap && (ft_strequ(tmp->entry->name, bfs->end->name)))
		if (tmp->cap && (ft_strequ(tmp->entry->name, bfs->start->name)))
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
			// tmp->entry->visited = 1; // commented out
		}
		tmp = tmp->next;
	}
}

void	reverse_ll(t_bucket **new, t_bucket *list)
{
	t_bucket	*tmp;
	
	tmp = list;
	while (tmp)
	{
		if (*new == NULL)
			
		unshift_ll(new, tmp->entry);
		tmp = tmp->next;
	}
	*new = tmp;
	ft_printf("Printing ll inside reverse\n");
	print_ll(*new);
}

void	free_lol(t_lol *lol)
{
	t_lol *tmp;

	tmp = lol;
	while (tmp)
	{
		while (tmp->list)
			pop_from_ll(&tmp->list);
		tmp = tmp->next;
	}
}

void	free_ll(t_bucket **ll)
{
	t_bucket *tmp;

	tmp = *ll;
	while (tmp)
		pop_from_ll(&tmp);
	tmp = NULL;
}

void	reverse_paths(t_lol **lol)
{
	t_lol 		*tmp;
	t_bucket	*newll;
	t_lol		*newlol;

	tmp = *lol;
	newll = NULL;
	newlol = NULL;
	while (tmp->list)
	{
		while (tmp->list)
		{
			unshift_ll(&newll, tmp->list->entry);
			pop_from_ll(&tmp->list);
		}
		append_to_lol(&newlol, newll);
		newll = NULL;
		pop_from_lol(&tmp);
	}
	*lol = newlol;
}


void	build_paths(t_bucket **ht, t_master *master, t_bfs **bfs)
{
	int len;

	// len = list_length((*bfs)->start->links);
	len = list_length((*bfs)->end->links);
	init_caps(ht, master);
	while (len--)
	{
		// append_to_ll(&(*bfs)->q, (*bfs)->start);
		append_to_ll(&(*bfs)->q, (*bfs)->end);
		while ((*bfs)->q)
		{
			(*bfs)->cur = (*bfs)->q->entry;
			pop_from_ll(&(*bfs)->q);
			build_paths2(ht, master, *bfs);
		}
	}
	if (!(*bfs)->paths)
		ft_error("ERROR: No solution. No link between start and end.");
	// print_lol(&(*bfs)->paths);
	reverse_paths(&(*bfs)->paths);
	sort_paths(*bfs);
	print_lol(&(*bfs)->paths);
	// while (1)
	// {
		
	// }
	// calc_distribution(master, *bfs);
}
