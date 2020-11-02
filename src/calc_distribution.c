/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_distribution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:03:49 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/02 00:12:30 by cphillip         ###   ########.fr       */
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

void			sprinkle_remaining(t_ant_instrux *ins)
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

t_ant_instrux	*equalize(t_paths *paths, t_ant_instrux *ins, int max)
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

void			normalize_moves(t_paths *paths, t_ant_instrux *ins)
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
	sprinkle_remaining(ins);
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

void			initial_moves_arr(t_paths *paths, t_ant_instrux *ins)
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

void			calc_distribution(t_master *master, t_paths *paths)
{
	clock_t begin;
	clock_t end;
	double time_spent;
	t_ant_instrux	*ins;
	int				len;
	int				i;

	begin = clock();
	if (!(ins = (t_ant_instrux*)malloc(sizeof(t_ant_instrux))))
		exit_malloc();
	init_instrux(ins);
	len = bucket_arr_len(paths->c);
	i = 0;
	ins->n_ants = paths->nbr_ants_s;
	while (i < len)
	{
		if (paths->nbr_ants_s >= 1 + list_length(paths->c[i]) - 2)
			ins->max_index = i;
		i++;
	}
	paths->max_paths = ins->max_index;
	initial_moves_arr(paths, ins);
	if (master->print_ant_distribution)
		print_int_arr(ins->ant_arr);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	ft_printf("Time spent allocating ants: %f\n", time_spent);
	begin = clock();
	ants_marching(paths, ins);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	ft_printf("Time spent writing output: %f\n", time_spent);
	free_ant_instrux(ins);
}
