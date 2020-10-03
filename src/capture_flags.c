/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 11:01:49 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/03 15:24:01 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	print_bools(t_master *master)
{
	if (master->colors == true)
	{
		ft_printf(" Adv Errors: \t");
			if(master->adv_errors == true)
				ft_printf(GREEN"[%s]"RESET"\n", "ON");
			else
				ft_printf(RED"[%s]"RESET"\n", "OFF");
		ft_printf(" Debugger: \t");
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
	if (ft_strchr(s, 'h'))
		load_help(master);
	else
	{
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
			else if (*s == 'l')
				master->leaks = true;
			s++;
		}
	}
	if (master->debugger == true)
		print_bools(master);
}

static void	add_flag(t_master *master, char *c)
{
	c++;
	if (!master->input_flags)
	{
		if (!(master->input_flags = (char*)malloc(sizeof(char)\
		 * (ft_strlen(c)))))
			exit_malloc();		
		ft_strcat(master->input_flags, c);
	}
	else
		ft_strcat(master->input_flags, c);
}

void capture_flags(t_master *master, int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
			add_flag(master, av[i]);
		i++;
	}
	if (master->input_flags != NULL)
		toggle_bools(master);
	// ft_printf("Flags: %s\n", master->input_flags);
}
