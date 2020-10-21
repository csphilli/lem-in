/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:58:07 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/21 10:03:27 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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

static t_paths	*crawl(t_master *master, t_paths *p, t_entry *entry)
{
	int	i;
	
	i = 0;
	if (!ft_strequ(entry->name, master->start_room))
		entry->visited = true;
	if (ft_strequ(entry->name, master->start_room))
	{
		p->p[p->index] = insert_node_to_path(p->p[p->index], entry);
		p->p = grow_path_array(p);
		p->index++;
		pop_from_list(p->p[p->index]);
		return (p);
	}
	else
		p->p[p->index] = insert_node_to_path(p->p[p->index], entry);
	while (i < link_array_len(entry->link_arr))
	{
		if (!entry->link_arr[i]->visited)
			p = crawl(master, p, entry->link_arr[i]);
		i++;
	}
	if (!ft_strequ(entry->name, master->end_room))
		pop_from_list(p->p[p->index]);
	entry->visited = false;
	return (p);
}

void	find_paths(t_master *master, t_bucket **ht)
{
	t_paths	*paths;
	t_entry	*end;
	t_entry	*start;

	end = get_entry(ht, master, master->end_room);
	start = get_entry(ht, master, master->start_room);
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
	if (end->visited == true || start->visited == true)
		ft_printf(E_NOPATH);
	else
	{
		paths = crawl(master, paths, end);
		free_entry(paths->p[paths->index]->entry);
		free_bucket(paths->p[paths->index]);
		paths->p[paths->index] = NULL;
	}
	print_paths(paths->p);
}	