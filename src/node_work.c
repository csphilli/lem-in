/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:20:56 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/07 10:52:32 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	append_or_insert_entry(t_bucket **ht, t_entry *entry, int index)
{
	t_bucket *new;
	t_bucket *tmp;

	tmp = ht[index];
	new = create_bucket();
	new->entry = entry;
	while (tmp->next != NULL)
	{
		if (tmp && entry->key >= tmp->next->entry->key)
			tmp = tmp->next;
		else
			break ;
	}
	if (tmp->next == NULL)
		tmp->next = new;
	else
	{
		new->next = tmp->next;
		tmp->next = new;
	}
}

static void	unshift_entry(t_bucket **head, t_entry *entry, int index)
{
	t_bucket	*new;
	t_bucket	*tmp;

	tmp = head[index];
	new = create_bucket();
	new->entry = entry;
	head[index] = new;
	new->next = tmp;
}

void		insert_node(t_bucket **ht, t_entry *entry, int index)
{
	t_bucket	*new;

	new = NULL;
	if (ht[index] == NULL)
	{
		new = create_bucket();
		new->entry = entry;
		ht[index] = new;
	}
	else
	{
		if (entry->key < ht[index]->entry->key)
			unshift_entry(ht, entry, index);
		else
			append_or_insert_entry(ht, entry, index);
	}
}
