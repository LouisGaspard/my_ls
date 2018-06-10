/*
** EPITECH PROJECT, 2017
** ls
** File description:
** ls
*/

#include "my.h"
#include "my_ls.h"

void	my_ls_d(char *repo_name)
{
	if (my_strcmp(repo_name, ".") == 0)
		my_printf(".\n");
	else
		my_printf("%s\n", repo_name);
}

void	my_ls_d_mult(int ac, char **av)
{
	DIR	*repo;
	int	a = 0;

	while (a != ac) {
		if ((repo = opendir(av[a])) != NULL) {
			my_ls_d(av[a]);
			closedir(repo);
		}
		a++;
	}
}

void	my_ls_l_d(char *repo_name)
{
	struct stat	sb;

	if (stat(repo_name, &sb) > 0)
		return;
	print_right(sb.st_mode);
	print_link(sb.st_nlink);
	print_user(sb.st_uid);
	print_group(sb.st_gid);
	print_size(sb.st_size);
	print_time(sb.st_mtime);
	my_printf("%s\n", repo_name);
}

void	my_ls_l_d_mult(int ac, char **av)
{
	DIR	*repo;
	int	a = 0;

	while (a != ac) {
		if ((repo = opendir(av[a])) != NULL)
			my_ls_l_d(av[a]);
		a++;
	}
}
