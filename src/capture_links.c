/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 12:16:07 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/08 10:18:46 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	**fill_array(char **src, char *new_link)
{
	char	**new;
	char	**tmp;
	int		len;
	int		i;

	tmp = src;
	new = NULL;
	len = 0;
	i = 0;
	while (*tmp++)
		len++;
	len += 2;
	if (!(new = (char**)malloc(sizeof(char*) * (len))))
		exit_malloc();
	init_link_arr(new, len);
	while (i < len - 2)
	{
		new[i] = ft_strdup(src[i]);
		i++;
	}
	new[i] = ft_strdup(new_link);
	free_strsplit(&src);
	src = NULL;
	return (new);
}

char	**insert_link(t_bucket *bucket, char *link)
{
	char	**arr;
	char	**tmp_arr;
	int		len;

	len = 0;
	tmp_arr = NULL;
	arr = NULL;
	if (!bucket->entry->link_arr)
	{
		if (!(arr = (char**)malloc(sizeof(char*) * 2)))
			exit_malloc();
		init_link_arr(arr, 2);
		arr[0] = ft_strdup(link);
	}
	else
	{
		tmp_arr = bucket->entry->link_arr;
		arr = fill_array(bucket->entry->link_arr, link);
	}
	return (arr);
}

void	search_for_room(t_bucket *bucket, char *link1, char *link2)
{
	t_bucket	*tmp;

	tmp = bucket;
	while(!ft_strequ(link1, tmp->entry->name) && tmp->next)
		tmp = tmp->next;
	if (tmp->next == NULL && !ft_strequ(link1, tmp->entry->name))
		exit_room_not_found(link1);
	else
	{
		bucket = tmp;
		bucket->entry->link_arr = insert_link(bucket, link2);
	}
}

void	add_link_to_room(t_bucket **ht, t_master *master, char *line)
{
	char		**data;
	int			index;	

	data = ft_strsplit(line, '-');

	index = gen_key(data[0]) % master->new_size;
	search_for_room(ht[index], data[0], data[1]);

	// ft_printf("index2: %d\n", index);
	// index = gen_key(data[1]) % master->new_size;
	// search_for_room(ht[index], data[1]);
	
	free_strsplit(&data);
	data = NULL;
	// ft_printf("link1: %s | link2: %s\n", data[0], data[1]);

	// ft_printf("%s\n", ht[0]->entry->name);
}