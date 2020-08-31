/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 13:04:27 by cphillip          #+#    #+#             */
/*   Updated: 2020/08/31 13:30:48 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"



static void 	append_room(t_master *master, t_room *room)
{
	t_room *tmp;

	tmp = master->room_head;
	if (master && room)
	{
		if (!master->room_head)
			master->room_head = room;
		else
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = room;
		}
	}
}

// void			parse_line(t_master *master, char **av, int fd)
static void			parse_line(t_master *master, char *line)
{
	t_room 	*room;
	
	if (!(room = (t_room*)malloc(sizeof(t_room))))
		exit (-1); // Need proper error handling.
	ft_printf("inside while loop\n");
		// ft_printf("line: %s\n", line);
	if (master->ants_captured != 1)
	{
		ft_printf("going to capture ants. Line: %s\n", line);
		capture_ants(master, line);
	}
	else
	{
		while (*line)
			line++;
		line--;
		while (ft_isdigit(*line))
			line--;
		if (*line == '-')
			ft_printf("capture connection\n");
			// capture_connection(master, line);
		else if (ft_strncmp(line, "##", 2) == 0)
			capture_comment(master, line);
		else
			room = capture_room(master, line);
		append_room(master, room);
	}
	ft_printf("End Parse Line\n");
}

void		parsing(t_master *master, int fd)
{
	char *line;
	
	while (get_next_line(fd, &line) > 0)
	{
		ft_printf("parsing line: %s\n", line);
		parse_line(master, line);
		ft_strdel(&line);
	}
}

/*

static void			parse_line(t_master *master, char *line)
{
	t_room 	*room;
	char	*line;
	char	*c;
	if (av[0])
		av[0] += 0;
	c = NULL;
	ft_printf("In Parse Line\n");
	while (get_next_line(fd, &line) > 0)
	{
		ft_printf("inside while loop\n");
		c = line;
		ft_printf("line: %s\n", line);
		if (master->ants_captured != 1)
			capture_ants(master, line);
		else
		{
			while (*c)
				c++;
			c--;
			while (ft_isdigit(*c))
				c--;
			if (*c == '-')
				ft_printf("capture connection\n");
				// capture_connection(master, line);
			else if (ft_strncmp(line, "##", 2) == 0)
				capture_comment(master, line);
			else
				room = capture_room(master, line);
			append_room(master, room);
		}
		free(line);
	}
	ft_printf("End Parse Line\n");
}

*/