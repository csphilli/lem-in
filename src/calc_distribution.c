/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_distribution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:03:49 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/19 09:58:08 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		init_moves(t_lol *moves)
{
	t_lol *tmp;
	int		i;

	tmp = moves;
	i = 0;
	if (tmp)
	{
		while (tmp)
		{
			tmp->index = i;
			tmp->len = list_length(tmp->list);
			tmp->cap = tmp->len - 1;
			tmp = tmp->next;
			i++;
		}
	}
}

void	print_line_break(int nbr, int amount)
{
	int sum;

	sum = nbr * amount;
	while (sum--)
		write(1, "-", 1);
	write(1, "\n", 1);
}

void	print_cascade_header(void)
{
	ft_printf("%-10sIndex position of list of list.\n", "Index:");
	ft_printf("%-10sLength of the list at index.\n", "Length:");
	ft_printf("%-10sMin moves to get 1 ant through path.\n", "Moves:");
	ft_printf("%-10sNumber of ants allocated to specific", "Ants:");
	ft_printf(" path.\n");
	ft_printf("%-10sMin number of ants to unlock allocation", "Unlock:");
	ft_printf(" at next index.\n\n");
	ft_printf("|%-10s%-10s", "Index", "Length");
	ft_printf("%-10s%-10s%-10s|\n", "Moves", "Ants", "Unlock");
	print_line_break(5, 10);
}

void	print_moves(t_lol **list)
{
	t_lol 		*tmp;

	tmp = *list;
	if (tmp)
	{
		print_cascade_header();
		while (tmp)
		{
			ft_printf("|%-10d", tmp->index);
			if (tmp->len)
				ft_printf("%-10d", tmp->len);
			if (tmp->cap)
				ft_printf("%-10d", tmp->cap);
			if (!tmp->nbr_ants)
				ft_printf("%-10d", 0);
			else
				ft_printf("%-10d", tmp->nbr_ants);
			if (tmp->unlock)
				ft_printf("%-10d|\n", tmp->unlock);
			print_line_break(5, 10);
			tmp = tmp->next;
		}
	}
}



void		chk_unlock(t_bfs **bfs, t_lol **tmp)
{
	if ((*tmp)->nbr_ants == (*tmp)->unlock && !(*tmp)->done)
	{
		(*bfs)->max_index++;
		(*tmp)->done = 1;
	}
}

void	cascade(t_bfs *bfs, t_master *master)
{
	t_lol 	*tmp;

	tmp = bfs->paths;
	while (tmp && master->nbr_ants > 0)
	{
		while (tmp->index <= bfs->max_index && master->nbr_ants > 0)
		{
			tmp->nbr_ants++;
			master->nbr_ants--;
			chk_unlock(&bfs, &tmp);
			tmp = (tmp->index == bfs->max_index ? bfs->paths : tmp->next);
		}
		tmp = bfs->paths;
	}
}

void	unlocks(t_bfs *bfs)
{
	t_lol	*tmp;

	tmp = bfs->paths;
	while (tmp)
	{
		if (tmp->next)
			tmp->unlock = tmp->next->len - tmp->len + 1;
		else
			tmp->unlock = 1000000;
		tmp = tmp->next;
	}
}


void			calc_distribution(t_master *master, t_bfs *bfs)
{
	t_lol 	*moves;
	int		*arr;

	arr = NULL;
	moves = bfs->paths;
	init_moves(moves);
	unlocks(bfs);
	cascade(bfs, master);
	print_int_arr(arr);
	print_moves(&moves);
	
	// while (1)
	// {
		
	// }
}
