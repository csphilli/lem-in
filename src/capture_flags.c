/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 11:01:49 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/22 01:46:34 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	toggle_bools(t_master *master)
{
	int		i;
	char	*s;

	i = 0;
	s = master->flags.input_flags;
	while (*s)
	{
		if (*s == 'p')
			master->flags.print_paths = true;
		else if (*s == 't')
			master->flags.print_hash_table = true;
		else if (*s == 'd')
			master->flags.vis_distro = true;
		else if (*s == 'e')
			master->flags.errors = true;
		s++;
	}
}

void	verify_flags(t_master *master, int nbr_size)
{
	char	*tmp;
	int		j;

	tmp = master->flags.input_flags;
	j = 0;
	if (tmp)
	{
		while (*tmp)
		{
			if (*tmp == 'l')
				tmp = tmp + nbr_size + 1;
			else if (!ft_strchr(master->flags.accepted_flags, *tmp))
				master->flags.errors ? \
				ft_error("ERROR: Invalid flag. See -h for options.") :\
				ft_error("ERROR");
			tmp++;
		}
	}
}

void	capture_flags(t_master *master, int ac, char **av)
{
	int i;
	int	nbr_size;

	i = 1;
	nbr_size = 0;
	while (i < ac)
	{
		if (av[i][1] == 'h')
			load_help();
		if (!master->flags.input_flags)
			master->flags.input_flags = ft_strnew(1);
		ft_strcat(master->flags.input_flags, &av[i][1]);
		master->flags.flag_count++;
		i++;
	}
	if (master->flags.input_flags != NULL)
		toggle_bools(master);
	verify_flags(master, nbr_size);
}
