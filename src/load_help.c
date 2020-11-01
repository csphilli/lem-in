/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 12:03:09 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/01 19:47:28 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	load_help(t_master *master)
{
	ft_printf("***********************************************************\n");
	ft_printf(" ___       ________  ____      ___           ___           \n");
	ft_printf("/  |      /  _____/ /    \\   /    \\         /__/  __     \n");
	ft_printf("|  |      |  |____  |  \\  \\ / /|  |  ______  __  /  /____ \n");
	ft_printf("|  |      |  ____/  |  |\\    / |  | /_____/ /  | |  __   |\n");
	ft_printf("|  |_____ |  |_____ |  | \\  /  |  |         |  | |  | |  |\n");
	ft_printf("|_______/ |_______/ |__/  \\/   |__/         |__| |__/ |__/\n");
	ft_printf("***********************************************************\n");
	ft_printf("\n**** USAGE ****:\n\n");
	ft_printf("%8s '-f' flag:"CYAN" ./lem-in -opt1 -opt2 < [file-name]\n"\
	RESET, "WITHOUT");
	ft_printf("%8s '-f' flag:"CYAN" ./lem-in -opt1 -opt2 [file-name]\n"RESET\
	, "WITH");
	ft_printf("\t- Options are entered one at a time. Example: -a -b -c\n");
	ft_printf("\t- If '-f' is NOT used and no input file is specified\n");
	ft_printf("\tAcceptable options: %s\n", master->accepted_flags);
	ft_printf("\n**** OPTION FUNCTIONS ****\n\n");
	ft_printf("\tf: Allows to read from file. No '"CYAN"<"RESET"' needed.\n");
	ft_printf("\td: Prints the ant distribution on paths used for soloving.\n");
	ft_printf("\th: Displays this help list.\n");
	ft_printf("\tt: Displays the input of ant farm as hash table.\n");
	ft_printf("\ta: Prints the list of all available paths to choose from.\n");
	ft_printf("\tp: Prints the list of paths the program will use to solve.\n");
	exit(-1);
}
