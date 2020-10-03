/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 09:17:17 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/03 15:33:49 by cphillip         ###   ########.fr       */
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

float 	load(t_master *master)
{
	float res;

	res = (float)master->nbr_keys / (float)master->new_size;
	return (res);
}

static void	do_lemin(int fd, t_master *master, t_bucket **ht)
{
	char	*line;

	while (get_next_line(fd, &line) > 0)
	{
		if (load(master) > master->load)
		{
			ft_printf("load exceeded. Growing HT\n");
			master->room_count = 0;
			ht = grow_ht(ht, master);
		}
		// ft_printf("going into parsing lines\n");
		parse_lines(master, line, ht);
	}
	printf("Load: %f | master->load: %f\n", load(master), master->load);
}

int	main(int ac, char **av)
{
	t_master	*master;
	t_bucket	**ht;	
	int			fd;

	fd = 0;
	ht = NULL;
	if (!(master = (t_master*)malloc(sizeof(t_master))))
		exit_malloc();
	init_master(master);
	capture_flags(master, ac, av);
	ht = create_ht(master);
	// ft_printf("done creating ht\n");
	if (ac > 1)
	{
		// ft_printf("checking inputs\n");
		check_inputs(master, ac);
		// ft_printf("done checking inputs\n");
		do_lemin(fd, master, ht);				
	}
	print_ht(ht, master);
	ft_printf("Room Count: %d\n", master->room_count);
	if (master->leaks == true)
	{
		while (1)
		{
			
		}
	}
	return (0);	
}
