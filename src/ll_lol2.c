/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_lol2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:42:58 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/13 14:44:50 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	append_to_ll(t_bucket **src, t_entry *entry)
{
	t_bucket	*tmp;

	tmp = *src;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_memalloc(sizeof(t_bucket));
	tmp->next->entry = entry;	
}