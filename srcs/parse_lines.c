/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 13:04:27 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/27 10:12:36 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		acceptable(char c)
{
	return (c >= 33 && c <= 126);
}



void	append_to_output(t_master *master, t_output **output)
{
	t_output *head;
	t_output *tmp;

	head = *output;
	tmp = head;
	if (!head)
	{
		head = ft_memalloc(sizeof(t_output));
		head->line = ft_strdup(master->input);
		head->len = master->l;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_memalloc(sizeof(t_output));
		tmp->next->line = ft_strdup(master->input);
		tmp->next->len = master->l;
	}
	*output = head;
}


char	*cat_input(t_master *master, char *dest, const char *src)
{
	int		i;
	size_t	dest_l;
	size_t	src_l;

	i = 0;
	dest_l = ft_strlen(dest);
	src_l = ft_strlen(src);
	while (src[i])
	{
		dest[dest_l + i] = src[i];
		i++;
	}
	dest[dest_l + i] = '\n';
	master->l += src_l + 1;
	return ((char *)dest);
}

void	store_input(t_master *master, char *line)
{
	master->input = cat_input(master, master->input, line);
	// ft_printf("master->input: %s", master->input);
	if (master->l > LINEBUF - 25)
	{
		append_to_output(master, &master->output);
		ft_strdel(&master->input);
		master->input = ft_strnew(LINEBUF);
		// ft_printf("address: %p\n", master->input);
		// free(master->input);
		master->l = 0;
	}
	// ft_printf("master->l: %d\n", master->l);
	// if (master->l)
	// ft_printf("master->input: %s", master->input);
	// while (1)
	// {
		
	// }
}

void	parse_lines(t_master *master, char *line, t_bucket **ht)
{
	int			i;
	t_entry		*entry;

	i = 0;
	entry = NULL;
	if (!master->ants_added)
		capture_ants(master, line);
	else if (line[i] == '#')
		capture_comment(master, line);
	else if (line[i] == '\0')
		ft_error("ERROR. Invalid line.");
	else if (master->ants_added == true && line[i] != '#')
	{
		while (acceptable(line[i++]))
		{
			if (line[i] == ' ')
				capture_room(ht, master, line);
			else if (line[i] == '-')
				capture_links(ht, master, line);
		}
	}
	store_input(master, line);
	ft_strdel(&line);
	// while (1)
	// {
		
	// }
	master->line_nbr++;
}
