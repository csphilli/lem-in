/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lol_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:42:58 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/22 01:48:05 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	unshift_lol(t_lol **lol, t_bucket *ll)
{
	t_lol	*head;
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

void	pop_from_lol(t_lol **list)
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

void	append_to_lol(t_lol **lol, t_bucket *ll)
{
	t_lol	*head;
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

int		lol_length(t_lol *lol)
{
	t_lol	*tmp;
	int		i;

	tmp = lol;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	insert_to_lol(t_lol **lol, t_bucket *ll)
{
	t_lol	*head;
	t_lol	*tmp;
	t_lol	*new;
	int		l;

	head = *lol;
	tmp = head;
	new = NULL;
	l = list_length(ll);
	if (head == NULL || list_length(ll) < list_length(head->list))
		unshift_lol(&head, ll);
	else
	{
		new = ft_memalloc(sizeof(t_lol));
		new->list = ll;
		while (tmp->next && (l > list_length(tmp->list) \
			&& l >= list_length(tmp->next->list)))
			tmp = tmp->next;
		new->next = tmp->next;
		tmp->next = new;
	}
	*lol = head;
}
