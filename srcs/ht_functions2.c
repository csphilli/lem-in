/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_functions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 12:38:17 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/24 18:45:50 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_bucket	**create_ht(t_master *master)
{
	t_bucket	**ht;
	size_t		i;

	i = 0;
	if (!(ht = ft_memalloc(sizeof(t_bucket) * (master->new_size + 1))))
		ft_error("Error. Failed to allocate memory for hash table.");
	while (i < master->new_size)
	{
		ht[i] = NULL;
		i++;
	}
	ht[i] = NULL;
	return (ht);
}

void		delete_old_ht(t_bucket **old, size_t size)
{
	size_t		i;
	t_bucket	*curr;
	t_bucket	*tmp;

	i = 0;
	while (i <= size)
	{
		if (old[i])
		{
			tmp = old[i];
			while (tmp)
			{
				curr = tmp;
				tmp = tmp->next;
				free_bucket(curr);
				curr = NULL;
			}
			free(tmp);
			tmp = NULL;
		}
		old[i] = NULL;
		i++;
	}
	free(old);
	old = NULL;
}

void		reassign_entry_to_ht(t_bucket **ht, t_master *master, t_entry *ptr)
{
	int		index;

	index = ptr->key % master->new_size;
	insert_node(ht, ptr, index);
	master->nbr_keys++;
	master->room_count++;
}

t_bucket	**realloc_ht(t_bucket **src, t_master *master)
{
	t_bucket	**new;
	t_bucket	**tmp;
	size_t		i;
	t_bucket	*curr;

	new = create_ht(master);
	tmp = src;
	i = 0;
	curr = NULL;
	while (i < master->old_size)
	{
		if (tmp[i] != NULL)
		{
			curr = tmp[i];
			while (curr)
			{
				reassign_entry_to_ht(new, master, curr->entry);
				curr = curr->next;
			}
		}
		i++;
	}
	delete_old_ht(src, master->old_size);
	return (new);
}

t_bucket	**grow_ht(t_bucket **ht, t_master *master)
{
	t_bucket **new;

	master->old_size = master->new_size;
	master->new_size *= master->size_factor;
	master->nbr_keys = 0;
	new = realloc_ht(ht, master);
	return (new);
}