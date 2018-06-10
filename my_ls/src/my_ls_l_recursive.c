/*
** EPITECH PROJECT, 2017
** ls
** File description:
** ls
*/

#include "my.h"
#include "my_ls.h"

void	ls_lr(char *repo)
{
	char		*str;
	DIR		*dir;
	struct dirent	*d;
	struct stat	sb;

	my_printf("\n%s:\n", repo);
	dir = opendir(repo);
	my_ls_l(dir, repo);
	dir = opendir(repo);
	while ((d = readdir(dir))) {
		if (d->d_name[0] != '.') {
			str = my_path(repo, d->d_name);
			if (stat(str, &sb) > 0)
				return;
			if (S_ISDIR(sb.st_mode))
				ls_lr(str);
			else
				continue;
		}
	}
}

void	ls_lr_mult(char *repo)
{
	char		*str;
	DIR		*dir;
	struct dirent	*d;
	struct stat	sb;

	if (!(dir = opendir(repo)))
		return;
	else
		my_printf("%s:\n", repo);
	my_ls_l(dir, repo);
	dir = opendir(repo);
	while ((d = readdir(dir))) {
		if (d->d_name[0] != '.') {
			str = my_path(repo, d->d_name);
			if (stat(str, &sb) > 0)
				return;
			if (S_ISDIR(sb.st_mode)) {
				my_printf("\n");
				ls_lr_mult(str);
			} else
				continue;
		}
	}
}

void	is_dir_lr(char *repo)
{
	struct stat	sb;

	if (stat(repo, &sb) > 0)
		return;
	if (S_ISDIR(sb.st_mode))
		ls_lr(repo);
	else
		return;
}

void	my_ls_l_recursive(DIR *repo)
{
	struct dirent	*dir;

	while ((dir = readdir(repo))) {
		if (dir->d_name[0] != '.')
			continue;
		if (dir->d_name[1] != '.' && dir->d_name[1] != 'g')
			is_dir_lr(dir->d_name);
	}
}

void	my_ls_l_recursive_bf(int ac, char **av)
{
	int	a = 1;
	int	b = 0;
	DIR	*repo;

	while (a != ac) {
		if ((repo = opendir(av[a])) != NULL) {
			if (b != 0)
				my_printf("\n");
			b++;
			ls_lr_mult(av[a]);
			closedir(repo);
		}
		a++;
	}
}
