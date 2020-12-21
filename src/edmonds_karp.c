/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 09:38:45 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/21 14:15:08 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	map_to_paths(t_bfs *bfs, int i)
{
	t_bucket	*ll;
	t_pmap		*tmp;
	t_pmap		*cur;
	t_entry		*goal;

	ll = NULL;
	cur = bfs->map;
	tmp = bfs->map->next;
	goal = (i == 1 ? bfs->start : bfs->end);
	append_to_ll(&ll, cur->fnd);
	append_to_ll(&ll, cur->via);
	adj_cap(cur->fnd, cur->via, 0);
	while (tmp)
	{
		if (ft_strequ(tmp->fnd->name, cur->via->name))
		{
			append_to_ll(&ll, tmp->via);
			adj_cap(tmp->fnd, tmp->via, 0);
			if (ft_strequ(tmp->via->name, goal->name))
				break ;
			cur->via = tmp->via;
		}
		tmp = tmp->next;
	}
	i == 1 ? insert_to_lol(&bfs->s2e, ll) : insert_to_lol(&bfs->e2s, ll);
}

void	build_paths2(t_bucket **ht, t_master *master, t_bfs *bfs, int i)
{
	t_entry		*cur;
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
			clear_data(ht, bfs, 0);
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

void	edmonds_karp2(t_bucket **ht, t_master *master, t_bfs **bfs, int i)
{
	int		len;
	t_entry	*entry;

	entry = (i == 1 ? (*bfs)->start : (*bfs)->end);
	len = list_length(entry->links);
	init_caps(ht);
	reset_data(ht, 1);
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
	if (!(*bfs)->s2e && !(*bfs)->e2s)
		master->flags.errors ? \
		ft_error("ERROR: No solution. No link between start and end.") : \
		ft_error("ERROR");
}

void	edmonds_karp(t_bucket **ht, t_master *master, t_bfs **bfs)
{
	edmonds_karp2(ht, master, bfs, 0);
	reverse_paths(&(*bfs)->e2s);
	edmonds_karp2(ht, master, bfs, 1);
}
