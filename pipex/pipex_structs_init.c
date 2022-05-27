/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_structs_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:57:02 by bgrulois          #+#    #+#             */
/*   Updated: 2022/05/10 17:47:48 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	here_doc_init(t_pipex_file *tmpfile, char *limiter, int i)
{
	int		fd;
	int		read_val;
	char	*tmp;
	char	*join_tmp;

	join_tmp = "/tmp/.";
	fd = open("/dev/random", O_RDONLY, 0644);
	read_val = read(fd, tmpfile->altpath, 10);
	if (read_val < 0)
		return (-1);
	while (tmpfile->altpath[++i])
	{
		if (tmpfile->altpath[i] == '/' || tmpfile->altpath[i] == 0)
			tmpfile->altpath[i] = '0';
	}
	close(fd);
	tmp = ft_strdup((char *) tmpfile->altpath);
	tmpfile->path = ft_strjoin(join_tmp, tmp);
	free(tmp);
	here_doc(tmpfile, limiter);
	return (0);
}

int	here_doc(t_pipex_file *tmpfile, char *limiter)
{
	char	*line;
	int		fd;

	limiter = ft_strjoin(limiter, "\n");
	line = get_next_line(0);
	fd = open((char *) tmpfile->path, O_WRONLY | O_CREAT | O_APPEND, 0666);
	while (ft_strncmp(line, limiter, ft_strlen(line)))
	{
		write(fd, line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
	}
	close(fd);
	free(line);
	free(limiter);
	return (0);
}

t_pipex_file	*files_handler(int mode, char **av, int ac, int hdoc)
{
	t_pipex_file		*file;
	int					i;

	i = -1;
	file = malloc((sizeof(t_pipex_file)));
	if (!file)
		return (NULL);
	file->altpath[10] = '\0';
	if (mode == 0)
	{
		if (hdoc == 0)
			file->path = av[1];
		if (hdoc == 1)
			here_doc_init(file, av[2], i);
		file->fd = open(file->path, O_RDONLY);
	}
	if (mode == 1)
	{
		file->path = av[ac - 1];
		if (hdoc == 0)
			file->fd = open(file->path, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (hdoc == 1)
			file->fd = open(file->path, O_CREAT | O_RDWR | O_APPEND, 0644);
	}
	return (file);
}

int	check_files(t_main_contents *ms, t_pipex_file *infile,
		t_pipex_file *outfile, int here_doc)
{
	int	err_code;

	err_code = 0;
	if (access(infile->path, R_OK) != 0)
	{
		perror(infile->path);
		err_code = -1;
	}
	if (access(outfile->path, W_OK) != 0
		|| access(outfile->path, R_OK) != 0)
	{
		perror(outfile->path);
		err_code = -2;
	}
	if (err_code == -2)
		clear_all(ms, infile, outfile, here_doc);
	return (err_code);
}
