/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_lol2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:42:58 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/15 11:46:02 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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

void	copy_ll(t_bucket **dst, t_bucket *src)
{
	t_bucket 	*new;
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
