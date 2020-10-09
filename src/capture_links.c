/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 18:47:11 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/09 18:49:32 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		link_exists(char **arr, char *link)
{
	int	i;

	i = 0;
	if (arr[i])
	{
		while (arr[i])
		{
			if (ft_strequ(arr[i], link))
				return (1);
			i++;
		}
	}
	return (0);
}

void	add_link(t_entry *entry, char *link)
{
	char	**tmp;
	char	**new;
	int		len;

	tmp = NULL;
	new = NULL;
	len = 0;
	if (!entry->link_arr)
	{
		// if (!(entry->link_arr = (char**)malloc(sizeof(char*) * (2))))
		// 	exit_malloc();
		// ft_init_arr(entry->link_arr, 2);
		// entry->link_arr[0] = ft_strdup(link);
		entry->link_arr = ft_arrcat(entry->link_arr, link);
	}
	else
	{
		tmp = entry->link_arr;
		if (!link_exists(entry->link_arr, link))
			entry->link_arr = ft_arrcat(entry->link_arr, link);
		free_strsplit(&tmp);
		free(tmp);
		tmp = NULL;
	}
}

int		is_room(t_bucket *head, char *room)
{
	t_bucket	*tmp;

	tmp = head;
	while (tmp)
	{
		if (ft_strequ(tmp->entry->name, room))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	do_link(t_bucket *head, char *room, char *link)
{
	t_bucket	*tmp;

	tmp = head;
	if (tmp && is_room(tmp, room))
	{
		while (tmp)
		{
			if (ft_strequ(tmp->entry->name, room))
			{
				add_link(tmp->entry, link);
				break ;
			}
			else if (!ft_strequ(tmp->entry->name, room) && !tmp->next)
				exit_room_not_found(room);
			tmp = tmp->next;
		}
	}
	else
		exit_room_not_found(room);
}

void	add_link_to_room(t_bucket **ht, t_master *master, char *line)
{
	char	**data;
	int		index;

	data = ft_strsplit(line, '-');
	index = gen_key(data[0]) % master->new_size;
	do_link(ht[index], data[0], data[1]);
	index = gen_key(data[1]) % master->new_size;
	do_link(ht[index], data[1], data[0]);
	free_strsplit(&data);
	data = NULL;
}
