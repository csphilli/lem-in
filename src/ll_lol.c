/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_lol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 09:29:45 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/13 16:48:38 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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

void    unshift_ll(t_bucket **ll, t_entry *entry) // working, no leaks
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

void	pop_from_lol(t_lol **list) // working no leaks
{
	t_lol *head;
	t_lol *tmp;

	head = *list;
	tmp = head;
	if (!head->next)
	{
		free(head);
		head = NULL;
	}
	else
	{
		head = head->next;
		while (tmp->list)
			pop_from_ll(&tmp->list);
		free(tmp);
		tmp = NULL;
	}
	*list = head;
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

