/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distro_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:42:58 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/02 11:50:33 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
