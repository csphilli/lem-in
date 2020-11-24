/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 09:38:45 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/24 12:57:37 by cphillip         ###   ########.fr       */
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
		// tmp->cap = 1;
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

void	map_to_paths(t_bfs *bfs, int i)
{
	t_bucket	*ll;
	t_pmap 		*tmp;
	t_pmap 		*cur;
	t_entry		*goal;

	ll = NULL;
	cur = bfs->map;
	tmp = bfs->map->next;
	goal = (i == 1 ? bfs->start : bfs->end);
	append_to_ll(&ll, cur->fnd);
	append_to_ll(&ll, cur->via);
	adj_cap(cur->fnd, cur->via, 0);
	// adj_cap(tmp->via, tmp->fnd, 0);
	while (tmp)
	{
		if (ft_strequ(tmp->fnd->name, cur->via->name))
		{
			append_to_ll(&ll, tmp->via);
			adj_cap(tmp->fnd, tmp->via, 0);
			adj_cap(tmp->via, tmp->fnd, 0); // added this
			// if (ft_strequ(tmp->via->name, bfs->start->name))
			// if (ft_strequ(tmp->via->name, bfs->end->name))
			if (ft_strequ(tmp->via->name, goal->name))
				break ;
			cur->via = tmp->via;
		}
		tmp = tmp->next;
	}
	i == 1 ? insert_to_lol(&bfs->s2e_paths, ll) : \
			insert_to_lol(&bfs->e2s_paths, ll);
}

void	build_paths2(t_bucket **ht, t_master *master, t_bfs *bfs, int i)
{
	t_entry 	*cur;
	t_bucket	*tmp;
	t_entry		*entry;

	entry = (i == 1 ? bfs->end : bfs->start);
	cur = get_entry(ht, master, bfs->cur->name);
	tmp = cur->links;
	cur->visited = 1;
	while (tmp)
	{
		if (tmp->cap && (ft_strequ(tmp->entry->name, entry->name)))
		{
			unshift_to_map(&bfs->map, tmp->entry, cur);
			map_to_paths(bfs, i);
			clear_data(ht, master, bfs, 0);
			// i == 0 ? print_lol(&bfs->e2s_paths) : print_lol(&bfs->s2e_paths);
			// print_ht(ht, master->new_size);
			return ;
		}
		else if (tmp->cap && !tmp->entry->visited && !tmp->entry->used)
		{
			append_to_ll(&bfs->q, tmp->entry);
			unshift_to_map(&bfs->map, tmp->entry, cur);
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


void	build_paths(t_bucket **ht, t_master *master, t_bfs **bfs, int i)
{
	int len;
	t_entry *entry;

	entry = (i == 1 ? (*bfs)->start : (*bfs)->end);
	len = list_length(entry->links);
	init_caps(ht, master);
	reset_data(ht, master, 1);
	while (len--)
	{
		append_to_ll(&(*bfs)->q, entry);
		while ((*bfs)->q)
		{
			(*bfs)->cur = (*bfs)->q->entry;
			pop_from_ll(&(*bfs)->q);
			build_paths2(ht, master, *bfs, i);
		}
	}	
	if (!(*bfs)->s2e_paths && !(*bfs)->e2s_paths)
		ft_error("ERROR: No solution. No link between start and end.");
}

void	build_paths_parse(t_bucket **ht, t_master *master, t_bfs **bfs)
{
	// ft_printf("E2S PATHS BEFORE SORT\n");
	build_paths(ht, master, bfs, 0);
	// ft_printf("List Length: %d\n", lol_length((*bfs)->e2s_paths));
	// print_lol(&(*bfs)->e2s_paths);

	// sort_paths((*bfs)->e2s_paths);
	// ft_printf("E2S PATHS AFTER SORT\n");
	// ft_printf("List Length: %d\n", lol_length((*bfs)->e2s_paths));
	// print_lol(&(*bfs)->e2s_paths);
	// exit(1);
	reverse_paths(&(*bfs)->e2s_paths);

	// ft_printf("S2E PATHS BEFORE SORT\n");
	build_paths(ht, master, bfs, 1);
	// ft_printf("List Length: %d\n", lol_length((*bfs)->s2e_paths));
	// print_lol(&(*bfs)->s2e_paths);
	// sort_paths((*bfs)->s2e_paths);

	// ft_printf("S2E PATHS AFTER SORT\n");
	// ft_printf("List Length: %d\n", lol_length((*bfs)->s2e_paths));
	// print_lol(&(*bfs)->s2e_paths);
	// ft_printf("List Length: %d\n", lol_length((*bfs)->e2s_paths));
	// ft_printf("List Length: %d\n", lol_length((*bfs)->s2e_paths));
	// exit(1);
}