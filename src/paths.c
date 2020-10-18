/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 10:57:48 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/18 12:23:09 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

// t_entry		**copy_and_insert_links(t_entry **array)
// {
// 	t_entry	**new;
// 	int		size;

// 	if (!(new = (t_entry**)malloc(sizeof(t_entry*))))
// }

t_entry		*create_entry(void)
{
	t_entry	*new;

	if (!(new = (t_entry*)malloc(sizeof(t_entry))))
		exit_malloc();
	init_entry(new);
	return (new);
}

void	copy_and_insert_node(t_bucket *head, t_entry *entry)
{
	t_bucket	*tmp;
	t_bucket	*new;
	t_entry		*copy;
	int			i;

	i = 0;
	new = create_bucket();
	copy = create_entry();
	copy->key = entry->key;
	copy->name = ft_strdup(entry->name);
	copy->visited = entry->visited;
	copy->x = entry->x;
	copy->y = entry->y;
	if (entry->comment)
		copy->comment = ft_strdup(entry->comment);
	if (entry->link_arr)
	{
		while (i < link_array_len(entry->link_arr))
			insert_link(copy, entry->link_arr[i++]);
	}
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	new->entry = copy;
	tmp->next = new;
}

t_bucket	**increase_paths(t_master *master, t_bucket **p)
{
	t_bucket	**new;
	t_bucket	*tmp;
	size_t		i;

	i = 0;
	tmp = NULL;
	master->n_paths++;
	if (!(new = (t_bucket**)malloc(sizeof(t_bucket*) * (master->n_paths + 1))))
		exit_malloc();
	init_paths(master, new);
	while (i < master->n_paths - 1)
	{
		tmp = p[i];
		while (tmp)
		{
			copy_and_insert_node(new[i], tmp->entry);
			tmp = tmp->next;
		}
		i++;
	}
	delete_old_ht(p, master->n_paths - 1);
	master->loc++;
	return (new);	
}

void	crawl(t_master *master, t_paths *paths, t_entry *entry)
{
	size_t	i;
	size_t	n_paths;

	i = 0;
	n_paths = (entry->link_arr ? link_array_len(entry->link_arr) : 0);
	if (!ft_strequ(entry->name, master->start_room))
		entry->visited = true;
	if (ft_strequ(entry->name, master->start_room) || !entry->link_arr || \
		explored(entry))
	{
		paths->p = increase_paths(master, paths->p);
		copy_and_insert_node(paths->p[master->loc - 1], entry);
		return ;
	}
	else if (link_array_len(entry->link_arr) > 0)
		copy_and_insert_node(paths->p[master->loc], entry);
	while (i < n_paths)
	{
		if (!entry->link_arr[i]->visited)
			crawl(master, paths, entry->link_arr[i]);
		i++;
	}
}

void	find_paths(t_bucket **ht, t_master *master)
{
	t_paths *paths;
	t_entry	*end;

	end = get_entry(ht, master, master->end_room);

	if (!(paths = (t_paths*)malloc(sizeof(t_paths))))
		exit_malloc();
	if (!(paths->p = (t_bucket**)malloc(sizeof(t_bucket*) * (master->n_paths + 1))))
		exit_malloc();
	init_paths(master, paths->p);
	// while (1)
	// {
		
	// }

	crawl(master, paths, end);
}