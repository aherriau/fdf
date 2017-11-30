/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_axo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:43:36 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/26 13:30:45 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_p0_axo(t_env *e, int i, int j)
{
	e->p0.x = j - e->x_grav;
	e->p0.y = i - e->y_grav;
	e->p0.z = (e->map[i][j] * e->alt) - e->z_grav;
	e->proj_p0.x = cos(e->omega) * e->p0.x - sin(e->omega) * e->p0.y;
	e->proj_p0.y = sin(e->omega) * sin(e->gamma) * e->p0.x +
		cos(e->omega) * sin(e->gamma) * e->p0.y - cos(e->gamma) * e->p0.z;
	e->ps0.x = e->pad_x + e->proj_p0.x * e->scale_axo;
	e->ps0.y = e->pad_y + e->proj_p0.y * e->scale_axo;
	e->ps0.z = e->map[i][j];
}

void	ft_p1_axo(t_env *e, int i, int j)
{
	e->p1.x = j - e->x_grav;
	e->p1.y = i - e->y_grav;
	e->p1.z = (e->map[i][j] * e->alt) - e->z_grav;
	e->proj_p1.x = cos(e->omega) * e->p1.x - sin(e->omega) * e->p1.y;
	e->proj_p1.y = sin(e->omega) * sin(e->gamma) * e->p1.x +
		cos(e->omega) * sin(e->gamma) * e->p1.y - cos(e->gamma) * e->p1.z;
	e->ps1.x = e->pad_x + e->proj_p1.x * e->scale_axo;
	e->ps1.y = e->pad_y + e->proj_p1.y * e->scale_axo;
	e->ps1.z = e->map[i][j];
}

void	ft_display_axo(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->height)
	{
		j = 0;
		while (j < e->width)
		{
			ft_p0_axo(e, i, j);
			if ((j + 1) < e->width)
			{
				ft_p1_axo(e, i, j + 1);
				ft_segment(e, 1);
			}
			if ((i + 1) < e->height)
			{
				ft_p1_axo(e, i + 1, j);
				ft_segment(e, 1);
			}
			j++;
		}
		i++;
	}
}

double	ft_scale_axo(t_env *e)
{
	int		i;
	int		j;
	double	max_x;
	double	max_y;
	double	scale;

	max_x = 1;
	max_y = 1;
	i = 0;
	while (i < e->height)
	{
		j = 0;
		while (j < e->width)
		{
			ft_p0_axo(e, i, j);
			if (fabs(e->proj_p0.x) > max_x)
				max_x = fabs(e->proj_p0.x);
			if (fabs(e->proj_p0.y) > max_y)
				max_y = fabs(e->proj_p0.y);
			j++;
		}
		i++;
	}
	scale = fmin(660 / max_x, 440 / max_y);
	return (scale);
}
