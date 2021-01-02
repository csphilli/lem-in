/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 12:03:09 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/02 16:16:42 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	load_help(void)
{
	ft_printf(BCYN);
	ft_printf("***********************************************************\n");
	ft_printf(" ___       ________  ____      ___           ___           \n");
	ft_printf("/  |      /  _____/ /    \\   /    \\         /__/  __     \n");
	ft_printf("|  |      |  |____  |  \\  \\ / /|  |  ______  __  /  /____ \n");
	ft_printf("|  |      |  ____/  |  |\\    / |  | /_____/ /  | |  __   |\n");
	ft_printf("|  |_____ |  |_____ |  | \\  /  |  |         |  | |  | |  |\n");
	ft_printf("|_______/ |_______/ |__/  \\/   |__/         |__| |__/ |__/\n");
	ft_printf("***********************************************************\n");
	ft_printf(RESET);
	write(1, "\n", 1);
	ft_printf("USAGE: ./lem-in -opt1 -opt2 < [input]\n");
	ft_printf("Flags are entered one at a time.\n");
	ft_printf("Example: ./lem-in -t -p -c < a_file\n");
	ft_printf(UCYN"\n**** ALLOWED FLAGS ****\n"RESET);
	ft_printf("c: Outputs timestamp of solving time. Used with time.sh\n");
	ft_printf("d: Enables a visual illustration of ant distribution\n");
	ft_printf("h: Displays this help list.\n");
	ft_printf("k: Performs a memory leak test at end of program\n");
	ft_printf("p: Prints the list of all available paths found.\n");
	ft_printf("q: Quiet mode. Eliminates map printing. Used with run.sh\n");
	ft_printf("t: Displays the hash table of graph.\n");
	exit(-1);
}
