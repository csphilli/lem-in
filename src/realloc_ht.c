/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_ht.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:18:44 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/05 14:45:56 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

// static void	clear_entry(t_entry *entry)
// {
// 	ft_strdel(&entry->name);
// 	if (entry->comment)
// 		ft_strdel(&entry->comment);
// 	entry->key = '\0';
// 	entry->x = '\0';
// 	entry->y = '\0';
// }

void	delete_old_ht(t_bucket **old, size_t size)
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
				curr->entry = NULL;
				curr->next = NULL;
				free(curr);
				curr = NULL;
				
			}
			free(tmp);
			tmp = NULL;
		}
		// free(old[i]);
		old[i] = NULL;
		i++;
	}
	free(old);
	old = NULL;
}

static void reassign_entry_to_ht(t_bucket **ht, t_master *master, t_entry *ptr)
{
	int		index;

	index = ptr->key % master->new_size;
	insert_node(ht, ptr, index);
	master->nbr_keys++;
	master->room_count++;
}

static t_bucket 	**realloc_ht(t_bucket **src, t_master *master)
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
	// ft_printf("master->new_size: %d\n", master->new_size);
	return (new);
}

t_bucket 	**grow_ht(t_bucket **ht, t_master *master)
{
	t_bucket **new;

	master->old_size = master->new_size;
	master->new_size *= 2;
	master->nbr_keys = 0;
	new = realloc_ht(ht, master);
	// print_ht(new, master->new_size);
	return (new);
}



