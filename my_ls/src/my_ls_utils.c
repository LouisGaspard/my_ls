/*
** EPITECH PROJECT, 2017
** ls
** File description:
** ls
*/

#include "my.h"
#include "my_ls.h"

void    my_ls_option3(t_arg *arg, char **av, int ac)
{
	if (arg->repo >= 1 && arg->opt_d == 1 && arg->opt_l == 1) {
		my_ls_l_d_mult(ac, av);
		arg->opt_t = 0;
		arg->opt_l = 0;
	}
}

void    my_ls_option2(t_arg *arg, char **av, int ac)
{
	if (arg->repo >= 1 && arg->opt_R == 1 && arg->opt_l == 0) {
		check_no_openable(ac, av);
		my_ls_recursive_bf(ac, av);
		exit(0);
	}
	if (arg->repo >= 1 && arg->opt_R == 1 && arg->opt_l == 1) {
		check_no_openable(ac, av);
		my_ls_l_recursive_bf(ac, av);
		exit(0);
	}
	if (arg->repo >= 1 && arg->opt_t == 1) {
		my_ls_t_mult(ac, av);
		arg->opt_t = 0;
	}
	if (arg->repo >= 1 && arg->opt_d == 1 && arg->opt_l == 0) {
		my_ls_d_mult(ac, av);
		arg->opt_t = 0;
	}
	my_ls_option3(arg, av, ac);
}

void    my_ls_option(t_arg *arg, char **av, int ac)
{
	DIR     *repo;

	if (arg->repo == 0) {
		repo = opendir(".");
		my_ls_here(arg, repo, ".");
		closedir(repo);
		exit(0);
	}
	if (arg->repo == 1 && arg->opt_l == 1 && arg->opt_R == 0) {
		my_ls_l_one(av, ac);
		exit(0);
	}
	if (arg->repo > 1 && arg->opt_l == 1 && arg->opt_R == 0 &&
	    arg->opt_d == 0) {
		check_no_openable(ac, av);
		my_ls_l_mult(av, ac);
		exit(0);
	}
	my_ls_option2(arg, av, ac);
}
