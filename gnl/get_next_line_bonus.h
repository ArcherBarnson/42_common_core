/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:18:00 by bgrulois          #+#    #+#             */
/*   Updated: 2021/12/23 14:19:11 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
char	*get_next_line_bonus(int fd);

#endif
