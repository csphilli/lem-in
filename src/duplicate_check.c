/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:08:25 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/24 10:35:01 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** DUPLICATE ROOM NAME CHECKER
** A very simple duplicate checker. Since I'm using a linear hash storage
** function, if the index keys are the same, there are one of two things
** happening. 1) The room name integar total is the same but the names
** are unique or 2) The names are not unique. In the case of nbr1, rooms
** 'end' and 'den' have the same int value but are unique. When
** the hash function encounters the same int total, it indexes to the next
** index and attempts to store it there. When it encounters the same total
** it performs this check.
*/

void	duplicate_check(t_master *master, char *s1, char *s2)
{
	if (*s1 && *s2)
	{
		if (ft_strcmp(s1, s2) == 0)
			exit_error(master, "duplicate");
	}
}
