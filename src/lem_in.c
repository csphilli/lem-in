/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 09:17:17 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/19 21:15:01 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		check_inputs(t_master *master, int ac)
{
	if (master->input_flags && master->flag_count + 1 != ac)
		ft_error("Error. Invalid usage. Use '-h' for help.");
	return (1);
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

t_bucket	**do_lemin(int fd, t_master *master, t_bucket **ht, t_bfs **bfs)
{
	ht = get_data(ht, master, fd);
	(*bfs)->start = master->start_room;
	(*bfs)->end = master->end_room;
	validate_rooms(ht, master);
	build_paths(ht, master, bfs);
	ants_marching(*bfs, master);
	return (ht);
}

void	do_extras(t_bucket **ht, t_master *master, t_bfs *bfs)
{
	// if (master->vis_distro)
	// {
	// 	system("clear");
	// 	master->vis_distro = false;
	// 	print_distro(&bfs->paths);
	// }
	if (master->print_hash_table)
		print_ht(ht, master->new_size);
	if (master->print_paths)
		print_lol(&bfs->paths);
}

int			main(int ac, char **av)
{
	t_master	*master;
	t_bucket	**ht;
	t_bfs		*bfs;
	int			fd;


	fd = 0;
	ht = NULL;
	master = ft_memalloc(sizeof(t_master));
	bfs = ft_memalloc(sizeof(t_bfs));
	init_master(master);
	capture_flags(master, ac, av);
	// check_inputs(master, ac);
	ht = create_ht(master);
	// if (master->valid_input == true)
	if (check_inputs(master, ac))
		ht = do_lemin(fd, master, ht, &bfs);
	// if (master->print_hash_table)
	// 	print_ht(ht, master->new_size);
	if (master->input_flags)
		do_extras(ht, master, bfs);
	// while (1)
	// {
		
	// }
	return (0);
}
