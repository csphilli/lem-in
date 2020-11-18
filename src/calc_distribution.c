/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_distribution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:03:49 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/19 00:03:16 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
**	SPRINKLE REMAINING
**	This function takes the remaining ants and distributes them evenly
**	among the chosen paths to use up until there aren't any ants left
**	to distribute. The use of margin will speed up the distribution. It
**	will calculate the max amount of ants that can be distributed in one
**	pass without consuming all the ants. After that one move, single
**	sprinkles are made on the paths until no ants remain.
*/

void			sprinkle_remaining(t_ants *ins)
{
	int i;
	int len;
	int	margin;

	i = 0;
	len = ft_int_arr_len(ins->ant_arr);
	margin = ins->n_ants / len;
	while (i < len)
	{
		ins->ant_arr[i] += margin;
		ins->n_ants -= margin;
		i++;
	}
	i = 0;
	while (ins->n_ants > 0)
	{
		ins->ant_arr[i] += 1;
		ins->n_ants--;
		i++;
		if (i == len)
			i = 0;
	}
}

/*
**	EQUALIZE
**	This function increases the number of ants on the shorter path until
**	the total moves between the paths are equal. The amount of moves
**	required for an ant to go through a path is [n_ants + (length of path - 2)]
**	If you had path1 length of 3 and path2 length of 6, you would have
**	the required moves for each path as:
**	path1: 1 + (3-2): 2
**	path2: 1 + (6-2): 5
**	The function will take the desired moves of 5, and calculate the
**	new ant amount in path1 to make them equal.
**	The equation for that is [ants = desired moves - (length of path -2)]
**	Using path1's len, the new ants become: x = 5 - (3-2) = 5 - 1 = 4
**	Then path1 is now: 4 + (3-2) = 5;
**	The function will continue to loop over the indecies until the max
**	index is reached.
*/

t_ants	*equalize(t_paths *paths, t_ants *ins, int max)
{
	int i;
	int desired;
	int calc;
	int	len;

	i = 0;
	desired = ins->moves_arr[max];
	calc = 0;
	len = ft_int_arr_len(ins->moves_arr);
	while (i < max)
	{
		calc = desired - (list_length(paths->c[i]) - 2);
		// if (ins->n_ants - calc < 0)
		// {
		// 	calc = ins->n_ants;
		// 	ins->ant_arr[i] = calc;
		// 	break ;
		// }
		ins->n_ants -= (calc - ins->ant_arr[i]);
		ins->ant_arr[i] = calc;
		ins->moves_arr[i] = calc + list_length(paths->c[i]) - 2;
		i++;
	}
	return (ins);
}

/*
**	INITIALIZE MOVES
**	This function parses each index to see where there are differences
**	between the paths in terms of total moves to move 1 ant through
**	a complete path. When there are differences, it will pass info
**	to EQUALIZE	and allocate the ants to each index to create
**	an even distribution of moves between paths.
*/

void			normalize_moves(t_paths *paths, t_ants *ins)
{
	int i;
	int j;
	int	len;

	i = 0;
	j = 0;
	len = ft_int_arr_len(ins->moves_arr);
	while (j < len)
	{
		if (ins->moves_arr[i] < ins->moves_arr[j])
		{
			ins = equalize(paths, ins, j);
			j = 0;
		}
		j++;
	}
	ft_printf("After normalizing:\n");
	ft_printf("Ant array: ");
	print_int_arr(ins->ant_arr);
	ft_printf("Moves array: ");
	print_int_arr(ins->moves_arr);
	// sprinkle_remaining(ins);
}

/*
**	INITIALIZE MOVES ARR
**	This function sets up the 2 arrays. The ant_arr is initially set
**	so that there is only 1 ant per path. Ants will be added to each
**	path further along (see above). moves_arr is an array comprised of
**	the total number of moves it takes for 1 ant to reach the goal.
**	moves_arr[0] corresponds to the number of moves required for 1 ant
**	to make it to the goal via path 0.
*/

void			initial_moves_arr(t_paths *paths, t_ants *ins)
{
	int	i;
	int calc;
	int	n_ants;

	i = 0;
	calc = 0;
	n_ants = paths->nbr_ants_s;
	while (i <= ins->max_index)
	{
		calc = 1 + (list_length(paths->c[i]) - 2);
		ins->n_ants--;
		ins->ant_arr = ft_intcat(ins->ant_arr, 1);
		ins->moves_arr = ft_intcat(ins->moves_arr, calc);
		i++;
	}
	i = 0;
	ft_printf("After setting up initial:\n");
	ft_printf("Ant array: ");
	print_int_arr(ins->ant_arr);
	ft_printf("Moves array: ");
	print_int_arr(ins->moves_arr);
	normalize_moves(paths, ins);
}

/*
**	CALC DISTRIBUTION
**	The first part of this function calculates the maximum number of
**	paths from paths->c to use to solve the program. max_index
**	represents the largest index in paths->c to use. It is based on
**	the number of ants passed in the program.
**	The number of moves to reach the goal in any path is
**	n_ants + (length of path - 2)
**	Assuming a path length of 3, it would take 1 ant 1+(3-2) = 2 moves
**	to reach the goal. You would never want to choose a path that required
**	more than 2 moves. This function loops through the paths until it reaches
**	the point where the number of ants passed is less than 1 + ListLength - 2;
**	That value is then passed through the rest of the functions to normalize
**	the ants based on the path lengths.
**	The goal is to take something like this:
**	XXX
**	XXXXX
**	XXXXXXX
**	and make it close to this:
**	XXXXXXX
**	XXXXXXX
**	XXXXXXX
*/


void		init_moves(t_lol *moves)
{
	t_lol *tmp;
	int		i;
	// int		max;

	tmp = moves;
	i = 0;
	if (tmp)
	{
		while (tmp)
		{
			tmp->index = i;
			tmp->len = list_length(tmp->list);
			tmp->cap = tmp->len - 1;
			// tmp->nbr_ants = tmp->nbr_moves--;
			// if (tmp->nbr_moves > max)
			// 	max = tmp->nbr_moves;
			tmp = tmp->next;
			i++;
		}
		// bfs->max_moves = max;
	}
}

void	print_moves(t_lol **list)
{
	t_lol 		*tmp;

	tmp = *list;
	if (tmp)
	{
		while (tmp)
		{
			ft_printf("[%3d]: ", tmp->index);
			if (tmp->len)
				ft_printf("Len: %3d | ", tmp->len);
			if (tmp->cap)
				ft_printf("Cap: %3d | ", tmp->cap);
			if (!tmp->nbr_ants)
				ft_printf("Nbr ants: 0 | ", tmp->nbr_ants);
			else
				ft_printf("Nbr ants: %3d | ", tmp->nbr_ants);
			if (tmp->unlock)
				ft_printf(" | Unlock: %d", tmp->unlock);
			write(1, "\n", 1);
			tmp = tmp->next;
		}
	}
}

int			lol_length(t_lol *lol)
{
	t_lol *tmp;
	int		i;

	tmp = lol;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void		chk_unlock(t_bfs **bfs, t_lol **tmp)
{
	ft_printf("Tmp nbr ants: %d\n", (*tmp)->nbr_ants);
	if ((*tmp)->nbr_ants == (*tmp)->unlock && !(*tmp)->done)
	{
		(*bfs)->max_index++;
		(*tmp)->done = 1;
		// return (1);
	}
	// else
	// 	return (0);
}

void	cascade(t_bfs *bfs, t_master *master)
{
	t_lol 	*tmp;
	// int		max;
	// int		count;
	// int		i;

	tmp = bfs->paths;
	// max = 0;
	// count = 0;
	while (tmp && master->nbr_ants > 0)
	{
		while (tmp->index <= bfs->max_index && master->nbr_ants > 0)
		{
			ft_printf("tmp index: %d\n", tmp->index);
			ft_printf("max index: %d\n", bfs->max_index);
				// break ;
			tmp->nbr_ants++;
			master->nbr_ants--;
			chk_unlock(&bfs, &tmp);
			// ft_printf("master ants: %d\n", master->nbr_ants);
			tmp = (tmp->index == bfs->max_index ? bfs->paths : tmp->next);
		}
		tmp = bfs->paths;
	}
}

void	unlocks(t_bfs *bfs, t_master *master)
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

// void	normalize_to_max(t_bfs *bfs, t_master *master, int max_index)
// {
// 	t_lol 	*tmp;
// 	int		i;

// 	tmp = bfs->paths;
// 	i = 0;
// 	while (i <= max_index)
// 	{
// 		tmp->nbr_ants = bfs->max_moves;
// 		master->nbr_ants -= tmp->nbr_ants;
// 		tmp = tmp->next;
// 		i++;
// 	}
// }

void			calc_distribution(t_master *master, t_bfs *bfs)
{
	t_lol 	*moves;
	int		*arr;
	int		max_index;

	arr = NULL;
	moves = bfs->paths;
	init_moves(moves);
	unlocks(bfs, master);
	cascade(bfs, master);
	// normalize_to_max(bfs, master, max_index);
	ft_printf("ants remaining: %d\n", master->nbr_ants);
	// ft_printf("max index: %d\n", max_index);
	// arr = ft_intcat(arr, 5);
	// arr = ft_intcat(arr, 10);
	// arr = ft_intcat(arr, 20);
	print_int_arr(arr);
	print_moves(&moves);
	while (1)
	{
		
	}
}


/*

1) to see if i can use the next path for distro, i need to subract the length
of paths from each other. p2 - p1. Then, that path is the hypothetical length
of a new path. So calculate the max number of moves through that path using 1 ant.
The max ants to use in that is LL - 1. Compare that number to the
outstanding nbr of ants left to distribute. If it's less than the outstanding, i can
use it, if not, use this same logic to start at the beginning and redistribute again.
2)
*/