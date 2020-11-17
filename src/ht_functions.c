/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:24:25 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/17 13:45:52 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			gen_key(char *str)
{
	int		key;

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
	return (key);
}

t_entry	*get_entry(t_bucket **ht, t_master *master, char *name)
{
	t_bucket	*tmp;
	int			index;

	tmp = NULL;
	index = gen_key(name) % master->new_size;
	tmp = ht[index];
	while (tmp)
	{
		if (ft_strequ(tmp->entry->name, name))
			return (tmp->entry);
		else if (!tmp->next && !ft_strequ(tmp->entry->name, name))
			exit_room_not_found(name);
		tmp = tmp->next;
	}
	return (0);
}

t_bucket *get_head(t_bucket **ht, t_master *master, char *name)
{
	t_bucket	*tmp;
	int			index;

	tmp = NULL;
	index = gen_key(name) % master->new_size;
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
		insert_node(ht, entry, index);
		master->room_count++;
		master->nbr_keys++;
	}
	else
		exit_dup_coord(master);
}
