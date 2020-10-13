/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 15:11:52 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/13 11:10:23 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_routes(t_routes *routes)
{
	t_entry **tmp;
	int i;

	i = 0;
	tmp = routes->q;
	ft_printf("Crawled: ");
	while (tmp[i])
	{
		ft_printf("%s", tmp[i]->name, tmp[i]);
		if (tmp[i + 1])
			ft_printf(",");
		i++;
	}
	ft_printf("\n");
}

void	crawl(t_entry *entry, t_routes *routes)
{
	int	n_paths;
	int	i;
	
	i = 0;
	entry->visited = true;
	if (!routes->q)
	{
		if (!(routes->q = (t_entry**)malloc(sizeof(t_entry*) * 2)))
			exit_malloc();
		routes->q[0] = entry;
		routes->q[1] = NULL;	
	}
	else if (!link_exists(routes->q, entry))
		routes->q = append_link(routes->q, entry);
	n_paths = link_array_len(entry->link_arr);
	while (i < n_paths)
	{
		if (!entry->link_arr[i]->visited)
			crawl(entry->link_arr[i], routes);
		i++;
	}
}

t_routes	*do_dfs(t_bucket **ht, t_master *master)
{
	t_routes	*routes;
	t_entry		*end;
	t_entry		*start;
	int			n_paths;
	int			i;

	end = NULL;
	i = 0;
	end = get_entry(ht, master, master->end_room);
	start = get_entry(ht, master, master->start_room);
	// ft_printf("S: %s | E: %s\n", master->start_room, master->end_room);
	n_paths = link_array_len(end->link_arr);
	if (!(routes = (t_routes*)malloc(sizeof(t_routes))))
		exit_malloc();
	routes->q = NULL;
	crawl(end, routes);
	// print_routes(routes);
	// while (1)
	// {
		
	// }
	
	check_path_exists(start, end, routes);
	// while (1)
	// {
		
	// }
	return (routes);
}