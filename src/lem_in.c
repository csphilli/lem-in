/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 09:17:17 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/02 19:33:43 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	main(int ac, char **av)
{
	t_master	*master;
	int			fd;

	fd = 0;
	if (!(master = (t_master*)malloc(sizeof(t_master))))
		return (0);
	init_master(master);
	capture_flags(master, ac, av);
	if (ac > 0)
	{				
		// while (--ac > 0)
		// {
		// ft_printf("av[%d]: %s\n", ac - 1, av[ac - 1]);
		// 	capture_flags(master, av[ac]);
		// 	// ac--;
		// }
		// ft_printf("av[0]: %s\n", av[0]);
		parsing(master, fd);
	}
	else
		ft_printf("File:"RED" %s "RESET"not found.\n", av[1]);
	while (1)
	{
		
	}
	return (0);
	
}

