/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:53:27 by bgrulois          #+#    #+#             */
/*   Updated: 2022/05/10 19:41:51 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_handling(int ac, char **av)
{
	int	hdoc;

	hdoc = 0;
	if (!av[0] || ac != 5)
	{
		write(2, "Error : Incorrect number of arguments\n", 38);
		return (-1);
	}
	return (hdoc);
}

t_main_contents	*save_main_args(int ac, char **av, char **envp, int here_doc)
{
	t_main_contents		*main_save;
	int					i;

	main_save = malloc(sizeof(t_main_contents));
	if (!main_save)
		return (NULL);
	main_save->ac = ac;
	main_save->here_doc = here_doc;
	main_save->av = dup_tab(av);
	main_save->envp = dup_tab(envp);
	i = -1;
	while (envp[++i])
	{
		if (strncmp(PATH, envp[i], 4) == 0)
			break ;
	}
	main_save->paths = ft_split(envp[i], ':');
	return (main_save);
}

int	main(int ac, char **av, char **envp)
{
	int					i;
	int					here_doc;
	t_pipex_file		*infile;
	t_pipex_file		*outfile;
	t_main_contents		*main_save;

	i = -1;
	infile = NULL;
	outfile = NULL;
	here_doc = error_handling(ac, av);
	if (here_doc == -1)
		return (-1);
	infile = files_handler(0, av, ac, here_doc);
	outfile = files_handler(1, av, ac, here_doc);
	main_save = save_main_args(ac, av, envp, here_doc);
	if (check_files(main_save, infile, outfile, here_doc) == -2)
		return (-1);
	if (pipes_arch(main_save, infile, outfile) == -1)
		return (-1);
	i = ac - 3 - here_doc;
	while (i-- > 0)
		wait(NULL);
	clear_all(main_save, infile, outfile, here_doc);
	return (0);
}
