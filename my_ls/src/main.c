/*
** EPITECH PROJECT, 2017
** ls
** File description:
** ls
*/

#include "my.h"
#include "my_ls.h"

int	main(int ac, char **av)
{
	DIR *repertoire;

	if (ac == 1) {
		repertoire = opendir(".");
		my_ls(repertoire);
	}
	else
		analyse_av(ac, av);
	return (0);
}
