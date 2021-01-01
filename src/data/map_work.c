/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:21:11 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/22 01:48:05 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	unshift_to_map(t_pmap **map, t_entry *found, t_entry *via)
{
	t_pmap	*head;
	t_pmap	*new;

	head = *map;
	new = ft_memalloc(sizeof(t_pmap));
	new->fnd = found;
	new->via = via;
	if (head == NULL)
		head = new;
	else
	{
		new->next = head;
		head = new;
	}
	*map = head;
}

void	pop_from_map(t_pmap **map)
{
	t_pmap *tmp;
	t_pmap *head;

	head = *map;
	tmp = head;
	if (!head->next)
	{
		free(head);
		head = NULL;
	}
	else
	{
		head = head->next;
		free(tmp);
		tmp = NULL;
	}
	*map = head;
}
