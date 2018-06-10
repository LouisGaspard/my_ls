/*
** EPITECH PROJECT, 2017
** my
** File description:
** my
*/

#ifndef __MY_LS_H_
#define __MY_LS_H_

#include <grp.h>
#include <sys/types.h>
#include <pwd.h>

typedef struct {
	int	opt_l;
	int	opt_R;
	int	opt_d;
	int	opt_r;
	int	opt_t;
	int	repo;
} t_arg;

void	my_ls(DIR *repo);
void	analyse_av(int ac, char **av);
t_arg	*init_struct();
int	check_av(char *av, t_arg *arg);
int	fill_arg(t_arg *arg, char **av, int ac);
void	print_type(mode_t sb);
void	print_right(mode_t sb);
void	print_link(nlink_t sb);
void	print_user(gid_t sb);
void	print_group(uid_t sb);
void	print_size(off_t sb);
void	print_time(time_t sb);
void	my_ls_option(t_arg *arg, char **av, int ac);
int	check_no_openable(int ac, char **av);
int	option_in_av(int ac, char **av);
void	my_ls_mult(int ac, char **av);
char	*my_path(char *str1, char *str2);
void	print_total(char *repo_name);
void	my_ls_recursive(DIR *repo);
void	my_ls_l_recursive(DIR *repo);
void	my_ls_recursive_bf(int ac, char **av);
int	my_ls_l(DIR *dir, char *repo);
struct stat my_stat(char *file);
void	my_ls_t(DIR *repo, char *str);
void	my_ls_d(char *str);
void	my_ls_l_recursive_bf(int ac, char **av);
void	my_ls_t_mult(int ac, char **av);
void	my_ls_d_mult(int ac, char **av);
void	my_ls_l_d_mult(int ac, char **av);
char	**tab_swap(int a, int b, char **tab);
void	my_ls_l_d(char *str);
void	my_ls_here(t_arg *arg, DIR *repo, char *str);
void	my_ls_l_one(char **av, int ac);
void	my_ls_l_mult(char **av, int ac);
long    my_difftime(time_t d1, time_t d2);

#endif
