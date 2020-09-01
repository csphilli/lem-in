/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_comment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 09:05:39 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/01 15:26:47 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	validate_comment(t_master *master, char *comment)
{
	if (master && comment)
	{
		if (master->s_toggle == 1 && \
			ft_strcmp(comment, "start") == 0)
		{
			ft_printf("error, start room already designated\n");
			exit(-1);
		}
		else if (master->e_toggle == 1 && \
			ft_strcmp(comment, "end") == 0)
		{
			ft_printf("error, end room already designated\n");
			exit(-1);
		}
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
		ft_printf("inside comment capture. line: %s\n", str);
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
		master->s_toggle = 1;
	else if (ft_strcmp(master->comment, "end") == 0)
		master->e_toggle = 1;
	// ft_printf("comment: %s\n", str[j]);
}