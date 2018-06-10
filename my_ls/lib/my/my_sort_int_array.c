/*
** EPITECH PROJECT, 2017
** my_sort_int_array
** File description:
** task06
*/

#include "my.h"

void	my_sort_int_array(int *tab, int size)
{
	int	iter = 0;
	int	c = 0;

	while (iter < size) {
		c = iter + 1;
		while (c < size) {
			if (tab[iter] > tab[c])
				my_swap(&tab[iter], &tab[c]);
			c++;
		}
		iter++;
	}
}
