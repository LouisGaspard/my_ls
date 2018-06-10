/*
** EPITECH PROJECT, 2017
** ls
** File description:
** ls
*/

#include "my.h"
#include "my_ls.h"

char	*less_nl(char *str, char *repo_name)
{
	char	*dest = malloc(sizeof(char) * my_strlen(str) + 1);
	int	a = 0;

	while (str[a]) {
		dest[a] = str[a];
		a++;
	}
	dest[a] = '\0';
	repo_name = my_strcat(repo_name, "/");
	dest = my_strcat(repo_name, dest);
	return (dest);
}

char	**my_sort_t(int	nb_line, char **tab, char *repo_name)
{
	int	i = 0;
	int	sorted = 1;
	time_t	d1;
	time_t	d2;

	while (sorted) {
		sorted = 0;
		i = 0;
		while (i != nb_line - 1) {
			d1 = my_stat(less_nl(tab[i], repo_name)).st_mtime;
			d2 = my_stat(less_nl(tab[i + 1], repo_name)).st_mtime;
			if (my_difftime(d1, d2) > 0) {
				tab = tab_swap(i, i + 1, tab);
				sorted = 1;
			}
			i++;
		}
	}
	return (tab);
}

int	nb_line(char **tab)
{
	int	a = 0;

	while (tab[a])
		a++;
	return (a);
}

void	my_ls_t(DIR *repo, char *repo_name)
{
	struct dirent *d;
	char	*buffer;
	char	**tab;

	buffer = my_strdup("");
	while ((d = readdir(repo))) {
		if (d->d_name[0] != '.') {
			buffer = my_strcat(buffer, d->d_name);
			buffer = my_strcat(buffer, "\n");
		}
	}
	tab = my_str_to_word_array(buffer);
	tab = my_sort_t(nb_line(tab), tab, repo_name);
	my_show_word_array(tab);
}

void	my_ls_t_mult(int ac, char **av)
{
	int	a = 0;
	int	b = 0;
	DIR	*repo;

	while (a != ac) {
		if ((repo = opendir(av[a])) != NULL) {
			my_printf("%s:\n", av[a]);
			my_ls_t(repo, av[a]);
			closedir(repo);
			if (a + b + 1 != ac)
				my_printf("\n");
		} else
			b++;
		a++;
	}
}
