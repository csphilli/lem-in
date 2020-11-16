/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 10:40:08 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/15 11:50:31 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		included(t_bucket **bfs, t_entry *entry)
{
	t_bucket *tmp;

	tmp = *bfs;
	while (tmp)
	{
		if (ft_strequ(tmp->entry->name, entry->name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		visited(t_bucket **bfs, t_entry *entry)
{
	t_bucket	*tmp;

	tmp = *bfs;
	while (tmp)
	{
		if (ft_strequ(tmp->entry->name, entry->name) && \
			tmp->entry->visited)
				return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	check_new_links(t_bucket **bfs, t_entry *entry, t_lol **lolq)
{
	t_bucket	*new;
	t_bucket	*tmp;

	new = NULL;
	tmp = (*lolq)->list;
	if (!visited(bfs, entry) && included(bfs, entry))
	{
		copy_ll(&new, tmp);
		unshift_ll(&new, entry);
		append_to_lol(lolq, new);
	}
}

void		build_paths2(t_bucket **bfs, t_lol **paths, t_lol **lolq, t_entry *goal)
{
	t_bucket	*tmp;
	t_bucket		*new;

	tmp = NULL; 
	new = NULL;
	while ((*lolq)->list)
	{
		tmp = (*lolq)->list->entry->links;
		if (ft_strequ((*lolq)->list->entry->name, goal->name))
		{
			copy_ll(&new, (*lolq)->list);
			append_to_lol(paths, new);
		}
		else
		{
			set_visited(&(*lolq)->list, 1);
			while (tmp)
			{
				check_new_links(bfs, tmp->entry, lolq);
				tmp = tmp->next;
			}		
			set_visited(&(*lolq)->list, 0);
		}
		print_lol(lolq);
		if ((*lolq)->list)
			pop_from_lol(lolq);
	}
}

void	build_paths(t_bucket **bfs, t_entry *start, t_entry *goal)
{
	// ft_printf("build paths\n");
	t_bucket	*new;
	t_bucket	*newer;
	t_lol		*lolq;
	t_lol		*paths;

	lolq = NULL;
	new = NULL;
	newer = NULL;
	paths = NULL;
	unshift_ll(&new, start);
	// unshift_lol(&lolq, new);
	append_to_lol(&lolq, new);
	build_paths2(bfs, &paths, &lolq, goal);
	print_lol(&paths);
}