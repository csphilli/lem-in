/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:20:56 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/24 15:02:42 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	append_or_insert_entry(t_bucket **ht, t_entry *entry, int index)
{
	t_bucket *new;
	t_bucket *tmp;

	tmp = ht[index];
	new = ft_memalloc(sizeof(t_bucket));
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
	new = ft_memalloc(sizeof(t_bucket));
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
		new = ft_memalloc(sizeof(t_bucket));
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

t_bucket	*insert_node_to_path(t_bucket *head, t_entry *node)
{
	t_bucket	*bucket;
	t_bucket	*tmp;

	tmp = NULL;
	bucket = ft_memalloc(sizeof(t_bucket));
	bucket->entry = node;
	if (head == NULL)
		head = bucket;
	else
	{
		tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = bucket;
	}
	return (head);
}

int		dupe(t_bucket **head, t_entry *entry)
{
	t_bucket *tmp;

	tmp = *head;
	while (tmp)
	{
		if (ft_strequ(entry->name, tmp->entry->name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
