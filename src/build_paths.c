/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:06:11 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/27 01:27:15 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		flow_chk(t_master *master)
{
	t_bucket	*tmp;

	tmp = master->start_room->links;
	while (tmp)
	{
		if (!tmp->entry->used)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	init_paths(t_master *master)
{
	// t_paths *tmp;
	int		i;

	i = 0;
	// tmp = *master->paths;
	while (i < MAX_SETS)
	{
		ft_printf("address: %p\n", master->paths[i]);
		i++;
	}
}

void	assemble_path(t_bucket **ht, t_master *master, int set_id)
{
	t_bucket	*ll;
	t_pmap		*tmp;
	t_pmap		*cur;

	ll = NULL;
	cur = master->bfs->map;
	tmp = master->bfs->map->next;
	append_to_ll(&ll, cur->fnd);
	append_to_ll(&ll, cur->via);
	while (tmp)
	{
		if (ft_strequ(tmp->fnd->name, cur->via->name))
		{
			append_to_ll(&ll, tmp->via);
			if (ft_strequ(tmp->via->name, master->start_room->name))
				break ;
			cur->via = tmp->via;
		}
		tmp = tmp->next;
	}
	
	ft_printf("path: ");
	print_ll(ll);
	system("leaks lem-in");
	ft_error("exit after path print\n");
}

void	build_paths_2(t_bucket **ht, t_master *master, t_bucket *links, int set_id)
{
	while (links)
	{
		ft_printf("name: %s | vis: %d | used: %d | flow: %d\n", \
		links->entry->name, links->entry->visited, links->entry->used, links->flow);
		if (!links->entry->visited && !links->entry->used && links->flow)
		{
			if (ft_strequ(links->entry->name, master->end_room->name))
			{
				unshift_to_map(&master->bfs->map, links->entry, master->bfs->cur);
				assemble_path(ht, master, set_id);
			}
			else
			{
				append_to_ll(&master->bfs->q, links->entry);
				unshift_to_map(&master->bfs->map, links->entry, master->bfs->cur);
				links->entry->visited = 1;
			}
		}
		links = links->next;
	}
}

void	build_paths(t_bucket **ht, t_master *master, int set_id)
{
	t_bucket *tmp;

	if (!master->paths)
		master->paths = ft_memalloc(sizeof(t_distro*) * MAX_SETS);
	while (flow_chk(master))
	{
		append_to_ll(&master->bfs->q, master->start_room);
		while (master->bfs->q)
		{
			ft_printf("q: ");
			print_ll(master->bfs->q);
			master->bfs->cur = master->bfs->q->entry;
			pop_from_ll(&master->bfs->q);
			master->bfs->cur->visited = 1;
			tmp = master->bfs->cur->links;
			build_paths_2(ht, master, tmp, set_id);

		}

		// system("leaks lem-in");
	}
	ft_error("exiting after 1 round\n");
	// print_ht(ht);
}