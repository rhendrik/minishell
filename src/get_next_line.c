/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:45:59 by rhendrik          #+#    #+#             */
/*   Updated: 2019/08/20 11:43:29 by rhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/get_next_line.h"
#include "../libft/libft.h"

static void	set_str(char *s[], char *tmp, const int fd)
{
	ft_strdel(&s[fd]);
	s[fd] = ft_strdup(tmp);
	ft_strdel(&tmp);
}

static int	has_read(char *s[], char *tmp, const int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		has_read;

	if ((has_read = read(fd, buf, BUFF_SIZE)) == 0)
		return (0);
	buf[has_read] = '\0';
	tmp = ft_strjoin(s[fd], buf);
	set_str(s, tmp, fd);
	return (1);
}

static int	single_line(char *s[], char **line, const int fd)
{
	*line = ft_strdup(s[fd]);
	ft_strclr(s[fd]);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*s[1024];
	char		*tmp;
	char		*ptr;

	tmp = NULL;
	if (line == NULL || fd < 0 || read(fd, buff, 0) < 0)
		return (-1);
	if (!s[fd])
		s[fd] = ft_strnew(0);
	while ((ptr = ft_strchr(s[fd], '\n')) == NULL)
		if ((has_read(s, tmp, fd)) == 0)
			break ;
	if (ft_strlen(s[fd]) != 0)
	{
		if (!(ft_strchr(s[fd], '\n')))
			return (single_line(s, &*line, fd));
		*ptr = '\0';
		tmp = ft_strdup(ptr + 1);
		*line = ft_strdup(s[fd]);
		set_str(s, tmp, fd);
	}
	else
		return (0);
	return (1);
}
