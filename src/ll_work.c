/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_work.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 09:29:45 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/22 01:48:05 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	pop_from_ll(t_bucket **ll)
{
	t_bucket *head;
	t_bucket *tmp;

	head = *ll;
	tmp = head;
	if (!head->next)
	{
		free(head);
		head = NULL;
	}
	else
	{
		head = tmp->next;
		tmp->entry = NULL;
		tmp->next = NULL;
		free(tmp);
		tmp = NULL;
	}
	*ll = head;
}

void	unshift_ll(t_bucket **ll, t_entry *entry)
{
	t_bucket	*tmp;
	t_bucket	*head;

	head = *ll;
	tmp = head;
	if (!head)
	{
		head = ft_memalloc(sizeof(t_bucket));
		head->entry = entry;
	}
	else
	{
		tmp = ft_memalloc(sizeof(t_bucket));
		tmp->entry = entry;
		tmp->next = head;
		head = tmp;
	}
	*ll = head;
}

void	insert_to_ll(t_bucket **src, t_entry *entry)
{
	t_bucket	*new;

	new = ft_memalloc(sizeof(t_bucket));
	new->entry = entry;
	if (*src == NULL)
		*src = new;
	else
	{
		new->next = *src;
		*src = new;
	}
}

void	append_to_ll(t_bucket **src, t_entry *entry)
{
	t_bucket	*tmp;
	t_bucket	*head;

	head = *src;
	tmp = head;
	if (head == NULL)
	{
		head = ft_memalloc(sizeof(t_bucket));
		head->entry = entry;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_memalloc(sizeof(t_bucket));
		tmp->next->entry = entry;
	}
	*src = head;
}

void	copy_ll(t_bucket **dst, t_bucket *src)
{
	t_bucket	*new;
	t_bucket	*tmp;

	new = NULL;
	tmp = src;
	while (tmp)
	{
		append_to_ll(&new, tmp->entry);
		tmp = tmp->next;
	}
	*dst = new;
}
