/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:18:02 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/31 15:16:02 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//update this to include a different error for each missing flag
int		validate_input(t_master *master)
{
	if (master->flags.ants_added == true &&\
		master->start_room &&\
		master->end_room &&\
		master->link)
		return (1);
	else
		master->flags.errors ? \
		ft_error("ERROR: Insufficient information provided.") :\
		ft_error("ERROR");
	return (0);
}
