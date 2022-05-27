/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:49:20 by bgrulois          #+#    #+#             */
/*   Updated: 2022/05/10 17:44:41 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_paths(char **path_split, char *path)
{
	if (path)
		free(path);
	if (path_split)
		free_tab(path_split);
	return ;
}

int	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		if (tab[i] != NULL)
		{
			while (tab[i])
			{
				free(tab[i]);
				i++;
			}
		}
		free(tab);
		return (0);
	}
	return (-1);
}

char	**dup_tab(char **tab)
{
	char	**returntab;
	int		i;

	i = 0;
	returntab = NULL;
	if (!tab)
		return (returntab);
	while (tab[i])
		i++;
	returntab = malloc(sizeof(char *) * (i + 1));
	if (!returntab)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		returntab[i] = ft_strdup(tab[i]);
		i++;
	}
	returntab[i] = NULL;
	return (returntab);
}

void	clear_all(t_main_contents *main_save, t_pipex_file *infile,
		t_pipex_file *outfile, int here_doc)
{
	free_tab(main_save->av);
	free_tab(main_save->envp);
	free_tab(main_save->paths);
	free(main_save);
	close(infile->fd);
	if (here_doc == 1)
	{
		unlink(infile->path);
		free(infile->path);
	}
	free(infile);
	close(outfile->fd);
	free(outfile);
}

void	cmd_not_found(t_main_contents *ms, int i, char **path_split)
{
	char	*path;

	path = find_path(ms, i, path_split);
	if (path == NULL || path_split[0] == NULL)
	{
		write(2, ms->av[i], ft_strlen(ms->av[i]));
		write(2, " : command not found\n", 22);
	}
	free(path);
	return ;
}
