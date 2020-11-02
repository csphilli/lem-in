/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_work2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:34:17 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/02 15:48:30 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		dupe(t_bucket *head, t_entry *entry)
{
	t_bucket *tmp;

	tmp = head;
	while (tmp)
	{
		if (ft_strequ(entry->name, tmp->entry->name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_bucket	*unshift_from_list(t_bucket *head)
{
	t_bucket *tmp;

	tmp = head;
	if (tmp->next)
		tmp = tmp->next;
	else
		tmp = NULL;
	// free_entry(head->entry);
	free_bucket(head);
	head = tmp;
	return (head);
}

t_bucket	*append_to_list_no_dupe(t_bucket *head, t_entry *node)
{
	t_bucket	*bucket;
	t_entry		*entry;
	t_bucket	*tmp;

	tmp = NULL;
	if (!dupe(head, node))
	{
		entry = node;
		bucket = create_bucket();
		bucket->entry = entry;
		if (head == NULL)
			head = bucket;
		else
		{
			tmp = head;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = bucket;
		}
	}
	return (head);
}

