/*
** EPITECH PROJECT, 2017
** ls
** File description:
** ls
*/

#include "my.h"
#include "my_ls.h"

char    **tab_swap(int  i, int j, char **tab)
{
	char    *str;

	str = my_strdup(tab[i]);
	free(tab[i]);
	tab[i] = malloc(sizeof(char) * my_strlen(tab[j]) + 1);
	tab[i] = my_strdup(tab[j]);
	free(tab[j]);
	tab[j] = malloc(sizeof(char) * my_strlen(str) + 1);
	tab[j] = my_strdup(str);
	return (tab);
}

struct stat my_stat(char *file)
{
	struct stat file_stats;

	if (stat(file, &file_stats) == 0)
		return (file_stats);
	return (file_stats);
}
