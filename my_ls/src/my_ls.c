/*
** EPITECH PROJECT, 2017
** ls
** File description:
** ls
*/

#include "my.h"
#include "my_ls.h"

int	option_in_av(int ac, char **av)
{
	int	a = 1;

	while (a != ac) {
		if (av[a][0] == '-')
			return (1);
		a++;
	}
	return (0);
}

int	check_no_openable(int ac, char **av)
{
	DIR	*repo;
	int	a = 1;
	int	b = 0;

	while (a != ac) {
		if (av[a][0] == '-') {
			a++;
			continue;
		}
		if ((repo = opendir(av[a])) == NULL) {
			my_printf("ls: cannot access '%s':", av[a]);
			my_printf("No such file or directory\n");
			b++;
			a++;
		} else {
			closedir(repo);
			a++;
		}
	}
	return (b);
}

void	my_ls_mult(int ac, char **av)
{
	int	a = 1;
	int	b = 0;
	DIR	*repo;

	b = check_no_openable(ac, av);
	while (a != ac) {
		if ((repo = opendir(av[a])) == NULL) {
			a++;
			b--;
			continue;
		}
		my_printf("%s:\n", av[a]);
		my_ls(repo);
		if (a + 1 + b != ac)
			my_printf("\n");
		a++;
	}
}

void	my_ls(DIR* repo)
{
	struct dirent	*d;

	while ((d = readdir(repo))) {
		if (d->d_name[0] != '.')
			my_printf("%s\n", d->d_name);
	}
	closedir(repo);
}
