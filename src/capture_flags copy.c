/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 11:01:49 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/19 10:20:27 by cphillip         ###   ########.fr       */
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
			master->print_all_paths = true;
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
	if (!master->input_flags)
	{
		if (!(master->input_flags = ft_memalloc(sizeof(char) * ft_strlen(c))))
			ft_error("Error: Failed to allocate memory.");
		ft_strcat(master->input_flags, c);
	}
	else
		ft_strcat(master->input_flags, c);

}

void	capture_flags(t_master *master, int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if ((av[i][0] == '-') && validated(master, av[i][1]))
		{
			if (av[i][1] == 'h')
				load_help();
			else if (av[i][1] == 'l')
				master->load = ft_atoi(&av[i][2]);
			add_flag(master, av[i]);
		}
		else
		{
			ft_printf("Error. Invalid flag '%c'.", av[i][1]);
			ft_error(" Use -h for a list of accepted flags.");
		}
		i++;
	}
	if (master->input_flags != NULL)
		toggle_bools(master);
}
