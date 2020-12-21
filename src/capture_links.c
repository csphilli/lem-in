/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 18:47:11 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/21 12:34:28 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

// int		is_room(t_bucket *head, char *room)
// {
// 	t_bucket	*tmp;

// 	tmp = head;
// 	while (tmp)
// 	{
// 		if (ft_strequ(tmp->entry->name, room))
// 			return (1);
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }

// void	eval_links(t_bucket **src, t_entry *entry)
// {
// 	t_bucket	*tmp;

// 	tmp = *src;
// 	if (!dupe(tmp, entry))
// 	{
// 		if (*src == NULL || entry->x < (*src)->entry->x)
// 			insert_to_ll(src, entry);
// 		else
// 			append_to_ll(src, entry);
// 	}
// }

// void	do_link(t_master *master, t_bucket *head, char *room, t_entry *link)
// {
// 	t_bucket	*tmp;

// 	tmp = head;
// 	if (tmp && is_room(tmp, room))
// 	{
// 		while (tmp)
// 		{
// 			if (ft_strequ(tmp->entry->name, room))
// 			{
// 				eval_links(&tmp->entry->links, link);
// 				break ;
// 			}
// 			else if (!ft_strequ(tmp->entry->name, room) && !tmp->next)
// 				exit_room_not_found(master, room);
// 			tmp = tmp->next;
// 		}
// 	}
// 	else
// 		exit_room_not_found(master, room);
// }

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

int		dupe_link(t_entry *src, t_entry *add)
{
	t_bucket *tmp;

	tmp = src->links;
	if (!tmp)
		return (0);
	while (tmp)
	{
		if (ft_strequ(tmp->entry->name, add->name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	capture_links(t_bucket **ht, t_master *master, char *line)
{
	char	**data;
	int		index;
	t_entry	*entry;
	int		i;
	int		j;

	i = 0;
	j = 1;
	chk_link_format(master, line);
	data = ft_strsplit(line, '-');
	while (i < 2)
	{
		entry = get_entry(ht, master, data[i]);
		index = hash(entry->name);
		if (!(dupe_link(entry, get_entry(ht, master, data[j]))))
			insert_to_ll(&entry->links, get_entry(ht, master, data[j]));
		i++;
		j--;		
	}
	master->link = 1;
	free_strsplit(&data);
	data = NULL;
}

