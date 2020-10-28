/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_marching.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 09:35:31 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/28 09:44:49 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
/*

int		list_length(t_bucket *head)
{
	t_bucket	*tmp;
	int			len;

	tmp = head;
	len = 1;
	while (tmp->next)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}



int		another_move(t_paths *paths, t_bucket *head, int index)
{
	t_bucket	*tmp;
	int			arr_len;

	tmp = head;
	arr_len = bucket_arr_len(paths->c);
	while (tmp->next)
	{
		if (tmp->entry->occ)
			return (1);
		tmp = tmp->next;
	}
	if (index - 1 < arr_len)
		index++;
	while (index < arr_len)
	{
		tmp = paths->c[index];
		while (tmp->next)
		{
			if (tmp->entry->occ)
				return (1);
			tmp = tmp->next;
		}
		index++;
	}
	return (0);
}

void	write_space(t_paths *paths, t_bucket *head, int index, int pos)
{
	// ft_printf("Index in write_space: %d\n", index);
	t_bucket	*tmp;
	int			list_len;
	int			arr_paths;

	tmp = head;
	list_len = list_length(tmp);
	arr_paths = bucket_arr_len(paths->c);
	if (another_move(paths, tmp, index))
	{
		if (index + 1 < arr_paths)
		{
			// ft_printf("index + 1 < arr_paths\n");
			write(1, " ", 1);
		}
		else if (index + 1 == arr_paths)
		{
			// ft_printf("at last index\n");
			if (pos < list_len - 1)
				write(1, " ", 1);
		}
	}
}


void	move_ants(t_paths *paths, t_bucket *path, int index, int len)
{
	t_bucket	*tmp;
	int			list_l;
	int			i;

	tmp = path;
	i = 0;
	list_l = list_length(tmp);
	// ft_printf("len of tmp at index %d: %d\n", index, length);
	while (tmp->next && (!tmp->next->entry->occ && \
		!ft_strequ(paths->s_room->name, tmp->next->entry->name)))
		{
			tmp = tmp->next;
			i++;
		}
	// ft_printf("i : %d\n", i);
	while (tmp->next)
	{
		if (ft_strequ(tmp->entry->name, paths->s_room->name))
		{
			// ft_printf(RED"Hit Break\n"RESET);
			return ;
		}
		if (tmp->next && ft_strequ(tmp->next->entry->name, paths->s_room->name))
		{
			// ft_printf("Start to Room\n");
			write_start_to_room(paths, tmp->entry, index, len);
			// write(1, " ", 1);
		}
		else if (ft_strequ(tmp->entry->name, paths->e_room->name) && tmp->next->entry->occ)
		{
			// ft_printf("Room to End\n");
			write_room_to_end(paths, tmp->entry, tmp->next->entry, index, len);
			// write(1, " ", 1);
		}
		else if (tmp->next && tmp->next->entry->occ)
		{
			// ft_printf("Room to Room\n");
			write_room_to_room(paths, tmp->entry, tmp->next->entry, index, len);
			// write(1, " ", 1);
		}
		else
			ft_printf(RED"No Hit\n"RESET);
		write_space(paths, tmp, index, i);
		tmp = tmp->next;
	}
}

void	move_all_but_one(t_paths *paths)
{
	t_bucket	*tmp;
	int			index;
	int			len;
	int			toggle;

	toggle = 0;
	len = link_array_len(paths->s_room->link_arr);
	// index = 0;
	while (paths->nbr_ants_s > 0)
	{
		index = 0;
		while (index < len)
		{
			tmp = paths->c[index];
			// ft_printf("Using index: %d\n", )
			move_ants(paths, tmp, index, len);

			index++;
		}
		write(1, "\n", 1); // print a space and new line?
		paths->nbr_moves++;
	}
	ft_printf("nbr ants left: %d\n", paths->nbr_ants_s);
	// make_shortest_move(paths);
	// after running through and getting ants into the maze, the initial loop is done. But then I need to
	//	continue working through it until the maze is empty.
}

void	ants_marching(t_paths *paths)
{
	int	i;

	i = 0;
	paths->max_id = paths->nbr_ants_s;
	ft_printf("max id: %d\n", paths->max_id);
	// get_shortest_path(paths);
	
	// print_paths(paths->c);
	move_all_but_one(paths);
	// while (1)
	// {
		
	// }
	ft_printf("nbr moves: %d\n", paths->nbr_moves);
}

if (ft_strequ(tmp->entry->name, paths->s_room->name))
		{
			ft_printf("Hit Break\n");
			return ;
		}
		if (tmp->next && ft_strequ(tmp->next->entry->name, paths->s_room->name))
		{
			ft_printf("Start to Room\n");
			write_start_to_room(paths, tmp->entry, index, len);
		}
		else if (ft_strequ(tmp->entry->name, paths->e_room->name) && tmp->next->entry->occ)
		{
			ft_printf("Room to End\n");
			write_room_to_end(paths, tmp->entry, tmp->next->entry, index, len);
		}
		else if (tmp->next && tmp->next->entry->occ)
		{
			ft_printf("Room to Room\n");
			write_room_to_room(paths, tmp->entry, tmp->next->entry, index, len);
		}
		else
			ft_printf("No Hit\n");
		write(1, " ", 1);
		tmp = tmp->next;
*/
