/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:51:53 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/20 18:18:22 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	pop_from_list(t_bucket *head)
{
	t_bucket 	*tmp;

	tmp = head;
	while (tmp->next->next)
		tmp = tmp->next;
	free_entry(tmp->next->entry);
	free_bucket(tmp->next);
	tmp->next = NULL;
}

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
		while (i < link_array_len(entry->link_arr))
		{
			entry->link_arr[i] = NULL;
			free(entry->link_arr[i]);
			i++;
		}
	}
	free(entry->link_arr);
	
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

void	delete_old_path(t_bucket **paths)
{
	t_bucket	**tmp;
	t_bucket	*curr;
	t_bucket	*hold;
	int			i;

	tmp = paths;
	i = 0;
	hold = NULL;
	while (i < bucket_arr_len(paths))
	{
		if (tmp[i])
		{
			curr = tmp[i];
			while (curr)
			{
				hold = curr;
				curr = curr->next;
				free_entry(hold->entry);
				free_bucket(hold);
			}
		}
		i++;
	}
	free(paths);
	paths = NULL;
}
