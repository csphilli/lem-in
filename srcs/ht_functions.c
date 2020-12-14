/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:24:25 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/14 21:09:18 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			hash(char *str)
{

	
	int		key;
	int		i;
	key = 0;
	i = 0;
	while (*str)
	{
		key += *str << i++;
		str++;
		// i++;
		// i = (i == 3 ? 1 : i);
	}

	/*
	key = 0;
	while (*str)
	{
		if (*str >= (0 + '0') && *str <= (9 + '0'))
			key += (*str - 48);
		else if (*str >= 'a' && *str <= 'z')
			key += *str;
		else if (*str >= 'A' && *str <= 'Z')
			key += *str;
		str++;
	}
	*/
	return (key);
}

t_entry		*get_entry(t_bucket **ht, t_master *master, char *name)
{
	t_bucket	*tmp;
	int			index;

	tmp = NULL;
	index = hash(name) % master->new_size;
	tmp = ht[index];
	while (tmp)
	{
		if (ft_strequ(tmp->entry->name, name))
			return (tmp->entry);
		else if (!tmp->next && !ft_strequ(tmp->entry->name, name))
			exit_room_not_found(master, name);
		tmp = tmp->next;
	}
	return (0);
}

t_bucket	*get_head(t_bucket **ht, t_master *master, char *name)
{
	t_bucket	*tmp;
	int			index;

	tmp = NULL;
	index = hash(name) % master->new_size;
	tmp = ht[index];
	return (tmp);
}

float		load(t_master *master)
{
	float res;

	res = (float)master->nbr_keys / (float)master->new_size;
	return (res);
}

void		assign_entry_to_ht(t_bucket **ht, t_master *master, t_entry *entry)
{
	size_t	index;

	if (!dup_coord(ht, master, entry))
	{
		index = entry->key % master->new_size;
		insert_node(master, ht, entry, index);
		master->room_count++;
		master->nbr_keys++;
	}
	else
		exit_dup_coord(master);
}
