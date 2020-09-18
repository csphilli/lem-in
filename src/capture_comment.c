/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_comment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 09:05:39 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/18 10:08:22 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	comment_debugger(t_master *master, char *s)
{
	ft_printf("inside comment debugger\n");
	if (master->colors == true)
	{
		ft_printf("Capturing Comment: "CYAN"%s"RESET"\n", s);
	}
	else
	{
		ft_printf("Capturing Comment: %s\n", s);
	}
}

static void	validate_comment(t_master *master, char *comment)
{
	if (master && comment)
	{
		if (master->s_toggle == true && \
			ft_strcmp(comment, "start") == 0)
				exit_error(master, "start_exists");
		else if (master->e_toggle == true && \
			ft_strcmp(comment, "end") == 0)
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
		{
			ft_printf("error, bad malloc\n");
			exit(-1);
		}
		// ft_printf("len: %d\n", i - j);
		ft_strcpy(master->comment, &str[j]);
		
	}
	ft_printf("comment: %s\n", master->comment);
	validate_comment(master, &str[j]);
	if (ft_strcmp(master->comment, "start") == 0)
		master->s_toggle = true;
	else if (ft_strcmp(master->comment, "end") == 0)
		master->e_toggle = true;
	// ft_printf("comment: %s\n", str[j]);
	// ft_strdel(&str);
}