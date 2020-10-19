/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 10:57:48 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/19 08:39:23 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

// t_entry		**copy_and_insert_links(t_entry **array)
// {
// 	t_entry	**new;
// 	int		size;

// 	if (!(new = (t_entry**)malloc(sizeof(t_entry*))))
// }

// t_entry		*create_entry(void)
// {
// 	t_entry	*new;

// 	if (!(new = (t_entry*)malloc(sizeof(t_entry))))
// 		exit_malloc();
// 	init_entry(new);
// 	return (new);
// }

t_bucket	*copy_and_insert_node(t_bucket *head, t_entry *entry)
{
	// ft_printf("INSIDE COPY\n");
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
	// ft_printf(" Done filling values\n");
	new->entry = copy;
	if (head == NULL)
	{
		head = create_bucket();
		head = new;
	}
	else
	{
		tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	// ft_printf(" Done assigning to list\n");
	return (head);
}

t_bucket	**increase_paths(t_master *master, t_bucket **p)
{
	// ft_printf("Increasing paths\n");
	t_bucket	**new;
	t_bucket	**tmp;
	t_bucket	*curr;
	size_t		i;

	i = 0;
	tmp = p;
	// ft_printf("n_paths?: %d\n", master->n_paths);
	master->n_paths += 1;
	// ft_printf("n_paths?: %d\n", master->n_paths);
	if (!(new = (t_bucket**)malloc(sizeof(t_bucket*) * (master->n_paths + 1))))
		exit_malloc();
	init_paths(master, new);
	while (tmp[i])
	{
		// ft_printf("tmp[%d]->entry: %s | %p\n", i, tmp[i]->entry->name, tmp[i]);
		curr = tmp[i];
		while (curr)
		{
			new[i] = copy_and_insert_node(new[i], curr->entry);
			curr = curr->next;
		}
		i++;
	}
	delete_old_ht(p, master->n_paths - 2);
	curr = new[i - 1];
	while (curr)
	{
		new[i] = copy_and_insert_node(new[i], curr->entry);
		curr = curr->next;
	}
	// master->loc++;
	// ft_printf("Done with increasing size\n");
	return (new);	
}

void	print_list(t_bucket *list)
{
	ft_printf("PRINTING LIST\n");
	t_bucket	*tmp;
	tmp = list;
	while (tmp)
	{
		ft_printf("%s", tmp->entry->name);
		if (tmp->next)
			ft_printf(",");
		tmp = tmp->next;
	}
	ft_printf("\n");
}

t_bucket	**crawl(t_master *master, t_paths *paths, t_entry *entry)
{
	// ft_printf("Into Crawl with entry: %s\n", entry->name);
	size_t	i;
	size_t	n_paths;

	i = 0;
	n_paths = (entry->link_arr ? link_array_len(entry->link_arr) : 0);
	if (!ft_strequ(entry->name, master->start_room))
		entry->visited = true;
	if ((ft_strequ(entry->name, master->start_room) || !entry->link_arr || \
		explored(entry)) && !dead_end(master, entry))
	{
		paths->p = increase_paths(master, paths->p);
		paths->p[master->loc] = copy_and_insert_node(paths->p[master->loc], entry);
		master->loc++;
		return (paths->p);
	}
	else if (link_array_len(entry->link_arr) > 0)
	{
		// ft_printf("link_array > 0. Inserting %s to index: %d\n", entry->name, master->loc);
		paths->p[master->loc] = copy_and_insert_node(paths->p[master->loc], entry);
	}
	while (i < n_paths)
	{
		if (!entry->link_arr[i]->visited && !dead_end(master, entry->link_arr[i]))
			paths->p = crawl(master, paths, entry->link_arr[i]);
		i++;
	}

	return (paths->p);
}

void	find_paths(t_bucket **ht, t_master *master)
{
	t_paths *paths;
	t_entry	*end;
	size_t	n_paths;
	size_t	i;

	end = get_entry(ht, master, master->end_room);
	i = 0;
	n_paths = link_array_len(end->link_arr);
	if (!(paths = (t_paths*)malloc(sizeof(t_paths))))
		exit_malloc();
	if (!(paths->p = (t_bucket**)malloc(sizeof(t_bucket*) * (master->n_paths + 1))))
		exit_malloc();
	init_paths(master, paths->p);
	// end->visited = true;
	while (i < n_paths)
	{
		ft_printf("STARTING: %s\n", end->link_arr[i]->name);
		// clear_visited(master, ht);
		paths->p = crawl(master, paths, end);
		i++;
	}
	
	print_paths(master, paths);
}