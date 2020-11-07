/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:51:53 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/07 13:10:25 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_node(t_bucket *node)
{
	free_entry(node->entry);
	free_bucket(node);
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

void	free_bucket(t_bucket *bucket)
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

void	free_ant_instrux(t_ant_instrux *ins)
{
	ft_init_int_arr(ins->ant_arr, ft_int_arr_len(ins->ant_arr));
	free(ins->ant_arr);
	ins->ant_arr = NULL;
	ft_init_int_arr(ins->moves_arr, ft_int_arr_len(ins->moves_arr));
	free(ins->moves_arr);
	ins->moves_arr = NULL;
	ins->max_index = 0;
	ins->n_ants = 0;
	free(ins);
	ins = NULL;
}