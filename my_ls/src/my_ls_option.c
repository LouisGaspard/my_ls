/*
** EPITECH PROJECT, 2017
** ls
** File description:
** ls
*/

#include "my.h"
#include "my_ls.h"

int	my_ls_l(DIR *repo, char *repo_name)
{
	struct dirent	*dir;
	struct stat	sb;
	char		*str;

	print_total(repo_name);
	while ((dir = readdir(repo))) {
		if (dir->d_name[0] != '.') {
			str = my_path(repo_name, dir->d_name);
			stat(str, &sb);
			print_right(sb.st_mode);
			print_link(sb.st_nlink);
			print_user(sb.st_uid);
			print_group(sb.st_gid);
			print_size(sb.st_size);
			print_time(sb.st_mtime);
			my_printf("%s\n", dir->d_name);
		}
	}
	return (0);
}

void	my_ls_here2(t_arg *arg, DIR *repo, char *str)
{
	if (arg->opt_l == 1 && arg->opt_R == 1 && arg->opt_d == 0 &&
	    arg->opt_r == 0 && arg->opt_t == 0) {
		my_ls_l_recursive(repo);
		arg->opt_R = 0;
		arg->opt_l = 0;
	}
	if (arg->opt_l == 0 && arg->opt_R == 0 && arg->opt_d == 0 &&
	    arg->opt_r == 0 && arg->opt_t == 1) {
		my_ls_t(repo, str);
		arg->opt_t = 0;
	}
	if (arg->opt_l == 0 && arg->opt_R == 0 && arg->opt_d == 1 &&
	    arg->opt_r == 0 && arg->opt_t == 0) {
		my_ls_d(str);
		arg->opt_d = 0;
	}
}

void	my_ls_here(t_arg *arg, DIR *repo, char *str)
{
	if (arg->opt_l == 1 && arg->opt_R == 0 && arg->opt_d == 0 &&
			arg->opt_r == 0 && arg->opt_t == 0) {
		my_ls_l(repo, str);
		arg->opt_l = 0;
	}
	if (arg->opt_l == 0 && arg->opt_R == 1 && arg->opt_d == 0 &&
			arg->opt_r == 0 && arg->opt_t == 0) {
		my_ls_recursive(repo);
		arg->opt_R = 0;
	}
	if (arg->opt_l == 1 && arg->opt_R == 0 && arg->opt_d == 1 &&
			arg->opt_r == 0 && arg->opt_t == 0) {
		my_ls_l_d(str);
		arg->opt_d = 0;
		arg->opt_l = 0;
	}
	my_ls_here2(arg, repo, str);
}

void	my_ls_l_mult(char **av, int ac)
{
	DIR	*repo;
	int	a = 1;
	int	b = 0;

	while (a != ac) {
		if ((repo = opendir(av[a])) != NULL) {
			my_printf("%s:\n", av[a]);
			print_total(av[a]);
			my_ls_l(repo, av[a]);
			closedir(repo);
			if (a + b + 1 != ac)
				my_printf("\n");
		} else
			b++;
		a++;
	}
}

void	my_ls_l_one(char **av, int ac)
{
	DIR	*repo;
	int	a = 1;
	char	*str;

	while (a != ac) {
		if ((repo = opendir(av[a])) != NULL) {
			str = my_path(".", av[a]);
			print_total(str);
			my_ls_l(repo, str);
			closedir(repo);
		}
		a++;
	}
}
