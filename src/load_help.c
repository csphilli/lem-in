/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 12:03:09 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/20 21:16:11 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	load_help(void)
{
	ft_printf("***********************************************************\n");
	ft_printf(" ___       ________  ____      ___           ___           \n");
	ft_printf("/  |      /  _____/ /    \\   /    \\         /__/  __     \n");
	ft_printf("|  |      |  |____  |  \\  \\ / /|  |  ______  __  /  /____ \n");
	ft_printf("|  |      |  ____/  |  |\\    / |  | /_____/ /  | |  __   |\n");
	ft_printf("|  |_____ |  |_____ |  | \\  /  |  |         |  | |  | |  |\n");
	ft_printf("|_______/ |_______/ |__/  \\/   |__/         |__| |__/ |__/\n");
	ft_printf("***********************************************************\n");
	write(1, "\n", 1);
	ft_printf("USAGE: ./lem-in -opt1 -opt2 < [input]\n");
	ft_printf("Flags are entered one at a time. Example: -a -b -c -l5\n");
	ft_printf("\n**** ALLOWED FLAGS ****\n\n");
	ft_printf("d: Enables visual illustration of ant distribution");
	ft_printf(" calculations.\n");
	ft_printf("h: Displays this help list.\n");
	ft_printf("p: Prints the list of all available paths found.\n");
	ft_printf("t: Displays the hash table.\n");
	exit(-1);
}
