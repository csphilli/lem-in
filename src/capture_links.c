/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 18:47:11 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/01 18:57:54 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_entry		**append_link(t_entry **link_arr, t_entry *entry)
{
	t_entry		**tmp;
	int			len;
	int			i;

	i = 0;
	len = link_array_len(link_arr);
	i = 0;
	len += 2;
	tmp = link_arr;
	if (!(link_arr = (t_entry**)malloc(sizeof(t_entry*) * (len))))
		exit_malloc();
	init_link_arr(link_arr, len);
	while (i < len - 2)
	{
		link_arr[i] = tmp[i];
		i++;
	}
	link_arr[i] = entry;
	free(tmp);
	tmp = NULL;
	return (link_arr);
}

void		insert_link(t_entry *entry, t_entry *link)
{
	if (!entry->link_arr)
	{
		if (!(entry->link_arr = (t_entry**)malloc(sizeof(t_entry*) * (2))))
			exit_malloc();
		init_link_arr(entry->link_arr, 2);
		entry->link_arr[0] = link;
	}
	else if (!link_exists(entry->link_arr, link))
		entry->link_arr = append_link(entry->link_arr, link);
}

int			is_room(t_bucket *head, char *room)
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

void		do_link(t_bucket *head, char *room, t_entry *link)
{
	t_bucket	*tmp;

	tmp = head;
	if (tmp && is_room(tmp, room))
	{
		while (tmp)
		{
			if (ft_strequ(tmp->entry->name, room))
			{
				insert_link(tmp->entry, link);
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

void		add_link_to_room(t_bucket **ht, t_master *master, char *line)
{
	char	**data;
	int		index;
	t_entry	*entry1;
	t_entry	*entry2;

	entry1 = NULL;
	entry2 = NULL;
	data = ft_strsplit(line, '-');
	entry1 = get_entry(ht, master, data[1]);
	entry2 = get_entry(ht, master, data[0]);
	if (entry1 == NULL)
		exit_room_not_found(data[1]);
	if (entry2 == NULL)
		exit_room_not_found(data[0]);
	if (entry1 && entry2)
	{
		index = gen_key(data[0]) % master->new_size;
		do_link(ht[index], data[0], entry1);
		index = gen_key(data[1]) % master->new_size;
		do_link(ht[index], data[1], entry2);
	}
	free_strsplit(&data);
	data = NULL;
}
