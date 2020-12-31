/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 09:17:17 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/31 14:17:55 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
		parse_lines(master, line, ht);
	buf_to_output(&master->map);
	ft_strdel(&master->map->buf);
	line = NULL;
	return (ht);
}

t_bucket	**do_lemin(t_master *master, t_bucket **ht)
{
	ht = get_data(ht, master);
	validate_input(master);
	edmonds_karp(ht, master);
	if (!chk_direct_link(ht, master))
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
	if (check_inputs(master, ac))
		ht = do_lemin(master, ht);
	if (master->flags.input_flags)
		do_extras(ht, master);
	end = clock();
	time = (double)(end - begin) / CLOCKS_PER_SEC;
	// printf("%lf\n", time);
	// system ("leaks lem-in");
	return (0);
}
