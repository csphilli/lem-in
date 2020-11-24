/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 09:17:17 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/24 12:57:46 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_input(t_bucket **input)
{
	t_bucket	*tmp;

	tmp = *input;
	while (tmp)
	{
		ft_printf("%s\n", tmp->input);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}

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
		// ft_printf("after every entry?\n");
		// 	ft_error("ERROR: Insufficient Input.");
		if (load(master) > master->load)
		{
			master->room_count = 0;
			ht = grow_ht(ht, master);
		}
		parse_lines(master, line, ht);
		// print_ht(ht, master->new_size);
	}
	line = NULL;
	return (ht);
}

int		overlap_chk(t_lol *paths, t_entry *entry, t_entry *start, t_entry *end)
{
	t_lol 		*tmp;
	t_bucket 	*list;
	int			count;

	tmp = paths;
	count = 0;
	while (tmp)
	{
		list = tmp->list;
		while (list)
		{
			if (ft_strequ(list->entry->name, entry->name) && !ft_strequ(list->entry->name, start->name) && !ft_strequ(list->entry->name, end->name))
				count++;
			list = list->next;
		}
		tmp = tmp->next;
	}
	return (count);
}

void	send_for_check(t_lol *paths, t_entry *start, t_entry *end)
{
	t_lol 		*tmp;
	t_bucket 	*list;
	// t_entry 	*curr;
	// int			count;

	tmp = paths;
	while (tmp)
	{
		list = tmp->list;
		while (list)
		{
			if (overlap_chk(paths, list->entry, start, end) > 1)
			{
				ft_printf("Found overlap: %s\n", list->entry->name);
				ft_error("Overlap");
			}
			list = list->next;
		}
		tmp = tmp->next;
	}
	ft_printf("No Overlaps found!\n");
}


t_bucket	**do_lemin(int fd, t_master *master, t_bucket **ht, t_bfs **bfs)
{

	// store_input(master, fd);

	ht = get_data(ht, master, fd);
	(*bfs)->start = master->start_room;
	(*bfs)->end = master->end_room;

	validate_input(master);
	// ft_printf("1\n");
	validate_rooms(ht, master);
	build_paths_parse(ht, master, bfs);
	// while (1)
	// {
		
	// }
	// ft_printf("2\n");
	// build_paths(ht, master, bfs);
	// ft_printf("3\n");
	calc_distro(ht, master, *bfs);
	// ft_printf("S2E Distro:\n");
	// print_distro(&(*bfs)->s2e_paths);

	// ft_printf("E2S Distro\n");
	// print_distro(&(*bfs)->e2s_paths);

	(*bfs)->paths = optimal_solution(*bfs);
	// ft_printf(GREEN"OPTIMAL\n"RESET);
	// print_distro(&(*bfs)->paths);
	
	build_distro_array(*bfs);
	send_for_check((*bfs)->paths, (*bfs)->start, (*bfs)->end);
	// ft_printf(GREEN"OPTIMAL SOLUTION SET\n"RESET);
	// print_int_arr((*bfs)->moves);
	// chk_direct_link(ht, master, *bfs);
	// ft_printf("4\n");
	// ft_printf("5\n");
	print_input(&master->input);
	
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
