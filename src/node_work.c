/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:20:56 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/03 15:06:39 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_bucket	*find_next(t_bucket *bucket, int key)
{
	t_bucket *tmp;

	tmp = bucket;
	while (tmp->entry)
	{
		if (tmp->next && key >= tmp->next->entry->key)
			tmp = tmp->next;
		else
			break ;
	}
	return (tmp);
}

static void	chain_entry(t_bucket *head, t_bucket *new)
{
	t_bucket 	*tmp;
	t_bucket	*curr;

	tmp = NULL;
	curr = NULL;
	if (new->entry->key < head->entry->key)
	{
		new->next = head;
		head = new;
	}
	else
	{
		curr = find_next(head, new->entry->key);
		if (curr->next == NULL)
			curr->next = new;
		else
		{
			tmp = curr->next;
			curr->next = new;
			new->next = tmp;
		}		
	}
}

void		insert_node(t_bucket **ht, t_entry *entry, int index)
{
	t_bucket	*new;

	new = NULL;
	if (ht[index]->entry == NULL)
		ht[index]->entry = entry;
	else
	{
		new = create_bucket();
		new->entry = entry;
		ft_printf("New->name: %s | new->key: %d\n", new->entry->name, new->entry->key);
		chain_entry(ht[index], new);
	}
}
