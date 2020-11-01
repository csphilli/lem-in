/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:00:25 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/01 19:37:36 by cphillip         ###   ########.fr       */
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

int			check_loop(t_bucket **arr, t_bucket *src, t_entry *start, int i)
{
	t_bucket	*tmp;
	t_bucket	*comp;

	tmp = src->next;
	while (tmp)
	{
		comp = arr[i]->next;
		while (comp)
		{
			if (ft_strequ(comp->entry->name, tmp->entry->name) && \
				!ft_strequ(comp->entry->name, start->name))
				return (1);
			comp = comp->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

/*
**	Collision check has 2 rounds.
**	The first round takes an arr which is paths->p and a path 'src'.
**	It loops through paths->p looking for the first path that has no
**	intersection with 'src'. Once it finds that, it gets added to
**	paths->c.
**	Round 2 is taking 'src' and checking for intersections in paths->c.
**	The reasoning for the if round == 1 and round == 2 is because
**	of the checking. In the first round, the loop returns as soon as
**	it finds a non-intersecting path. But for round 2, the criteria
**	for being added to paths->c is there cannot be any intersections
**	at all so it will need to loop through the entire array. For
**	example, if in round two an non intersecting path was found
**	at arr[0], the check would return 0. But since round == 2,
**	the return (0) isn't activated and the loop continues on.
*/

int			collision_check(t_bucket **arr, t_bucket *src,\
			t_entry *start, int round)
{
	t_bucket	*comp;
	t_bucket	*tmp;
	int			i;

	comp = NULL;
	tmp = src;
	i = 0;
	if (arr)
	{
		while (i < bucket_arr_len(arr))
		{
			if (!check_loop(arr, src, start, i))
			{
				if (round == 1)
					return (0);
			}
			else
			{
				if (round == 2)
					return (1);
			}
			i++;
		}
	}
	return (0);
}

void		collision_parse(t_paths *paths)
{
	t_bucket	*tmp;
	int			index;
	int			collision;
	t_entry		*start;

	tmp = NULL;
	index = 0;
	collision = 0;
	start = paths->s_room;
	while (index < bucket_arr_len(paths->p))
	{
		tmp = paths->p[index];
		if (!collision_check(paths->p, tmp, start, 1))
			if (!collision_check(paths->c, tmp, start, 2))
				paths->c = grow_chosen_array(paths, tmp);
		index++;
	}
}

void		choose_paths(t_master *master, t_paths *paths)
{
	if (!(paths->c = (t_bucket**)malloc(sizeof(t_bucket) * paths->c_len)))
		exit_malloc();
	init_paths(paths->c_len, paths->c);
	sort_chosen_paths(paths);
	collision_parse(paths);
	max_paths(paths);
	if (master->print_all_paths)
	{
		ft_printf("\nALL PATHS FOUND (END to START):\n");
		print_paths(paths->p);
	}
	if (master->print_chosen_paths)
	{
		ft_printf("\nCHOSEN PATHS FOR SOLUTION (END to START):\n");
		print_paths(paths->c);
	}
	calc_distribution(master, paths);
}
