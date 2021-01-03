/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 09:17:17 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/03 11:50:48 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		check_inputs(t_master *master, int ac, int mode)
{
	if (mode == 1)
	{
		if (master->flags.input_flags && master->flags.flag_count + 1 != ac)
			ft_errorexit("ERROR: Invalid use. '-h' for help.\n");
	}
	if (mode == 2)
	{
		if (!master->start_room)
			ft_errorexit("ERROR: No start room specified.\n");
		if (!master->end_room)
			ft_errorexit("ERROR: No end room specified.\n");
		if (!master->link)
			ft_errorexit("ERROR: No room links specified.\n");
		if (!master->a_room)
			ft_errorexit("ERROR: No rooms specified.\n");
	}
}

t_bucket	**get_data(t_bucket **ht, t_master *master)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '\0')
			ft_errorexit("ERROR: Empty line.\n");
		parse_lines(master, line, ht);
	}
	buf_to_output(&master->map);
	ft_strdel(&master->map->buf);
	line = NULL;
	return (ht);
}

t_bucket	**do_lemin(t_master *master, t_bucket **ht, int ac)
{
	ht = get_data(ht, master);
	check_inputs(master, ac, 2);
	edmonds_karp(ht, master);
	if (!master->solution)
		ft_errorexit("ERROR: No solution. No path between start and end.\n");
	if (!direct_link(ht, master))
	{
		calc_distro(master);
		build_distro_array(master);
		ants_marching(master);
	}
	return (ht);
}

void		print_outputs_and_extras(t_bucket **ht, \
			t_master *master, double time)
{
	if (!master->direct)
	{
		if (!master->flags.print_input)
			print_io(master->map, 1);
		print_io(master->moves, 0);
	}
	if (master->flags.print_time)
		ft_printf("%lf", time);
	if (master->flags.print_paths)
		print_paths(master);
	if (master->flags.print_hash_table)
		print_ht(ht);
	if (master->flags.vis_distro)
		print_cascade(master);
	if (master->flags.leak_check)
		system("leaks lem-in");
}

int			main(int ac, char **av)
{
	t_master	*master;
	t_bucket	**ht;
	double		time;
	clock_t		begin;
	clock_t		end;

	master = create_structs();
	begin = clock();
	ht = NULL;
	capture_flags(master, ac, av);
	ht = ft_memalloc(sizeof(t_bucket*) * TABLE_SIZE);
	check_inputs(master, ac, 1);
	ht = do_lemin(master, ht, ac);
	end = clock();
	time = (double)(end - begin) / CLOCKS_PER_SEC;
	print_outputs_and_extras(ht, master, time);
	return (0);
}
