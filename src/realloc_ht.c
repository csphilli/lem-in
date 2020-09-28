/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_ht.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:18:44 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/28 19:50:29 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room 	**realloc_ht(t_room **src, t_master *master)
{
	t_room	**new;
	t_room	*tmp;
	size_t	i;
	new = create_ht(master);
	i = 0;
	while (i < master->old_size)
	{
		if (src[i])
		{
			tmp = src[i];
			while (tmp)
			{
				insert_into_ht(new, master, tmp->name);
				tmp = tmp->next;			
			}
		}
		i++;
	}
	delete_ht(src, master);
	return (new);
}

t_room 	**grow_ht(t_room **ht, t_master *master)
{
	t_room **new;

	master->old_size = master->new_size;
	master->new_size *= 2;
	master->nbr_keys = 0;
	new = realloc_ht(ht, master);
	return (new);
}

t_room 	**create_ht(t_master *master)
{
	t_room	**ht;
	size_t	i;

	i = 0;
	if (!(ht = (t_room**)malloc(sizeof(t_room*) * (master->new_size + 1))))
		exit_malloc();
	while (i <= master->new_size)
		ht[i++] = NULL;
	return (ht);
}
