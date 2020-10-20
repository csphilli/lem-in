/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:23:28 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/19 22:53:08 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
**	'explored' checks to see if a particular entry is fulled explored. It is
**	considered fully explored when every link in the entry's link
**	array have been flagged as visited.
*/

void	check_first(t_entry *entry)
{
	int i;

	i = 0;
	while (i < link_array_len(entry->link_arr))
	{
		ft_printf("%s = ", entry->link_arr[i]->name);
		if (entry->link_arr[i]->visited == true)
			ft_printf("visited\n");
		else
			ft_printf("unvisited\n");		
		i++;
	}
}

int		explored(t_entry *entry)
{
	int	i;

	i = 0;
	if (entry->link_arr)
	{
		// check_first(entry);
		i = 0;
		while (i < link_array_len(entry->link_arr))
		{
			if (entry->link_arr[i]->visited == false)
				return (0);
			i++;
		}
	}
	return (1);
}

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
	while (i < master->new_size)
	{
		if(ht[i])
		{
			tmp = ht[i];
			while (tmp)
			{
				if ((link_array_len(tmp->entry->link_arr) == 1) && \
					(!ft_strequ(tmp->entry->name, master->start_room)))
					tmp->entry->visited = true;
				tmp = tmp->next;
			}
		}
		i++;
	}
}

void	clear_visited(t_master *master, t_bucket **ht)
{
	t_bucket	**tmp;
	t_bucket	*curr;
	int			i;

	i = 0;
	tmp = ht;
	curr = NULL;
	while (tmp[i])
	{
		if (tmp[i])
		{
			curr = tmp[i];
			while (curr)
			{
				ft_printf(" Clearing %s\n", curr->entry->name);
				if (!ft_strequ(curr->entry->name, master->end_room))
					curr->entry->visited = false;
				curr = curr->next;
			}
		}
		i++;
	}
}

/*
**	Used for the pathing algo, this simply adds the name of the start
**	and end room to the master struct for later reference.
*/

void		start_or_end(char *s, t_master *master, char *name)
{
	if (ft_strequ(s, "start"))
		master->start_room = ft_strdup(name);
	else if (ft_strequ(s, "end"))
		master->end_room = ft_strdup(name);
}

/*
**	Calculates the length of an array of pointers to pointers
*/

int			bucket_arr_len(t_bucket **arr)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (arr[i++])
		len++;
	return (len);
}