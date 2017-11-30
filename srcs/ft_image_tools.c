/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 21:43:53 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/27 19:10:59 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_image(t_env *e, unsigned char *ptr, int x, int type)
{
	int		endian;

	if (type == 1)
		endian = e->endian;
	if (type == 2)
		endian = e->endian2;
	while ((e->dec)--)
		if (endian == e->local_endian)
		{
			if (endian)
				*(ptr + x * e->opp + e->dec) =
					((unsigned char *)(&(e->color2)))[4 - e->opp + e->dec];
			else
				*(ptr + x * e->opp + e->dec) =
					((unsigned char *)(&(e->color2)))[e->dec];
		}
		else
		{
			if (endian)
				*(ptr + x * e->opp + e->dec) =
					((unsigned char *)(&(e->color2)))[e->opp - 1 - e->dec];
			else
				*(ptr + x * e->opp + e->dec) =
					((unsigned char *)(&(e->color2)))[3 - e->dec];
		}
}

void	ft_color_image(t_env *e, int color, int type)
{
	int				x;
	int				y;
	unsigned char	*ptr;

	e->opp = e->bpp2 / 8;
	y = e->ps0.y;
	while (y < e->ps1.y + e->ps0.y)
	{
		ptr = (unsigned char *)(e->data2 + y * e->sl2);
		x = e->ps0.x;
		while (x < e->ps1.x + e->ps0.x)
		{
			e->color2 = mlx_get_color_value(e->mlx, color);
			e->dec = e->opp;
			ft_fill_image(e, ptr, x, type);
			x++;
		}
		y++;
	}
}

void	ft_segment(t_env *e, int type)
{
	if (e->color == 1 || e->color_1 == 1 || e->color_2 == 1 ||
			e->color_3 == 1 || e->color_4 == 1)
		ft_segment_color(e, type);
	else
		ft_segment_white(e, type);
}
