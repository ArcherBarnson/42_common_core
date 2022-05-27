/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:14:51 by bgrulois          #+#    #+#             */
/*   Updated: 2022/05/10 18:48:26 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	str_is_path(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

char	*find_path(t_main_contents *ms, int i, char **path_split)
{
	int		j;
	char	*tmp;
	char	*path;

	j = -1;
	if (str_is_path(ms->av[i]) == 1 && access(ms->av[i], X_OK) == 0)
		return (strdup(ms->av[i]));
	if (ms->paths && str_is_path(ms->av[i]) == 0)
	{
		while (ms->paths[++j])
		{
			path = ft_strjoin(ms->paths[j], "/");
			tmp = path;
			path = ft_strjoin(path, path_split[0]);
			free(tmp);
			if (access((const char *)path, X_OK) == 0)
				return (path);
			free(path);
		}
	}
	return (NULL);
}

int	pipes_main(int pipefd[2], t_main_contents *ms, int i, int fds[3])
{
	int		cpid;
	char	**path_split;
	char	*path;

	path_split = ft_split(ms->av[i], ' ');
	path = find_path(ms, i, path_split);
	cmd_not_found(ms, i, path_split);
	cpid = fork();
	if (cpid == 0)
	{
		if (ms->av[i + 2])
			close(pipefd[0]);
		dup2(fds[0], STDIN_FILENO);
		dup2(fds[1], STDOUT_FILENO);
		if (path == NULL || execve(path, path_split, ms->envp) == -1)
		{
			free_paths(path_split, path);
			return (-1);
		}
	}
	free_paths(path_split, path);
	return (0);
}

int	set_fds(t_main_contents *ms, int pipefd[2], int fds[3], int i)
{
	if (ms->av[i + 2])
	{
		if (pipe(pipefd) == -1)
			return (-1);
		if (i != ms->here_doc + 2)
			fds[0] = fds[2];
		fds[1] = pipefd[1];
		fds[2] = pipefd[0];
	}
	else
		fds[0] = fds[2];
	return (0);
}

int	pipes_arch(t_main_contents *ms, t_pipex_file *infile,
	t_pipex_file *outfile)
{
	int	i;
	int	pipefd[2];
	int	fds[3];

	i = ms->here_doc + 2 - 1;
	while (++i < ms->ac - 1)
	{
		if (i == ms->here_doc +2)
			fds[0] = infile->fd;
		if (!ms->av[i + 2])
			fds[1] = outfile->fd;
		if (set_fds(ms, pipefd, fds, i) == -1)
			return (-1);
		if (pipes_main(pipefd, ms, i, fds) == -1)
		{
			clear_all(ms, infile, outfile, ms->here_doc);
			exit(1);
		}
		close(fds[0]);
		close(fds[1]);
	}
	return (0);
}
