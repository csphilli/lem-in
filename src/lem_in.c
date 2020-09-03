/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 09:17:17 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/03 14:14:45 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	verify_input(int ac, char **av)
{
	int i;
	int flag_counter;

	i = 0;
	flag_counter = 0;
	while (av[i])
		if (av[i++][0] == '-')
			flag_counter++;
	if (flag_counter + 1 != ac)
	{
		ft_printf("Error: Invalid Usage. Type "CYAN"./lem-in -h"RESET" for assistance\n");
		exit(-1);
	}
	// Need to add error mgmt
}

int	main(int ac, char **av)
{
	t_master	*master;
	int			i;
	int			fd;

	fd = 0;
	i = 1;
	if (!(master = (t_master*)malloc(sizeof(t_master))))
		return (0);
	init_master(master);
	
	ft_printf("ac: %d\n", ac);
	
	if (ac > 1)
		capture_flags(master, ac, av);
	verify_input(ac, av);
		// capture_flags(master, ac, av);
	
	// parsing(master, );
	parse_input(master, fd);
	// while (1)
	// {
		
	// }
	return (0);
	
}

