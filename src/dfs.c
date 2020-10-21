/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 15:11:52 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/20 19:25:44 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_dfs(t_dfs *dfs)
{
	t_entry **tmp;
	int i;

	i = 0;
	tmp = dfs->q;
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

static void		search_solution(t_entry *entry, t_dfs *dfs)
{
	int	n_paths;
	int	i;
	
	i = 0;
	entry->visited = true;
	if (!dfs->q)
	{
		if (!(dfs->q = (t_entry**)malloc(sizeof(t_entry*) * 2)))
			exit_malloc();
		dfs->q[0] = entry;
		dfs->q[1] = NULL;	
	}
	else if (!link_exists(dfs->q, entry))
		dfs->q = append_link(dfs->q, entry);
	n_paths = link_array_len(entry->link_arr);
	while (i < n_paths)
	{
		if (!entry->link_arr[i]->visited)
			search_solution(entry->link_arr[i], dfs);
		i++;
	}
}

void	do_dfs(t_bucket **ht, t_master *master) // dont need to seriously return it.
{
	t_dfs		*dfs;
	t_entry		*end;
	t_entry		*start;
	int			n_paths;
	int			i;

	end = NULL;
	i = 0;
	end = get_entry(ht, master, master->end_room);
	start = get_entry(ht, master, master->start_room);
	n_paths = link_array_len(end->link_arr);
	if (!(dfs = (t_dfs*)malloc(sizeof(t_dfs))))
		exit_malloc();
	dfs->q = NULL;
	search_solution(end, dfs);	
	check_path_exists(start, end, dfs);
	print_dfs(dfs);
	
	// find_paths(dfs);
	// return (dfs);
}