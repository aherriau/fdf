/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:19:47 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/26 15:17:49 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_count_int(char *s, char c)
{
	int		index;
	int		index2;
	int		count;

	index = 0;
	count = 0;
	while (s[index] != '\0')
	{
		index2 = index;
		while ((s[index2] != '\0') && (s[index2] != c))
			index2++;
		if (s[index2] == '\0')
		{
			count++;
			return (count);
		}
		if ((s[index2] == c) && (index2 > index))
		{
			count++;
			index = index2;
		}
		index++;
	}
	return (count);
}

void	ft_update_map_dim(char *line, int *start, t_env *e)
{
	char	**tab;
	int		i;

	tab = ft_strsplit(line, ' ');
	i = 0;
	while (tab[i])
	{
		if (*start == 1)
		{
			*start = 0;
			e->alt_min = ft_atoi(tab[i]);
			e->alt_max = ft_atoi(tab[i]);
		}
		else
		{
			if (ft_atoi(tab[i]) < e->alt_min)
				e->alt_min = ft_atoi(tab[i]);
			if (ft_atoi(tab[i]) > e->alt_max)
				e->alt_max = ft_atoi(tab[i]);
		}
		i++;
	}
	ft_tabdel(tab);
	(e->height)++;
}

int		ft_get_map_dim(char *filename, t_env *e)
{
	char	*line;
	int		fd;
	int		start;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (-1);
	start = 1;
	while (get_next_line(fd, &line))
	{
		if (start)
			e->width = ft_count_int(line, ' ');
		else
		{
			if (ft_count_int(line, ' ') != e->width)
			{
				close(fd);
				ft_strdel(&line);
				return (0);
			}
		}
		ft_update_map_dim(line, &start, e);
		ft_strdel(&line);
	}
	close(fd);
	return (1);
}

void	ft_create_line(char *line, t_env *e, int **map, int i)
{
	char	**tab;
	int		j;

	tab = ft_strsplit(line, ' ');
	j = 0;
	while (j < e->width)
	{
		map[i][j] = ft_atoi(tab[j]);
		j++;
	}
	ft_tabdel(tab);
}

int		**ft_create_map(char *filename, t_env *e)
{
	int		**map;
	char	*line;
	int		fd;
	int		i;

	if ((map = (int **)malloc(sizeof(int *) * e->height)) == NULL)
		return (NULL);
	i = 0;
	while (i < e->height)
	{
		map[i] = (int *)malloc(sizeof(int) * e->width);
		if (map[i] == NULL)
			return (NULL);
		i++;
	}
	fd = open(filename, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		ft_create_line(line, e, map, i);
		ft_strdel(&line);
		i++;
	}
	close(fd);
	return (map);
}
