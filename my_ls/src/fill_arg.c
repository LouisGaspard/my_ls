/*
** EPITECH PROJECT, 2017
** ls
** File description:
** ls
*/

#include "my.h"
#include "my_ls.h"

int	fill_arg(t_arg	*arg, char **av, int ac)
{
	int	a = 1;

	while (a != ac) {
		check_av(av[a], arg);
		a++;
	}
	return (0);
}
