/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 11:01:49 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/03 14:16:36 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	add_flag(t_master *master, char *c)
{
	c++;
	if (!master->input_flags)
	{
		master->input_flags = (char*)malloc(sizeof(char) * ft_strlen(c));
		ft_strcat(master->input_flags, c);
	}
	else
		ft_strcat(master->input_flags, c);
}

void	capture_flags(t_master *master, int ac, char **av)
{
	int i;

	i = 1;
	while (ac > 1 && av[1] && av[1][0] == '-')
	{
		if (ft_strchr(master->accepted_flags, av[i][i + 1]))
		{
			if (!master->has_flags)
				master->has_flags = 1;
			add_flag(master, av[i]);
		}
		else
			ft_printf("bad flag\n"); // need error mgmt.
		av++;
	}
	ft_printf("total flags: %d\nCaptured flags: %s\n", ft_strlen(master->input_flags), master->input_flags);
}
