/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:17:03 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/28 19:46:37 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	clear_room(t_room *room)
{
	room->index = '\0';
	room->key = '\0';
	ft_strdel(&room->name);
	room->links = NULL;
	room->next = NULL;
}

void	delete_ht(t_room **ht, t_master *master)
{
	size_t	i;
	t_room **tmp;
	t_room *head;
	t_room *curr;

	i = 0;
	tmp = ht;
	while (i < master->old_size)
	{
		if (tmp[i])
		{
			head = tmp[i];
			while (head->next)
			{
				curr = head;
				head = head->next;
				clear_room(curr);
				free(curr);
			}
			clear_room(head);
			free(head);
		}
		i++;
	}
	free(tmp);
}
