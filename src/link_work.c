/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 13:27:53 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/12 08:32:45 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		link_exists(t_entry **link_arr, t_entry *link)
{
	int	i;

	i = 0;
	while (link_arr[i] != NULL)
	{
		if (ft_strequ(link_arr[i]->name, link->name))
			return (1);
		i++;
	}
	return (0);
}

int		link_array_len(t_entry **arr)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (arr[i++])
		len++;
	return (len);
}

t_entry	*get_entry(t_bucket **ht, t_master *master, char *name)
{
	t_bucket	*tmp;
	int			index;

	tmp = NULL;
	index = gen_key(name) % master->new_size;
	tmp = ht[index];
	while (tmp)
	{
		if (ft_strequ(tmp->entry->name, name))
			return (tmp->entry);
		else if (!tmp->next && !ft_strequ(tmp->entry->name, name))
			exit_room_not_found(name);
		tmp = tmp->next;
	}
	return (0);
}
