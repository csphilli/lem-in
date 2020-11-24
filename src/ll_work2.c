/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_work2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:20:36 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/24 20:16:21 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	reverse_ll(t_bucket **new, t_bucket *list)
{
	t_bucket	*tmp;

	tmp = list;
	while (tmp)
	{
		unshift_ll(new, tmp->entry);
		tmp = tmp->next;
	}
	*new = tmp;
}
