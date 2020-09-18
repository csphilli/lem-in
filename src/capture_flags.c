/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 11:01:49 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/18 16:30:01 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	print_bools(t_master *master)
{
	if (master->colors == true)
	{
		ft_printf("%2cAdv Errors: \t", ' ');
			if(master->adv_errors == true)
				ft_printf(GREEN"[%s]"RESET"\n", "ON");
			else
				ft_printf(RED"[%s]"RESET"\n", "OFF");
		ft_printf("%2cDebugger: \t", ' ');
			if(master->debugger == true)
				ft_printf(GREEN"[%s]"RESET"\n", "ON");
			else
				ft_printf(RED"[%s]"RESET"\n", "OFF");
	}
}

static void	toggle_bools(t_master *master)
{
	int i;
	char *s;

	i = 0;
	s = master->input_flags;
	// ft_printf("Boolean Values:\n");
	ft_printf("string of flags: %s\n", s);
	while (s[i++])
		if (s[i] == 'h')
			load_help(master);
	while (*s)
	{		
		if (*s == 'a')
			ft_printf("Do something. Poke it\n");
		else if (*s == 'c')
			master->colors = true;
		else if (*s == 'd')
			master->debugger = true;
		else if (*s == 'e')
			master->adv_errors = true;
		else
			exit_error(master, "flags");
		s++;
	}
	if (master->debugger == true)
		print_bools(master);
	ft_printf("\n");
}

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
		if (av[i][1])
		{
			if (!master->has_flags)
				master->has_flags = 1; // What is this for??
			add_flag(master, av[i]);
		}
		av++;
	}
	if (master->input_flags != NULL)
		toggle_bools(master);
}
