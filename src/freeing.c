/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:51:53 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/20 10:49:56 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_entry(t_entry *entry)
{
	int	i;

	i = 0;
	if (entry->name)
		ft_strdel(&entry->name);
	if (entry->comment)
		ft_strdel(&entry->comment);
	if (entry->link_arr)
	{
		while (i <= link_array_len(entry->link_arr))
		{
			entry->link_arr[i] = NULL;
			free(entry->link_arr[i]);
			i++;
		}
	}
	free(entry->link_arr);
	entry->visited = false;
	entry->name = NULL;
	entry->comment = NULL;
	entry->link_arr = NULL;
	entry->x = '\0';
	entry->y = '\0';
	entry->key = '\0';
	free(entry);
	entry = NULL;
}

void		free_bucket(t_bucket *bucket)
{
	bucket->entry = NULL;
	bucket->next = NULL;
	free(bucket);
	bucket = NULL;
}
