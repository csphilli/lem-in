/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:23:28 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/19 07:36:13 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
**	'explored' checks to see if a particular entry is fulled explored. It is
**	considered fully explored when every link in the entry's link
**	array have been flagged as visited.
*/

int		explored(t_entry *entry)
{
	int	i;

	i = 0;
	if (entry->link_arr)
	{
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
**	Checks to see if the entry in question is a dead-end room.
**	A dead end room is a room with only 1 link in the link array of which
**	that link will always be the link back to the room it just came from.
**	If the entry in question is the final destination, it is not considered
**	a dead-end room.
*/

int		dead_end(t_master *master, t_entry *entry)
{
	if ((link_array_len(entry->link_arr) == 1) && \
		(!ft_strequ(entry->name, master->start_room)))
		return (1);
	else
		return (0);
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