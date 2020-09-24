/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 09:17:17 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/24 15:38:14 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	exit_usage(void)
{
	ft_printf(E_USAGE);
	exit(-1);
}

static void check_inputs(t_master *master, int ac)
{
	int i;

	i = 0;
	char *s;

	s = master->input_flags;
	while (*s++)
		i++;
	if (i + 1 != ac && !ft_strchr(master->input_flags, 'f'))
		exit_usage();
}

int	main(int ac, char **av)
{
	t_master	*master;
	t_room		*ht[HT_SIZE];
	int			i;
	
	int			fd;
	fd = 0;
	i = 0;
	if (!(master = (t_master*)malloc(sizeof(t_master))))
		return (0);
	initialize_lemin(master, ht);
	capture_flags(master, ac, av);		
	if (ac > 1)
	{
		check_inputs(master, ac);
		parse_input(master, fd, ht);		
	}
	print_ht(ht);
	if (master->leaks == true)
	{
		while (1)
		{
			
		}
	}
	return (0);	
}
