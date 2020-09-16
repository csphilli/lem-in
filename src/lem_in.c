/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 09:17:17 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/16 13:39:54 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	verify_input(t_master *master, int ac, char **av)
{
	int i;
	int flag_counter;

	i = 0;
	flag_counter = 0;
	if (ft_strchr(master->input_flags, 'f'))
		flag_counter++;
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
	capture_flags(master, ac, av);
	if (ac > 1)
	{
		verify_input(master, ac, av);
		parse_input(master, fd);
		
	}
	
	// exit_error(master, "nofile");
	// while (1)
	// {
		
	// }
	return (0);
	
}

