/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 09:17:17 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/21 20:02:33 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			check_inputs(t_master *master, int ac)
{
	if (master->flags.input_flags && master->flags.flag_count + 1 != ac)
		master->flags.errors ? ft_error("ERROR: Invalid use. '-h' for help.") : \
		ft_error("ERROR");
	return (1);
}

t_bucket	**get_data(t_bucket **ht, t_master *master)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		// if (load(master) > master->load)
		// {
		// 	master->room_count = 0;
		// 	ht = grow_ht(ht, master);
		// }
		parse_lines(master, line, ht);
	}
	// append_to_output(master, &master->output);
	buf_to_output(&master->map);
	ft_strdel(&master->map->buf);
	line = NULL;
	return (ht);
}

t_bucket	**do_lemin(t_master *master, t_bucket **ht, t_bfs **bfs)
{
	// ht = get_data(ht, master, fd);
	ht = get_data(ht, master);
	// print_ht(ht);
	// ft_error("exiting after parsing\n");
	// analyze_ht(ht);
	(*bfs)->start = master->start_room;
	(*bfs)->end = master->end_room;
	validate_input(master);
	edmonds_karp(ht, master, bfs);
	if (!chk_direct_link(ht, master, *bfs))
	{
		calc_distro(master, *bfs);
		(*bfs)->paths = optimal_solution(*bfs);
		build_distro_array(*bfs);
		ants_marching(*bfs, master);
	}
	return (ht);
}

void		do_extras(t_bucket **ht, t_master *master, t_bfs *bfs)
{
	if (master->flags.print_hash_table)
		print_ht(ht);
	if (master->flags.print_paths)
		print_lol(&bfs->paths);
}

int			main(int ac, char **av)
{
	t_master	*master;
	t_bucket	**ht;
	t_bfs		*bfs;
	// int			fd;
	double		time;
	clock_t		begin;
	clock_t		end;

	begin = clock();
	// fd = 0;
	ht = NULL;
	master = ft_memalloc(sizeof(t_master));
	bfs = ft_memalloc(sizeof(t_bfs));
	init_master(master);
	capture_flags(master, ac, av);
	ht = ft_memalloc(sizeof(t_bucket*) * TABLE_SIZE);
	if (check_inputs(master, ac))
		// ht = do_lemin(fd, master, ht, &bfs);
		ht = do_lemin(master, ht, &bfs);
	if (master->flags.input_flags)
		do_extras(ht, master, bfs);
	end = clock();
	time = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%lf\n", time);
	system ("leaks lem-in");
	return (0);
}
