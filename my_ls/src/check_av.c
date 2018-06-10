/*
** EPITECH PROJECT, 2017
** ls
** File description:
** ls
*/

#include "my.h"
#include "my_ls.h"

void	struct_put_one(char option, t_arg *arg)
{
	switch (option) {
	case 'l':
		arg->opt_l = 1;
		break;
	case 'R':
		arg->opt_R = 1;
		break;
	case 'd':
		arg->opt_d = 1;
		break;
	case 'r':
		arg->opt_r = 1;
		break;
	case 't':
		arg->opt_t = 1;
		break;
	}
}

int	is_option(char option)
{
	char	*str = "lRdrt";
	int	a = 0;

	while (str[a]) {
		if (option == str[a])
			return (1);
		a++;
	}
	return (-1);
}

void	check_option(char *av, t_arg *arg)
{
	int	a = 0;

	while (av[a]) {
		if (is_option(av[a]) != -1)
			struct_put_one(av[a], arg);
		a++;
	}
}

int	check_av(char *av, t_arg *arg)
{
	DIR	*repo;

	if (av[0] == '-')
		check_option(av, arg);
	else if ((repo = opendir(av)) != NULL)
		arg->repo += 1;
	return (0);
}
