/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:02:59 by bgrulois          #+#    #+#             */
/*   Updated: 2022/05/10 17:25:42 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define READ_FROM 0
# define WRITE_TO 1
# define PATH "PATH"
# define BUFFER_SIZE 1

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>

typedef struct s_pipex_file
{
	int				fd;
	char			*path;
	unsigned char	altpath[10];
}		t_pipex_file;

typedef struct s_main_contents
{
	int		here_doc;
	int		ac;
	char	**av;
	char	**envp;
	char	**paths;
}		t_main_contents;

char			**ft_split(char const *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(char *src);
int				ft_strncmp(const char	*s1, const char *s2, size_t n);
size_t			ft_strlen(char *str);
int				get_line_size(char *buf);
int				line_is_full(char *buf);
char			*malloc_free_cat(char *src, char *returnstr);
void			cleanstr(char *buf);
void			rearrange(char *buf, int size);
char			*strdupmod(char *src, char *dest);
char			*read_and_check(int fd, char *buf);
char			*get_next_line(int fd);
t_pipex_file	*files_handler(int mode, char **av, int ac, int here_doc);
int				check_files(t_main_contents *ms, t_pipex_file *infile,
					t_pipex_file *outfile, int here_doc);
void			cmd_not_found(t_main_contents *ms, int i, char **path_split);
char			*find_path(t_main_contents *main_save, int i,
					char **path_split);
int				pipes_main(int pipefd[2], t_main_contents *main_save,
					int i, int fds[3]);
int				set_fds(t_main_contents *ms, int pipefd[2], int fds[3], int i);
int				pipes_arch(t_main_contents *main_contents, t_pipex_file *infile,
					t_pipex_file *outfile);
int				here_doc_init(t_pipex_file *tmpfile, char *limiter, int i);
int				here_doc(t_pipex_file *tmpfile, char *limiter);
char			**dup_tab(char **tab);
int				free_tab(char **tab);
void			free_paths(char **path_split, char *path);
void			clear_all(t_main_contents *main_save, t_pipex_file *infile,
					t_pipex_file *outfile, int here_doc);
t_main_contents	*save_main_args(int ac, char **av, char **envp, int here_doc);
int				error_handling(int ac, char **av);

#endif
