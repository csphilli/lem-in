/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 13:04:27 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/22 11:34:14 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		room_or_link(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '-')
			break ;
		i++;		
	}
	if (line[i] == ' ')
		return (1);
	return (0);
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
	master->map->b_len += src_l + 1;
	return ((char *)dest);
}

void	store_map(t_master *master, char *line)
{
	if (!(master->map))
		master->map = create_io();
	master->map->buf = cat_input(master, master->map->buf, line);
	if (master->map->b_len > IO_BUF - 25)
	{
		buf_to_output(&master->map);
		ft_strdel(&master->map->buf);
		master->map->buf = ft_strnew(IO_BUF);
		master->map->b_len = 0;
	}
}

void	parse_lines(t_master *master, char *line, t_bucket **ht)
{
	int			i;
	t_entry		*entry;

	i = 0;
	entry = NULL;
	if (!master->flags.ants_added)
		capture_ants(master, line);
	else if (line[i] == '#')
		capture_comment(master, line);
	else if (line[i] == ' ')
		master->flags.errors ? ft_error("ERROR. Space preceeding instruction.") :\
		ft_error("ERROR");
	else if (master->flags.ants_added == true && line[i] != '#')
	{
		if (room_or_link(line))
			capture_room(ht, master, line);
		else
			capture_links(ht, master, line);
	}
	store_map(master, line);
	ft_strdel(&line);
	master->line_nbr++;
}
