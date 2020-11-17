/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_work2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:34:17 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/17 15:43:27 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		dupe(t_bucket **head, t_entry *entry)
{
	t_bucket *tmp;

	tmp = *head;
	while (tmp)
	{
		if (ft_strequ(entry->name, tmp->entry->name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

// void	dlt_dead_end(t_bucket **head)
// {
// 	ft_printf("Head start: %s\n", (*head)->entry->name);
// 	t_bucket *tmp;
// 	// t_bucket *cur;

// 	// cur = *head;
// 	tmp = *head;
// 	tmp = tmp->next;
// 	if (tmp->next)
// 		(*head)->next = tmp->next;
// 	else
// 		(*head)->next = NULL;
// 	ft_printf("deleting %s\n", tmp->entry->name);
// 	free_node(tmp);
// 	// *head = cur;
// 	ft_printf("Head end: %s\n", (*head)->entry->name);

// }