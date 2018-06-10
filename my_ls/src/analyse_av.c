/*
** EPITECH PROJECT, 2017
** ls
** File description:
** ls
*/

#include "my.h"
#include "my_ls.h"

char    *path_file(char *repo, char *file)
{
	char            *str;

	str = malloc(sizeof(char) * my_strlen(repo) * 5 + 1);
	str[0] = '.';
	str[1] = '\0';
	str = my_strcat(str, "/");
	str = my_strcat(str, file);
	return (str);
}

void	analyse_av(int ac, char **av)
{
	DIR	*repo;
	t_arg	*arg;

	arg = init_struct();
	if (ac == 2 && av[1][0] != '-') {
		if ((repo = opendir(av[1])) == NULL) {
			my_printf("ls: cannot access '%s':", av[1]);
			my_printf("No such file or directory\n");
			exit(84);
		}
		my_ls(repo);
		exit(0);
	}
	if (ac >= 2 && option_in_av(ac, av) == 0) {
		my_ls_mult(ac, av);
		exit(0);
	}
	if (ac >= 2) {
		fill_arg(arg, av, ac);
		my_ls_option(arg, av, ac);
	}
}
