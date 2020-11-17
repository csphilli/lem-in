/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lol_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:42:58 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/17 15:43:05 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	unshift_lol(t_lol **lol, t_bucket *ll) // working, no leaks.
{
	t_lol 	*head;
	t_lol	*tmp;

	head = *lol;
	tmp = head;
	if (head == NULL)
	{
		head = ft_memalloc(sizeof(t_lol));
		head->list = ll;
	}
	else
	{
		tmp = ft_memalloc(sizeof(t_lol));
		tmp->list = ll;
		tmp->next = head;
		head = tmp;
	}
	*lol = head;
}
void	pop_from_lol(t_lol **list) // working no leaks
{
	t_lol *head;
	t_lol *tmp;

	head = *list;
	tmp = head;
	if (head->next)
		head = head->next;
	while (tmp->list)
		pop_from_ll(&tmp->list);
	free(tmp);
	tmp = NULL;
	*list = head;
}

void	append_to_lol(t_lol **lol, t_bucket *ll) // working, no leaks.
{
	t_lol 	*head;
	t_lol	*tmp;

	head = *lol;
	tmp = head;
	if (head == NULL)
	{
		head = ft_memalloc(sizeof(t_lol));
		head->list = ll;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_memalloc(sizeof(t_lol));
		tmp->next->list = ll;
	}
	*lol = head;
}


