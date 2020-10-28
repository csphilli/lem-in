/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:00:25 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/28 11:09:52 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_bucket	**grow_chosen_array(t_paths *paths, t_bucket *copy)
{
	t_bucket	**new;
	t_bucket	*tmp;
	int			i;
	int			len;

	i = 0;
	tmp = NULL;
	len = bucket_arr_len(paths->c) + 2;
	if (!(new = (t_bucket**)malloc(sizeof(t_bucket*) * len)))
		exit_malloc();
	init_paths(len, new);
	while (i < len - 2)
	{
		tmp = paths->c[i];
		while (tmp)
		{
			new[i] = insert_node_to_path(new[i], tmp->entry);
			tmp = tmp->next;
		}
		i++;
	}
	new[i] = copy_from_array(new[i], copy);
	delete_old_path(paths->c);
	return (new);
}




void		collision_check(t_paths *paths, t_bucket *src)
{
	t_bucket	*comp;
	t_bucket	*tmp;
	int			i;

	comp = NULL;
	tmp = src;
	i = 0;
	while (i < bucket_arr_len(paths->p))
	{
		paths->collision = 0;
		tmp = src->next;
		while (tmp)
		{
			comp = paths->p[i]->next;
			while (comp)
			{
				if (ft_strequ(comp->entry->name, tmp->entry->name) && \
					!ft_strequ(comp->entry->name, paths->s_room->name))
					paths->collision = 1;
				comp = comp->next;
			}
			tmp = tmp->next;
		}
		if (paths->collision == 0)
		{
			paths->c = grow_chosen_array(paths, src);
			return ;
		}
		i++;
	}
}

void	collision_parse(t_paths *paths)
{
	t_bucket	*tmp;
	int			index;

	tmp = NULL;
	index = 0;
	while (index < bucket_arr_len(paths->p))
	{
		tmp = paths->p[index];
		collision_check(paths, tmp);
		index++;
	}
}

// int		list_len(t_bucket *head)
// {
// 	t_bucket	*tmp;
// 	int			len;

// 	tmp = head;
// 	len = 1;
// 	while (tmp->next)
// 	{
// 		len++;
// 		tmp = tmp->next;
// 	}
// 	return (len);
// }



void	choose_paths(t_master *master, t_paths *paths)
{
	if (!(paths->c = (t_bucket**)malloc(sizeof(t_bucket) * paths->c_len)))
		exit_malloc();
	init_paths(paths->c_len, paths->c);
	ft_printf("printing paths\n");
	ft_printf("printing random: %s\n", master->start_room);
	// get_shortest_path(paths);
	// paths->c[0] = copy_from_array(paths->c[0], paths->p[paths->shortest_index]);
	ft_printf("ALL PATHS:\n");
	print_paths(paths->p);
	ft_printf("CHOSEN PATHS (UNSORTED):\n");
	collision_parse(paths);
	print_paths(paths->c);
	ft_printf("CHOSEN PATHS (SORTED):\n");
	sort_chosen_paths(paths);
	print_paths(paths->c);
	max_paths(paths);
	while (1)
	{
		
	}
	// ants_marching(paths);
	// if (bucket_arr_len(paths->c) > paths->max_paths)
	// 	choose_wisely(paths);
	// ft_printf("Max paths: %d\n", paths->max_paths);
	// ft_printf("Pos %d has the minimum len of %d\n", pos, min);
	// while (1)
	// {
		
	// }
}