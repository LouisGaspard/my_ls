/*
** EPITECH PROJECT, 2017
** ls
** File description:
** ls
*/

#include "my.h"
#include "my_ls.h"

int	print_first_right(mode_t st_mode)
{
	if (S_ISDIR(st_mode) && !(S_ISLNK(st_mode)))
		return (my_printf("d"));
	if (S_ISLNK(st_mode))
		return (my_printf("l"));
	if (S_ISCHR(st_mode))
		return (my_printf("c"));
	if (S_ISBLK(st_mode))
		return (my_printf("b"));
	if (S_ISFIFO(st_mode))
		return (my_printf("p"));;
	if (S_ISSOCK(st_mode))
		return (my_printf("s"));
	return (my_printf("-"));
}

void	print_rwx(mode_t st_mode)
{
	my_printf((st_mode & S_IRUSR) ? ("r") : ("-"));
	my_printf((st_mode & S_IWUSR) ? ("w") : ("-"));
	if ((st_mode & S_ISUID) && !(st_mode & S_IXUSR))
		my_printf("S");
	else if ((st_mode & S_ISUID) && (st_mode & S_IXUSR))
		my_printf("s");
	else
		my_printf((st_mode & S_IXUSR) ? ("x") : ("-"));
	my_printf((st_mode & S_IRGRP) ? ("r") : ("-"));
	my_printf((st_mode & S_IWGRP) ? ("w") : ("-"));
}

void	print_right(mode_t st_mode)
{
	print_first_right(st_mode);
	print_rwx(st_mode);
	if ((st_mode & S_ISGID) && !(st_mode & S_IXGRP))
		my_printf("S");
	else if ((st_mode & S_ISGID) && (st_mode & S_IXGRP))
		my_printf("s");
	else
		my_printf((st_mode & S_IXGRP) ? ("x") : ("-"));
	my_printf((st_mode & S_IROTH) ? ("r") : ("-"));
	my_printf((st_mode & S_IWOTH) ? ("w") : ("-"));
	if ((st_mode & S_ISVTX) && !(st_mode & S_IXOTH))
		my_printf("T");
	else if ((st_mode & S_ISVTX) && (st_mode & S_IXOTH))
		my_printf("t");
	else
		my_printf((st_mode & S_IXOTH) ? ("x ") : ("- "));
}
