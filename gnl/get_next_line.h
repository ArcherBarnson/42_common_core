/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:28:38 by bgrulois          #+#    #+#             */
/*   Updated: 2021/12/23 12:21:16 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int		ft_strlen(char *str);
int		get_line_size(char *buf);
int		line_is_full(char *buf);
char	*malloc_free_cat(char *src, char *returnstr);
void	cleanstr(char *buf);
void	rearrange(char *buf, int size);
char	*strdupmod(char *src, char *dest);
char	*read_and_check(int fd, char *buf);
char	*get_next_line(int fd);

#endif
