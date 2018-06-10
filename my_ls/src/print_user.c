/*
** EPITECH PROJECT, 2017
** ls
** File description:
** ls
*/

#include "my.h"
#include "my_ls.h"

void	print_user(gid_t sb)
{
	struct passwd	*user;

	if ((user = getpwuid(sb)))
		my_printf("%s ", user->pw_name);
}
