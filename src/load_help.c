/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 12:03:09 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/19 12:47:38 by cphillip         ###   ########.fr       */
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
	ft_printf("l: Change the load factor of hash table. See below\n");
	ft_printf("\n**** Changing hash table load parameter ****\n\n");
	ft_printf("-l followed by positive int value.\n");
	ft_printf("Example: '-l5' changes load to 5. '-l10' changes to 10.\n\n");
	ft_printf("The load value is the hypothetical amount of links each index\n");
	ft_printf("can have at a given hash table size. It also affects the\n");
	ft_printf("space complexity. Lower value == higher space requirements.\n");
	exit(-1);
}
