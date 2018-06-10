/*
** EPITECH PROJECT, 2017
** ls
** File description:
** ls
*/

#include "my.h"
#include "my_ls.h"

void	print_group(uid_t sb)
{
	struct group *group;

	if ((group = getgrgid(sb)))
		my_printf("%s", group->gr_name);
}
