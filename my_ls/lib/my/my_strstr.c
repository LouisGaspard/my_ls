/*
** EPITECH PROJECT, 2017
** strstr
** File description:
** strstr
*/

#include "my.h"

char	*my_strstr(char *str, char const *to_find)
{
	int	a = 0;
	int	b = 0;
	int	c = my_strlen(to_find);

	while (str[a]) {
		if (str[a] == to_find[b]) {
			while (str[a] == to_find[b] && to_find[b]) {
				a++;
				b++;
			}
			if (c == b)
				return (&str[a - c]);
		}
		a++;
	}
	return (0);
}
