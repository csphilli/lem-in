/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 12:03:09 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/06 08:40:17 by cphillip         ###   ########.fr       */
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
	ft_printf("\tOptions are entered one at a time. Example: -a -b -c\n");
	ft_printf("\tAcceptable options: %s\n", master->accepted_flags);
	ft_printf("\n**** OPTION FUNCTIONS ****\n\n");
	ft_printf("\ta: I don't know at this time\n");
	ft_printf("\tc: Adds highlighting to important areas of the output.\n");
	ft_printf("\td: Debugger. Outputs text in key locations to assist with");
	ft_printf(" program creation.\n");
	ft_printf("\te: Allows output of more descriptive error messages.\n");
	ft_printf("\tf: Allows to read from file. No '"CYAN"<"RESET"' needed.\n");
	ft_printf("\th: Displays this help list.\n");
	exit(-1);
}
