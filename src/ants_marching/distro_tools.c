/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distro_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:42:58 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/01 22:08:48 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	unshift_distro(t_distro **distro, t_bucket *ll)
{
	t_distro	*head;
	t_distro	*tmp;

	head = *distro;
	tmp = head;
	if (head == NULL)
	{
		head = ft_memalloc(sizeof(t_distro));
		head->list = ll;
	}
	else
	{
		tmp = ft_memalloc(sizeof(t_distro));
		tmp->list = ll;
		tmp->next = head;
		head = tmp;
	}
	*distro = head;
}

void	pop_from_distro(t_distro **list)
{
	t_distro *head;
	t_distro *tmp;

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

void	append_to_distro(t_distro **distro, t_bucket *ll)
{
	t_distro	*head;
	t_distro	*tmp;

	head = *distro;
	tmp = head;
	if (head == NULL)
	{
		head = ft_memalloc(sizeof(t_distro));
		head->list = ll;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_memalloc(sizeof(t_distro));
		tmp->next->list = ll;
	}
	*distro = head;
}

int		distro_length(t_distro *distro)
{
	t_distro	*tmp;
	int			i;

	tmp = distro;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	insert_to_distro(t_distro **distro, t_bucket *ll)
{
	t_distro	*head;
	t_distro	*tmp;
	t_distro	*new;
	int			l;

	head = *distro;
	tmp = head;
	new = NULL;
	l = list_length(ll);
	if (head == NULL || list_length(ll) < list_length(head->list))
		unshift_distro(&head, ll);
	else
	{
		new = ft_memalloc(sizeof(t_distro));
		new->list = ll;
		while (tmp->next && (l > list_length(tmp->list) \
			&& l >= list_length(tmp->next->list)))
			tmp = tmp->next;
		new->next = tmp->next;
		tmp->next = new;
	}
	*distro = head;
}
