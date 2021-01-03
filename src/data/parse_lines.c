/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 13:04:27 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/03 21:40:17 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		link_chk(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '-')
			return (1);
		i++;
	}
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

void	parse_phase(t_bucket **ht, t_master *master, char *line)
{
	if (line[0] == '\0')
		ft_errorexit("ERROR: Empty line.\n");
	if (ft_isspace(line[0]))
		ft_errorexit("ERROR. Space preceeding instruction.\n");
	if (master->phase == 0 && line[0] == '#')
		ft_errorexit("ERROR: First input must be integer ant value.\n");
	if (line[0] == '#')
		capture_comment(master, line);
	else if (master->phase == 0 && capture_ants(master, line))
		master->phase++;
	else if (master->phase == 1 && !capture_room(ht, master, line))
	{
		capture_links(ht, master, line);
		master->phase++;
	}
	else if (master->phase == 2)
		capture_links(ht, master, line);
	store_map(master, line);
	ft_strdel(&line);
}
