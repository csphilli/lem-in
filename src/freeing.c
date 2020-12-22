/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:51:53 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/22 01:48:05 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_node(t_bucket *node)
{
	free_entry(node->entry);
	free_bucket(node);
	node = NULL;
}

void	free_entry(t_entry *entry)
{
	int	i;

	i = 0;
	if (entry->name)
		ft_strdel(&entry->name);
	if (entry->comment)
		ft_strdel(&entry->comment);
	while (entry->links)
		pop_from_ll(&entry->links);
	entry->links = NULL;
	free(entry);
	entry = NULL;
}

void	free_bucket(t_bucket *bucket)
{
	bucket->entry = NULL;
	bucket->next = NULL;
	free(bucket);
	bucket = NULL;
}
