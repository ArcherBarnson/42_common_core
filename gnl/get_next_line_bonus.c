/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 09:51:32 by bgrulois          #+#    #+#             */
/*   Updated: 2021/12/27 10:03:15 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	cleanstr(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		buf[i] = '\0';
		i++;
	}
}

void	rearrange(char *buf, int size)
{
	int	i;
	int	j;

	i = 0;
	size++;
	j = ft_strlen(buf) - size;
	while (i < j)
	{
		buf[i] = buf[size + i];
		i++;
	}
	buf[i] = '\0';
}

char	*strdupmod(char *src, char *dest)
{
	int	i;

	i = 0;
	while (src[i] != '\n' && src[i])
		i++;
	if (src[i] == '\n')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] != '\n' && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*read_and_check(int fd, char *buf)
{
	int	read_val;

	read_val = 0;
	if (!buf || fd < 0 || fd > 1023)
		return (NULL);
	if (buf[0] == '\0')
	{
		read_val = read(fd, buf, BUFFER_SIZE);
		if (read_val <= 0)
			return (NULL);
		buf[read_val] = '\0';
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	buf[1024][BUFFER_SIZE + 1];
	char		*returnstr;

	returnstr = NULL;
	if (read_and_check(fd, buf[fd]) == NULL)
		return (NULL);
	if (BUFFER_SIZE == 0)
		return (NULL);
	if (line_is_full(buf[fd]) != 0)
	{
		returnstr = strdupmod(buf[fd], returnstr);
		rearrange(buf[fd], get_line_size(buf[fd]));
	}
	else if (line_is_full(buf[fd]) == 0)
	{
		returnstr = strdupmod(buf[fd], returnstr);
		cleanstr(buf[fd]);
		return (malloc_free_cat(returnstr, get_next_line(fd)));
	}
	return (returnstr);
}
