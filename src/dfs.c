/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 15:11:52 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/12 15:56:48 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"




void	print_routes(t_entry **q)
{
	t_entry **tmp;
	// int	len;
	int i;

	i = 0;
	tmp = q;

	while (tmp[i])
	{
		ft_printf("%s", tmp[i]->name);
		if (tmp[i + 1])
			ft_printf(",");
		i++;
	}
	ft_printf("\n");
	// len = link_array_len(routes->q);
	// ft_printf("Len of route: %d\n");
	// ft_printf("Curr: ");
	// while (i < len)
	// 	ft_printf("%s ", routes->q[i++]->name);
	// ft_printf("\n");
}

void	crawl(t_entry *entry, t_routes *routes)
{
	int	n_paths;
	int	i;

	n_paths = link_array_len(entry->link_arr);
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
	while (i < n_paths)
	{
		if (!entry->link_arr[i]->visited)
			crawl(entry->link_arr[i], routes);
		i++;
	}
}

void	do_dfs(t_master *master)
{
	t_routes	*routes;
	int			n_paths;
	int			i;

	i = 0;
	n_paths = link_array_len(master->end_room->link_arr);
	if (!(routes = (t_routes*)malloc(sizeof(t_routes))))
		exit_malloc();
	if (!(routes->q = (t_entry**)malloc(sizeof(t_entry*))))
		exit_malloc();
	routes->q[0] = NULL;
	crawl(master->end_room, routes);
	// while (1)
	// {
		
	// }
	print_routes(routes->q);
	
	
	i = 0;
	// while (routes->q[i] != NULL)
	// {
	// 	ft_printf("%s ", routes->q[i]->name);
	// 	i++;
	// }
	
	
	
}
/*
int		match(t_routes *routes, t_entry *entry)
{
	int	i;

	i = 0;
	ft_printf("Inside matching.\n");
	while (routes->q[i])
	{
		
		// ft_printf(" Searching for: %s\n", entry->name);
		if (ft_strequ(routes->q[i]->name, entry->name))
		{
			ft_printf(" Found %s\n", entry->name);
			return (1);
		}
		i++;
	}
	ft_printf(" Didn't find %s\n", entry->name);
	return (0);
}

void	crawl(t_entry *entry, t_routes *routes)
{
	int	n_paths;
	int	i;
	int	j;

	i = 0;
	j = 0;
	n_paths = link_array_len(entry->link_arr);
	ft_printf("Starting Crawl\n");
	ft_printf(" Number of paths: %d | Paths: ", n_paths);
	while (j < n_paths)
	{
		ft_printf("%s", entry->link_arr[j]->name);
			j + 1 < n_paths ? ft_printf(",") : 0;
		j++;
	}
	ft_printf("\n");
	// ft_printf("Inside %s with %d links\n", entry->name, n_paths);
	while (i < n_paths)
	{
		ft_printf("Round %d\n", i);
		if (!match(routes, entry->link_arr[i]) && !entry->visited)
		{
			// ft_printf("!match\n");
			
			if (!link_exists(routes->q, entry->link_arr[i]))
			{
				ft_printf("Link didn't exist, adding %s\n", entry->link_arr[i]->name);
				routes->q = append_link(routes->q, entry->link_arr[i]);

			}
			ft_printf("Moving to room: %s\n", entry->link_arr[i]->name);
			crawl(entry->link_arr[i], routes);
			// i++;
		}
		else if (match(routes, entry->link_arr[i]))
		{
			ft_printf("Name: %s\n", entry->link_arr[i]->name);
			ft_printf("match or visited\n");
			return ;
		}
		i++;
	}
	entry->visited = true;
}
	
*/