/*
** EPITECH PROJECT, 2017
** strdup
** File description:
** strdup
*/

#include "my.h"

char	*my_strdup(char const *str)
{
	char	*dest = malloc(sizeof(*str) * my_strlen(str) + 1);
	int	a = 0;

	while (str[a]) {
		dest[a] = str[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}
