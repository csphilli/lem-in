/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:18:02 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/02 22:55:28 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		validate_input(t_master *master)
{
	if (master->ants_added == true &&\
		master->start_room &&\
		master->end_room &&\
		master->link)
		return (1);
	else
		master->errors ? \
		ft_error("ERROR: Insufficient information provided.") :\
		ft_error("ERROR");
	return (0);
}
