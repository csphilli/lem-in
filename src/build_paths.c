/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 10:40:08 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/14 13:54:24 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

















// int		chk_for_goal(t_bucket *list, t_entry *goal)
// {
// 	t_bucket *tmp;
	
// 	tmp = list;
// 	while (tmp->next)
// 		tmp = tmp->next;
// 	if (ft_strequ(tmp->entry->name, goal->name))
// 		return (1);
// 	return (0);
// }


// t_lol	*execute_que(t_bucket **ht, t_master *master, t_bfs *bfs, t_lol *que)
// {
// 	t_lol	*lolp;
// 	t_entry *chk;
// 	t_bucket	*list;
// 	int		len;

// 	lolp = NULL;
// 	len = 0;
// 	latest = NULL;
// 	chk = NULL;
// 	list = NULL;
// 	while (que)
// 	{
// 		// ft_printf("PRINTING CURRENT QUE\n");
// 		// print_lol(que);
// 		// ft_printf("PRINTING SAVED SOLUTIONS\n");
// 		print_lol(lolp);
// 		set_visited(ht, master, que->list, 1);
// 		latest = get_last_entry(que->list);
// 		// ft_printf("lastest visited status: %d\n", test->visited);
// 		// break ;
// 		if (ft_strequ(latest->name, bfs->goal->name))
// 		{
// 			lolp = ll_to_lol(lolp, que->list);
// 			bfs->path_count++;
// 			if (bfs->path_count == 20)
// 				return (lolp);
// 		}
// 		else
// 		{
// 			len = link_array_len(latest->link_arr);
// 			cpy = copy_ll(que->list);
// 			// ft_printf("len: %d\n", len);
// 			while (len--)
// 			{
// 				chk = get_entry(ht, master, latest->link_arr[len]->name);
// 				// ft_printf("chk name: %s\n", chk->name);
// 				if (!chk->visited && !chk->no)
// 				{
// 					list = copy_ll(que->list);
// 					list = append_to_ll(list, latest->link_arr[len]);
// 					que = ll_to_lol(que, list);
// 					free_ll(list);
// 					list = NULL;
// 					// while (1)
// 					// {
						
// 					// }
// 				}
// 				// free_entry(chk);
// 				chk = NULL;
// 			}
// 		}
// 		// free_entry(latest);
// 		// latest = NULL;
// 		set_visited(ht, master, que->list, 0);
// 		que = pop_from_lol(que);
// 		// while (1)
// 		// {
			
// 		// }
// 	}
// 	return (lolp);
// }

void	build_paths(t_bucket **ht, t_master *master, t_bfs *bfs)
{
	ft_printf("build paths\n");
	t_bucket	*new;
	t_bucket	*newer;
	t_lol		*lolq;

	new = NULL;
	lolq = NULL;
	newer = NULL;
	unshift_ll(&new, bfs->end);
	unshift_ll(&new, bfs->end);
	unshift_ll(&new, bfs->start);

	unshift_ll(&newer, bfs->start);
	unshift_ll(&newer, bfs->end);
	unshift_ll(&newer, bfs->start);

	print_ll(new);
	// ft_printf("new: %p\n", new);
	// pop_from_ll(&new);
	// pop_from_ll(&new);
	// pop_from_ll(&new);
	unshift_lol(&lolq, new);
	unshift_lol(&lolq, newer);
	pop_from_lol(&lolq);
	pop_from_lol(&lolq);

	ft_printf("end: %s\n", bfs->end->name);
	ft_printf("start: %s\n", bfs->start->name);
	// if (new)
	// {
	// 	ft_printf("Printing List\n");
	// 	print_ll(new);
	// }
	// else
	// 	ft_printf("no list to print\n");

	if (lolq)
	{
		ft_printf("Printing LOL\n");
		print_lol(lolq);
	}
	else
		ft_printf("no lol to print\n");
	// new = append_to_ll(new, bfs->goal);
	while (1)
	{
		
	}
	// ll_to_lol(que, new);
	// paths = execute_que(ht, master, bfs, que);
	// ft_printf("PRINTING LIST\n");
	// print_ll(new);
	// ft_printf("PRINTING QUE\n");
	// print_ll(bfs->bfs);
	// ft_printf("entry name: %s\n", new->entry->name);

	// print_lol(paths);

}