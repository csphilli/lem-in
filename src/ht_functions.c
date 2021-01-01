/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:24:25 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/01 17:16:22 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			hash(char *str)
{	
	int		hash_value;
	int		i;
	hash_value = 1;
	i = 0;
	while (*str)
	{
		hash_value += *str;
		hash_value = (hash_value * *str) % (TABLE_SIZE);
		str++;
	}
	return (hash_value);
}

t_entry		*get_entry(t_bucket **ht, t_master *master, char *name)
{
	t_bucket	*tmp;
	int			index;

	tmp = NULL;
	index = hash(name);
	tmp = ht[index];
	while (tmp)
	{
		if (ft_strequ(tmp->entry->name, name))
			return (tmp->entry);
		else if (!tmp->next && !ft_strequ(tmp->entry->name, name))
			ft_error("ERROR: Failed to insert link. Room not found.\n");
		tmp = tmp->next;
	}
	return (0);
}

t_bucket	*get_head(t_bucket **ht, char *name)
{
	t_bucket	*tmp;
	int			index;

	tmp = NULL;
	index = hash(name);
	tmp = ht[index];
	return (tmp);
}

void		assign_entry_to_ht(t_bucket **ht, t_master *master, t_entry *entry)
{
	size_t	index;
	
	index = hash(entry->name);
	insert_node(master, ht, entry, index);
	master->a_room = 1;
}
