/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 09:17:17 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/01 17:43:18 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		check_inputs(t_master *master, int ac, int mode)
{
	if (mode == 1)
	{
		if (master->flags.input_flags && master->flags.flag_count + 1 != ac)
			ft_error("ERROR: Invalid use. '-h' for help.\n");
	}
	if (mode == 2)
	{
		if (!master->start_room)
			ft_error("ERROR: No start room specified.\n");
		if (!master->end_room)
			ft_error("ERROR: No end room specified.\n");
		if (!master->link)
			ft_error("ERROR: No room links specified.\n");
		if (!master->a_room)
			ft_error("ERROR: No rooms specified.\n");
	}
}

t_bucket	**get_data(t_bucket **ht, t_master *master)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
		parse_lines(master, line, ht);
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
		ft_error("ERROR: No solution. No path between start and end.\n");
	if (!direct_link(ht, master))
	{
		calc_distro(master);
		build_distro_array(master);
		ants_marching(master);
	}
	return (ht);
}

void		do_extras(t_bucket **ht, t_master *master)
{
	if (master->flags.print_hash_table)
		print_ht(ht);
	if (master->flags.print_paths)
		print_distro(&master->bfs->paths);
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
	if (master->flags.input_flags)
		do_extras(ht, master);
	end = clock();
	time = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%lf\n", time);
	// system ("leaks lem-in");
	return (0);
}
