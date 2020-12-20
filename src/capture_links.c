/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 18:47:11 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/20 20:48:44 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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

void	eval_links(t_bucket **src, t_entry *entry)
{
	t_bucket	*tmp;

	tmp = *src;
	if (!dupe(tmp, entry))
	{
		if (*src == NULL || entry->x < (*src)->entry->x)
			insert_to_ll(src, entry);
		else
			append_to_ll(src, entry);
	}
}

void	do_link(t_master *master, t_bucket *head, char *room, t_entry *link)
{
	t_bucket	*tmp;

	tmp = head;
	if (tmp && is_room(tmp, room))
	{
		while (tmp)
		{
			if (ft_strequ(tmp->entry->name, room))
			{
				eval_links(&tmp->entry->links, link);
				break ;
			}
			else if (!ft_strequ(tmp->entry->name, room) && !tmp->next)
				exit_room_not_found(master, room);
			tmp = tmp->next;
		}
	}
	else
		exit_room_not_found(master, room);
}

void	chk_link_format(t_master *master, char *line)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '-')
			x++;
		i++;
	}
	if (x > 1)
		master->errors ? ft_error("ERROR: Invalid link format.") :\
		ft_error("ERROR");
}

void	capture_links(t_bucket **ht, t_master *master, char *line)
{
	char	**data;
	int		index;
	t_entry	*entry1;
	t_entry	*entry2;

	entry1 = NULL;
	entry2 = NULL;
	chk_link_format(master, line);
	data = ft_strsplit(line, '-');
	entry1 = get_entry(ht, master, data[1]);
	entry2 = get_entry(ht, master, data[0]);
	if (!entry1)
		exit_room_not_found(master, data[1]);
	if (!entry2)
		exit_room_not_found(master, data[0]);
	if (entry1 && entry2)
	{
		index = hash(data[0]);// % master->new_size;
		do_link(master, ht[index], data[0], entry1);
		index = hash(data[1]);// % master->new_size;
		do_link(master, ht[index], data[1], entry2);
	}
	free_strsplit(&data);
	master->link = 1;
	data = NULL;
}
