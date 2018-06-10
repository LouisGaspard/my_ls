/*
** EPITECH PROJECT, 2017
** ls
** File description:
** ls
*/

#include "my.h"
#include "my_ls.h"

t_arg	*init_struct(void)
{
	t_arg	*arg;

	if ((arg = malloc(sizeof(*arg))) == NULL)
		exit(84);;
	arg->opt_l = 0;
	arg->opt_R = 0;
	arg->opt_d = 0;
	arg->opt_r = 0;
	arg->opt_t = 0;
	return (arg);
}
