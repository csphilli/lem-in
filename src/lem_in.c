/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 09:17:17 by cphillip          #+#    #+#             */
/*   Updated: 2020/08/31 13:22:52 by cphillip         ###   ########.fr       */
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
	if (ac > 0)
	{
		// parse_flags(master, av);
		// ft_printf("ac: %d\n", ac);
		ac--;
		while (ac > 0)
		{
			capture_flags(master, av[ac]);
			ac--;
		}
		// ft_printf("ac 0: %s", av[0]);
		parsing(master, fd);
	}
	else
		ft_printf("Error: No file specified\n");
	return (0);
}

