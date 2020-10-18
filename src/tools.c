/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:23:28 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/18 11:25:56 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		explored(t_entry *entry)
{
	int	i;

	i = 0;
	if (entry->link_arr)
	{
		while (i < link_array_len(entry->link_arr))
		{
			if (entry->visited == false)
				return (0);
			i++;
		}
	}
	return (1);
}