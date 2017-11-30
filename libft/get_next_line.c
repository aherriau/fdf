/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 21:44:25 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/26 14:46:29 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_already_read(char **mem, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*mem)[i] != '\n')
		i++;
	*line = ft_strsub(*mem, 0, i);
	tmp = ft_strsub(*mem, i + 1, ft_strlen(*mem) - (i + 1));
	ft_strdel(mem);
	*mem = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (1);
}

int		ft_line_feed(char **mem, char **line, char *buff, int n)
{
	int		i;
	char	*prev;
	char	*current;

	i = 0;
	if ((*mem != NULL) && (ft_strlen(*mem) > 0))
	{
		prev = ft_strsub(*mem, 0, ft_strlen(*mem));
		while (buff[i] != '\n')
			i++;
		current = ft_strsub(buff, 0, i);
		*line = ft_strjoin(prev, current);
		ft_strdel(mem);
		ft_strdel(&prev);
		ft_strdel(&current);
		*mem = ft_strsub(buff, i + 1, n - (i + 1));
		return (1);
	}
	while (buff[i] != '\n')
		i++;
	*line = ft_strsub(buff, 0, i);
	ft_strdel(mem);
	*mem = ft_strsub(buff, i + 1, n - (i + 1));
	ft_strdel(&buff);
	return (1);
}

int		ft_read(const int fd, char **line, char **mem, int *readed)
{
	char		*buff;
	char		*tmp;
	int			n;

	buff = ft_strnew(BUFF_SIZE);
	*readed = 0;
	while ((n = read(fd, buff, BUFF_SIZE)) > 0)
	{
		*readed = 1;
		if (ft_strchr(buff, '\n') != NULL)
			return (ft_line_feed(mem, line, buff, n));
		if (*mem != NULL)
		{
			tmp = ft_strdup(*mem);
			ft_strdel(mem);
			*mem = ft_strjoin(tmp, buff);
			ft_strdel(&tmp);
		}
		else
			*mem = ft_strsub(buff, 0, ft_strlen(buff));
		ft_strdel(&buff);
		buff = ft_strnew(BUFF_SIZE);
	}
	ft_strdel(&buff);
	return (n);
}

int		get_next_line(const int fd, char **line)
{
	static char	*mem = NULL;
	int			readed;
	int			n;

	if ((fd <= -1) || (line == NULL))
		return (-1);
	if ((mem != NULL) && (ft_strchr(mem, '\n') != NULL))
		return (ft_already_read(&mem, line));
	n = ft_read(fd, line, &mem, &readed);
	if (n == 1)
		return (1);
	if ((readed == 1) || (mem != NULL && ft_strlen(mem) > 0))
	{
		*line = ft_strdup(mem);
		ft_strdel(&mem);
		return (1);
	}
	line = NULL;
	return (n);
}
