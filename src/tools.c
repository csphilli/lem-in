/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:23:28 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/12 15:07:32 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
**	dead_end_scan is a scan made prior to checking for paths.
**	It's purpose is to flag any room that is a dead end as visited.
**	This prevents any unnecessary checking in rooms that won't
**	help the objective of the program. A dead end is a room that
**	contains only one link. If that link is not the starting room,
**	it gets flagged.
*/

void	dead_end_scan(t_master *master, t_bucket **ht)
{
	size_t		i;
	t_bucket	*tmp;

	i = 0;
	tmp = NULL;
	while (i++ < master->new_size)
	{
		if (ht[i])
		{
			tmp = ht[i];
			while (tmp)
			{
				if (tmp->entry->link_arr)
				{
					if ((link_array_len(tmp->entry->link_arr) == 1) && \
						(!ft_strequ(tmp->entry->name, master->start_room) && \
						!ft_strequ(tmp->entry->name, master->end_room)))
						tmp->entry->no = true;
				}
				else if (!tmp->entry->link_arr)
					tmp->entry->no = true;
				tmp = tmp->next;
			}
		}
	}
}

/*
**	Used for the pathing algo, this simply adds the name of the start
**	and end room to the master struct for later reference.
*/

void	start_or_end(char *s, t_master *master, char *name)
{
	if (ft_strequ(s, "start"))
		master->start_room = ft_strdup(name);
	else if (ft_strequ(s, "end"))
		master->end_room = ft_strdup(name);
}

/*
**	Calculates the length of an array of pointers to pointers
*/

int		bucket_arr_len(t_bucket **arr)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (arr[i++])
		len++;
	return (len);
}

void	max_paths(t_paths *paths) // Might not need.
{
	int	start_paths;
	int	end_paths;

	start_paths = link_array_len(paths->s_room->link_arr);
	end_paths = link_array_len(paths->e_room->link_arr);
	ft_printf("start paths: %d | end paths: %d\n", start_paths, end_paths);
	if (start_paths < end_paths)
		paths->max_paths = start_paths;
	else if (start_paths > end_paths)
		paths->max_paths = end_paths;
	else if (start_paths == end_paths)
		paths->max_paths = start_paths;
}

int		list_length(t_bucket *head)
{
	t_bucket	*tmp;
	int			len;

	tmp = head;
	len = 1;
	while (tmp->next)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
