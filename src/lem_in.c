/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 09:17:17 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/12 15:54:15 by cphillip         ###   ########.fr       */
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
			exit_usage();
	}
	master->valid_input = true;
}

float		load(t_master *master)
{
	float res;

	res = (float)master->nbr_keys / (float)master->new_size;
	return (res);
}

t_bucket	**do_lemin(int fd, t_master *master, t_bucket **ht)
{
	char	*line;

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
	validate_rooms(ht, master);	
	return (ht);
}

int			main(int ac, char **av)
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
	check_inputs(master, ac);
	ht = create_ht(master);
	if (master->valid_input == true)
	{
		ht = do_lemin(fd, master, ht);
		// print_ht(ht, master->new_size);
		do_dfs(master);
	}
	
	if (master->leaks == true)
	{
		while (1)
		{
		}
	}
	return (0);
}
