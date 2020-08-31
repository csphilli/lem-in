/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 11:01:49 by cphillip          #+#    #+#             */
/*   Updated: 2020/08/31 12:13:21 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	capture_flags(t_master *master, char *av)
{
	ft_printf("inside capture flags\n");
	ft_printf("av[1]: %s\n", (av + 1));
	if (ft_strstr("e", (av + 1)))
	{
		if (ft_strequ(av, "-e"))
			master->a_errors = 1;
	}
	else // need proper error management handling to exit code.
		ft_printf("Error: Invalid flag. Type <./lem-in -h> for list of options\n"); // need highlighting on error text	
}