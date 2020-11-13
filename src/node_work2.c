/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_work2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:34:17 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/13 17:07:13 by cphillip         ###   ########.fr       */
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

void	pop_bfsq(t_bfs *bfs)
{
	t_bucket *tmp;
	t_bucket *head;

	tmp = bfs->bfsq;
	if (tmp->next)
	{
		head = tmp->next;
		free_node(tmp);
		bfs->bfsq = head;
	}
	else
	{	
		free_node(bfs->bfsq);
		bfs->bfsq = NULL;
	}
}


// void	append_to_bfsq(t_bfs *bfs, t_entry *node)
// {
// 	// t_entry		*entry;
// 	t_bucket	*tmp;
// 	t_bucket	*head;

// 	head = bfs->bfsq;
// 	tmp = NULL;
// 	if (!dupe(&head, node))
// 	{
// 		// entry = copy_entry(node);
// 		if (head == NULL)
// 		{
// 			head = ft_memalloc(sizeof(t_bucket));
// 			// head->entry = entry;
// 			head->entry = node;
// 		}
// 		else
// 		{
// 			tmp = head;
// 			while (tmp->next)
// 				tmp = tmp->next;
// 			tmp->next = ft_memalloc(sizeof(t_bucket));
// 			// tmp->next->entry = entry;
// 			tmp->next->entry = node;
// 		}
// 		bfs->bfsq = head;
// 	}
// }

// void	append_to_bfs(t_bfs *bfs, t_entry *node)
// {
// 	// t_entry		*entry;
// 	t_bucket	*tmp;
// 	t_bucket	*head;

// 	head = bfs->bfs;
// 	tmp = NULL;
// 	if (!dupe(head, node))
// 	{
// 		// entry = copy_entry(node);		
// 		if (head == NULL)
// 		{
// 			head = ft_memalloc(sizeof(t_bucket));
// 			// head->entry = entry;
// 			head->entry = node;
// 		}
// 		else
// 		{
// 			tmp = head;
// 			while (tmp->next)
// 				tmp = tmp->next;
// 			tmp->next = ft_memalloc(sizeof(t_bucket));
// 			// tmp->next->entry = entry;
// 			tmp->next->entry = node;
// 		}
// 	}
// 	bfs->bfs = head;
// }
