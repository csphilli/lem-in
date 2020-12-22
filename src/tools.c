/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:23:28 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/22 11:34:58 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	start_or_end(t_master *master, t_entry *entry)
{
	if (ft_strequ(entry->comment, "start"))
		master->start_room = entry;
	else if (ft_strequ(entry->comment, "end"))
		master->end_room = entry;
}

int		bucket_arr_len(t_bucket **arr)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (arr[i++])
		len++;
	return (len);
}

int		list_length(t_bucket *head)
{
	t_bucket	*tmp;
	int			len;

	tmp = head;
	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
