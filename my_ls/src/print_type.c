/*
** EPITECH PROJECT, 2017
** ls
** File description:
** ls
*/

#include "my.h"
#include "my_ls.h"

void	print_type2(mode_t sb)
{
	switch (sb & S_IFMT) {
	case S_IFLNK:
		my_printf("l");
		break;
	case S_IFREG:
		my_printf("-");
		break;
	case S_IFSOCK:
		my_printf("s");
		break;
	default:
		my_printf("?");
		break;
	}
}

void	print_type(mode_t sb)
{
	switch (sb & S_IFMT) {
	case S_IFBLK:
		my_printf("b");
		break;
	case S_IFCHR:
		my_printf("c");
		break;
	case S_IFDIR:
		my_printf("d");
		break;
	case S_IFIFO:
		my_printf("p");
		break;
	}
	print_type2(sb);
}
