/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:07:27 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/19 13:34:22 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"


t_bucket	*insert_node_to_path(t_bucket *head, t_entry *node)
{
	t_bucket	*bucket;
	t_entry		*entry;
	t_bucket	*tmp;

	tmp = NULL;
	entry = copy_entry(node);
	bucket = create_bucket();
	bucket->entry = entry;
	if (head == NULL)
		head = bucket;
	else
	{
		tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = bucket;
	}
	return (head);
}

// t_bucket	**deep_copy(t_bucket **dst, t_bucket **src)
// {
// }

// void	delete_src(t_bucket **src)
// {
	
// }

t_bucket	**copy_old(t_bucket **src)
{
	int			len;
	int			i;
	t_bucket	*tmp;
	t_bucket	**new;

	i = 0;
	tmp = NULL;
	len = bucket_arr_len(src);
	len += 2;
	if (!(new = (t_bucket**)malloc(sizeof(t_bucket*) * len)))
		exit_malloc();
	init_paths(len + 1, new);
	while (i < len - 2)
	{
		tmp = src[i];
		while (tmp)
		{
			new[i] = insert_node_to_path(new[i], tmp->entry);
			tmp = tmp->next;
		}
		i++;
	}
	tmp = src[i - 1];
	while (tmp)
	{
		new[i] = insert_node_to_path(new[i], tmp->entry);
		tmp = tmp->next;
	}
	return (new);
}

t_bucket	**grow_path_array(t_master *master, t_bucket **src)
{
	t_bucket	**new;

	new = copy_old(src);
	return (new);	
}


t_bucket	**crawl(t_master *master, t_bucket **paths, t_entry *entry)
{
	size_t		i;
	size_t		n_links;
	t_bucket	*new;

	i = 0;
	new = NULL;
	n_links = (entry->link_arr ? link_array_len(entry->link_arr) : 0);
	if (!ft_strequ(entry->name, master->start_room))
		entry->visited = true;
	if ((ft_strequ(entry->name, master->start_room) || !entry->link_arr || \
		explored(entry)) && !dead_end(master, entry))
	{
		paths = grow_path_array(master, paths);
		// ft_printf("master->loc: %d\n", master->loc);
		paths[master->loc] = insert_node_to_path(paths[master->loc], entry);
		master->loc++;
		print_paths(paths);
		return (paths);
	}
	else if (link_array_len(entry->link_arr) > 0)
	{
		paths[master->loc] = insert_node_to_path(paths[master->loc], entry);
		// print_paths(paths);
	}
	
	// print_paths(paths);
	while (i < n_links)
	{
		if (!entry->link_arr[i]->visited && !dead_end(master, entry->link_arr[i]))
			paths = crawl(master, paths, entry->link_arr[i]);
		i++;
	}
	return (paths);
}

void	find_paths(t_master *master, t_bucket **ht)
{
	t_paths	*paths;
	t_entry	*end;

	end = get_entry(ht, master, master->end_room);
	if (!(paths = (t_paths*)malloc(sizeof(t_paths))))
		exit_malloc();
	paths->p = NULL;
	if (!(paths->p = (t_bucket**)malloc(sizeof(t_bucket*) * 2)))
		exit_malloc();
	init_paths(2, paths->p);
	end->visited = true; // put this inside while loop
	paths->p = crawl(master, paths->p, end);
	// ft_printf("end room: %s\n", end->name);
	// while (1)
	// {	
	// }
}	