/*
** EPITECH PROJECT, 2017
** ls
** File description:
** ls
*/

#include "my.h"
#include "my_ls.h"

char	*my_path(char *str1, char *str2)
{
	char	*dest;
	int	i = 0;
	int	j = 0;

	dest = malloc(sizeof(char) *
		(my_strlen(str1) + my_strlen(str2)) + 2);
	while (str1[i]) {
		dest[i] = str1[i];
		i++;
	}
	if (dest[i - 1] != '/') {
		dest[i] = '/';
		i++;
	}
	while (str2[j]) {
		dest[i + j] = str2[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}

void	print_total(char *repo_name)
{
	int		total = 0;
	struct stat	sb;
	struct dirent	*dir;
	char		*path;
	DIR		*repo;

	if ((repo = opendir(repo_name)) == NULL)
		return;
	while ((dir = readdir(repo))) {
		path = my_path(repo_name, dir->d_name);
		if ((lstat(path, &sb)) == 0)
			if (dir->d_name[0] != '.')
				total += sb.st_blocks;
	}
	closedir(repo);
	my_printf("total %d\n", total / 2);
}
