/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:20:56 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/28 19:21:25 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	unshift_node(t_room **ht, t_room *room, int index)
{
	t_room *tmp;
	tmp = room;
	tmp->next = ht[index];
	ht[index] = tmp;
}

void 	append_node(t_room **ht, t_room *room, int index)
{
	t_room *tmp;

	tmp = ht[index];
	if (tmp->next == NULL)
		tmp->next = room;
	else
	{
		while (tmp->next && (tmp->next->key <= room->key))
			tmp = tmp->next;
		if (tmp->next == NULL)
			tmp->next = room;
		else
		{
			room->next = tmp->next;
			tmp->next = room;
		}
	}
}

void	insert_node(t_room **ht, t_room *room, int index)
{
	if (ht[index] == NULL)
		ht[index] = room;
	else if (room->key < ht[index]->key)
		unshift_node(ht, room, index);
	else
		append_node(ht, room, index);
}
