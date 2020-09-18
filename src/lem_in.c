/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 09:17:17 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/18 15:45:09 by cphillip         ###   ########.fr       */
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

static void	print_bools(t_master *master)
{
	if (master->colors == true)
	{
		ft_printf("%2cAdv Errors: \t", ' ');
			if(master->adv_errors == true)
				ft_printf(GREEN"[%s]"RESET"\n", "ON");
			else
				ft_printf(RED"[%s]"RESET"\n", "OFF");
		ft_printf("%2cDebugger: \t", ' ');
			if(master->debugger == true)
				ft_printf(GREEN"[%s]"RESET"\n", "ON");
			else
				ft_printf(RED"[%s]"RESET"\n", "OFF");
	}
}

static void	toggle_bools(t_master *master)
{
	char *s;

	s = master->input_flags;
	ft_printf("Boolean Values:\n");
	ft_printf("string of flags: %s\n", s);
	while (*s)
	{		
		if (*s == 'a')
			ft_printf("a toggle enabled.\n");
		else if (*s == 'c')
			master->colors = true;
		else if (*s == 'd')
			master->debugger = true;
		else if (*s == 'e')
			master->adv_errors = true;
		s++;
	}
	if (master->debugger == true)
		print_bools(master);
	ft_printf("\n");
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
	// ft_printf("ac: %d\n", ac);
	capture_flags(master, ac, av);
	if (master->input_flags != NULL)
		toggle_bools(master);
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

