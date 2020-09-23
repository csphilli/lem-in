/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 09:17:17 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/23 08:41:19 by cphillip         ###   ########.fr       */
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
}





int	main(int ac, char **av)
{
	t_master	*master;
	t_room		*ht[HT_SIZE];
	
	int			i;
	int			fd;
	fd = 0;
	i = 1;
	if (!(master = (t_master*)malloc(sizeof(t_master))))
		return (0);
	init_master(master);
	init_ht(ht);
	// ft_printf("ac: %d\n", ac);
	capture_flags(master, ac, av);	
	if (ac > 1)
	{
		verify_input(master, ac, av);
		parse_input(master, fd, ht);
		
	}
	// print_list(master); // Found in Capture Room.
	print_ht(ht);
	if (master->leaks == true)
	{
		while (1)
		{
			
		}
	}
	return (0);
	
}

