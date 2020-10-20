/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:15:03 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/20 17:44:09 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	pop_from_list(t_bucket *head)
{
	t_bucket 	*tmp;

	tmp = head;
	while (tmp->next->next)
		tmp = tmp->next;	
	free_entry(tmp->next->entry);
	free_bucket(tmp->next);
	tmp->next = NULL;
}

void	print_list(t_bucket *head)
{
	t_bucket *tmp;
	tmp = head;
	while (tmp)
	{
		ft_printf("%s,", tmp->entry->name);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

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

t_bucket	*copy_from_array(t_bucket *head, t_bucket *src)
{
	t_bucket	*tmp;

	tmp = src;
	while (tmp)
	{
		head = insert_node_to_path(head, tmp->entry);
		tmp = tmp->next;
	}
	return (head);
}

void	delete_old_path(t_bucket **paths)
{
	t_bucket	**tmp;
	t_bucket	*curr;
	t_bucket	*hold;
	int			i;

	tmp = paths;
	i = 0;
	hold = NULL;
	while (i < bucket_arr_len(paths))
	{
		if (tmp[i])
		{
			curr = tmp[i];
			while (curr)
			{
				hold = curr;
				curr = curr->next;
				free_entry(hold->entry);
				free_bucket(hold);
			}
		}
		i++;
	}
	free(paths);
	paths = NULL;
}

t_bucket	**grow_path_array(t_paths *paths)
{
	t_bucket	**new;
	t_bucket	*tmp;
	int			i;
	int			len;

	i = 0;
	tmp = NULL;
	len = bucket_arr_len(paths->p) + 2;
	if (!(new = (t_bucket**)malloc(sizeof(t_bucket*) * len)))
		exit_malloc();
	init_paths(len, new);
	while (i < len - 2)
	{
		tmp = paths->p[i];
		while (tmp)
		{
			new[i] = insert_node_to_path(new[i], tmp->entry);
			tmp = tmp->next;
		}
		i++;
	}
	tmp = paths->p[i - 1];
	new[i] = copy_from_array(new[i], tmp);
	delete_old_path(paths->p);
	return (new);
}

t_paths	*crawl(t_master *master, t_paths *paths, t_entry *entry)
{
	int	i;
	
	i = 0;
	if (!ft_strequ(entry->name, master->start_room))
		entry->visited = true;
	if (ft_strequ(entry->name, master->start_room))
	{
		paths->p[paths->index] = insert_node_to_path(paths->p[paths->index], entry);
		paths->p = grow_path_array(paths);
		paths->index++;
		pop_from_list(paths->p[paths->index]);
		return (paths);
	}
	else
		paths->p[paths->index] = insert_node_to_path(paths->p[paths->index], entry);
	while (i < link_array_len(entry->link_arr))
	{
		if (!entry->link_arr[i]->visited)
			paths = crawl(master, paths, entry->link_arr[i]);
		i++;
	}
	// ft_printf(RED"Returning from %s\n"RESET, entry->name);
	if (!ft_strequ(entry->name, master->end_room))
		pop_from_list(paths->p[paths->index]);
	entry->visited = false;
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
	paths->index = 0;
	paths->len = 0;
	paths->p_len = 2;
	if (!(paths->p = (t_bucket**)malloc(sizeof(t_bucket*) * paths->p_len)))
		exit_malloc();
	init_paths(paths->p_len, paths->p);
	dead_end_scan(master, ht);
	paths = crawl(master, paths, end);
	free_entry(paths->p[paths->index]->entry);
	free_bucket(paths->p[paths->index]);
	paths->p[paths->index] = NULL;
	print_paths(paths->p);
	while (1)
	{
		
	}
	// print_paths(paths->p);
	// ft_printf("end room: %s\n", end->name);
}	