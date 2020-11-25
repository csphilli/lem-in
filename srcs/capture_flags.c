/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 11:01:49 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/21 21:15:36 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		validated(t_master *master, char c)
{
	if (ft_strchr(master->accepted_flags, c))
		return (1);
	return (0);
}

void	toggle_bools(t_master *master)
{
	int		i;
	char	*s;

	i = 0;
	s = master->input_flags;
	while (*s)
	{
		if (*s == 'p')
			master->print_paths = true;
		else if (*s == 't')
			master->print_hash_table = true;
		else if (*s == 'd')
			master->vis_distro = true;
		s++;
	}
}

void	add_flag(t_master *master, char *c)
{
	c++;
	if (!ft_strchr(master->accepted_flags, *c))
		ft_error("ERROR: Invalid flag input. Use -h for list.");
	if (!master->input_flags)
		master->input_flags = ft_memalloc(sizeof(char) * ft_strlen(c));
	ft_strcat(master->input_flags, c);
	master->flag_count++;
}

void	capture_flags(t_master *master, int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (av[i][1] == 'h')
			load_help();
		else if (av[i][1] == 'l')
			master->load = ft_atoi(&av[i][2]);
		add_flag(master, av[i]);
		i++;
	}
	if (master->input_flags != NULL)
		toggle_bools(master);
}
