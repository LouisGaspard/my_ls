/*
** EPITECH PROJECT, 2017
** ls
** File description:
** ls
*/

#include "my.h"
#include "my_ls.h"

long    my_difftime(time_t d1, time_t d2)
{
	return (d1 - d2);
}

void	print_time(time_t sb)
{
	int	a = 4;
	char	*time;

	time = ctime(&sb);
	while (time[a + 9]) {
		my_printf("%c", time[a]);
		a++;
	}
	my_printf(" ");
}
