/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 11:01:49 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/01 20:56:56 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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
		else if (*s == 'e')
			master->errors = true;
		s++;
	}
}

void	verify_flags(t_master *master, int nbr_size)
{
	char 	*tmp;
	int		j;

	tmp = master->input_flags;
	j = 0;
	while (*tmp)
	{
		if (*tmp == 'l')
			tmp = tmp + nbr_size + 1;
		else if (!ft_strchr(master->accepted_flags, *tmp))
			master->errors ? \
			ft_error("ERROR: Invalid flag. See -h for options.") :\
			ft_error("ERROR");
		tmp++;
	}
}

int		check_load_size(t_master *master, char *s)
{
	int	i;

	i = ft_atoimax(s);
	if (i < 0 || i > 2147483647)
		master->errors ? ft_error("ERROR: Load factor must be of size int.")\
		: ft_error("ERROR");
	master->load = i;
	return (ft_nbr_size(i));
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
		else if (av[i][1] == 'l')
			nbr_size = check_load_size(master, &av[i][2]);
		if (!master->input_flags)
			master->input_flags = ft_strnew(1);
		ft_strcat(master->input_flags, &av[i][1]);
		master->flag_count++;
		i++;
	}
	if (master->input_flags != NULL)
		toggle_bools(master);
	verify_flags(master, nbr_size);
}
