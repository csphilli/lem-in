/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 09:17:17 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/18 12:25:14 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		check_inputs(t_master *master, int ac)
{
	int		i;
	char	*s;

	i = 0;
	s = NULL;
	if (master->input_flags)
	{
		s = master->input_flags;
		while (*s++)
			i++;
		if (i + 1 != ac && !ft_strchr(master->input_flags, 'f'))
			ft_error("Error. Invalid usage. Use '-h' for help.");
	}
	master->valid_input = true;
}

t_bucket	**get_data(t_bucket **ht, t_master *master, int fd)
{
	char	*line;

	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (load(master) > master->load)
		{
			master->room_count = 0;
			ht = grow_ht(ht, master);
		}
		parse_lines(master, line, ht);
	}
	line = NULL;
	return (ht);
}


t_bucket	**do_lemin(int fd, t_master *master, t_bucket **ht)
{
	t_bfs	*bfs;

	bfs = ft_memalloc(sizeof(t_bfs));
	ht = get_data(ht, master, fd);
	bfs->start = master->start_room;
	bfs->end = master->end_room;
	validate_rooms(ht, master);
	build_paths(ht, master, &bfs);
	// print_lol(&bfs->paths);
	while (1)
	{
		
	}
	// dead_end_scan(master, ht);
	// do_bfs(master, ht);
	// find_paths(master, ht);
	return (ht);
}

int			main(int ac, char **av)
{
	t_master	*master;
	t_bucket	**ht;
	int			fd;


	fd = 0;
	ht = NULL;
	// if (!(master = (t_master*)malloc(sizeof(t_master))))
	// 	exit_malloc();
	master = ft_memalloc(sizeof(t_master));
	init_master(master);
	capture_flags(master, ac, av);
	check_inputs(master, ac);
	ht = create_ht(master);
	if (master->valid_input == true)
		ht = do_lemin(fd, master, ht);
	if (master->print_hash_table)
		print_ht(ht, master->new_size);
	if (master->leaks == true)
	{
		while (1)
		{
		}
	}
	
	return (0);
}
