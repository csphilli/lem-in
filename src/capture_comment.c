/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_comment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 09:05:39 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/18 15:37:16 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	comment_debugger(t_master *master, char *s)
{
	ft_printf("inside comment debugger\n");
	if (master->colors == true)
		ft_printf("Capturing Comment: "CYAN"%s"RESET"\n", s);
	else
		ft_printf("Capturing Comment: %s\n", s);
}

static void	validate_comment(t_master *master, char *comment)
{
	ft_printf("comment in validate: %s\n", comment);
	if (master && comment)
	{
		ft_printf("inside if master && comment\n");
		// if (master->s_toggle == true && \
		// 	ft_strcmp(master->comment, "start") == 0)
		// 		exit_error(master, "start_exists");
		// else if (master->e_toggle == true && \
		// 	ft_strcmp(master->comment, "end") == 0)
		// 		exit_error(master, "end_exists");
		if (master->s_toggle == false && ft_strequ(master->comment, "start"))
			master->s_toggle = true;
		else
			exit_error(master, "start_exists");
		if (master->e_toggle == false && ft_strequ(master->comment, "end"))
			master->e_toggle = true;
		else
			exit_error(master, "end_exists");
	}
}

void		capture_comment(t_master *master, char *str)
{
	int		i;
	int		j;

	i = ft_strlen(str);
	j = 0;
	if (master && str)
	{
		if (master->debugger == true)
			comment_debugger(master, str);
		while (str[j] == '#')
			j++;
		if(!(master->comment = (char*)malloc(sizeof(char) * (i - j) + 1)))
			exit_error(master, "malloc");
		ft_strcpy(master->comment, &str[j]);
		
	}
	// ft_printf("comment: %s\n", master->comment);
	// ft_printf("%s\n", &str[j]);
	validate_comment(master, &str[j]);
	// if (ft_strcmp(master->comment, "start") == 0)
	// 	master->s_toggle = true;
	// else if (ft_strcmp(master->comment, "end") == 0)
	// 	master->e_toggle = true;
}
