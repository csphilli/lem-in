/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:20:56 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/01 19:08:53 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		unshift_entry(t_bucket **head, t_entry *entry, int index)
{
	t_bucket	*new;
	t_bucket	*tmp;

	tmp = head[index];
	new = ft_memalloc(sizeof(t_bucket));
	new->entry = entry;
	head[index] = new;
	new->next = tmp;
}

void		dupe_chk(t_bucket *head, t_entry *entry)
{
	t_bucket *tmp;

	tmp = head;
	while (tmp)
	{
		if (ft_strequ(entry->name, tmp->entry->name))
			ft_errorExit("ERROR: Duplicate room found.\n");
		tmp = tmp->next;
	}
}

void		insert_node(t_master *master, t_bucket **ht,\
			t_entry *entry, int index)
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
		dupe_chk(ht[index], entry);
		unshift_entry(ht, entry, index);
	}
}
