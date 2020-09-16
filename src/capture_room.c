/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 09:01:34 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/03 17:50:10 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"



// static void		capture_room_part_two(t_master *master, t_room *room)
// {
// }

void			capture_room(t_master *master, char *line)
{
	if (master && line)
	{
		ft_printf("inside room capture. Line: %s\n", line);
		// assign room address to master struct of latest room.
	}
}

/*
static void		capture_room_part_two(t_master *master, t_room *room)
{
	if (master->s_toggle == 1)
		room->name = "start";
	else if (master->e_toggle == 1)
		room->name = "end";
}

t_room			*capture_room(t_master *master, char *line)
{
	t_room		*new;
	char		*c;

	c = line;
	if (!(new = (t_room*)malloc(sizeof(t_room))))
		return (0);
	init_room(new);
	while (*c)
		c++;
	c--;
    while (ft_isdigit(*(c)))
		c--;
	new->y = ft_atoi(c + 1);
	c--;
	while (ft_isdigit(*(c)))
    	c--;
    new->x = ft_atoi(c + 1);
    if(!(new->name = (char*)malloc((c - line + 1) * sizeof(char))))
    	return (NULL);
    ft_strncpy(new->name, line, c - line);
    new->name[c - line] = '\0';
    ft_strdel(&line);
	capture_room_part_two(master, new);
	return (new);
}
*/