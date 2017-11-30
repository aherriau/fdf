/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_tools_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:24 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/26 13:34:05 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_process_segment(t_env *e, int color, int type)
{
	unsigned char	*ptr;

	e->opp = e->bpp / 8;
	ptr = (unsigned char *)(e->data + (int)e->ps2.y * e->sl);
	e->color2 = mlx_get_color_value(e->mlx, color);
	e->dec = e->opp;
	ft_fill_image(e, ptr, e->ps2.x, type);
}

void	ft_process_color(t_env *e, int length)
{
	double	pas;
	double	z0;
	double	z1;

	e->ps2.x = e->ps0.x;
	e->ps2.y = e->ps0.y;
	if (e->alt_max == e->alt_min)
		pas = 0;
	else
		pas = 255 / (e->alt_max - e->alt_min);
	z0 = e->ps0.z * pas;
	z1 = e->ps1.z * pas;
	e->decal = (z1 - z0) / length;
	e->count = z0;
}

int		ft_switch_color(t_env *e)
{
	if (e->color == 1)
	{
		if (e->color_1 == 1)
			return (ft_get_color(255 - e->count, 255 - e->count,
						255 - e->count));
		else if (e->color_2 == 1)
			return (ft_get_color(255 - e->count, 255 - e->count, e->count));
		else if (e->color_3 == 1)
			return (ft_get_color(e->count, 255 - e->count, e->count));
		else if (e->color_4 == 1)
			return (ft_get_color(255 - e->count, e->count, e->count));
		else
			return (ft_get_color(e->count, e->count, e->count));
	}
	else
	{
		if (e->color_1 == 1)
			return (ft_get_color(e->count, e->count, e->count));
		else if (e->color_2 == 1)
			return (ft_get_color(e->count, e->count, 255 - e->count));
		else if (e->color_3 == 1)
			return (ft_get_color(255 - e->count, e->count, 255 - e->count));
		else
			return (ft_get_color(e->count, 255 - e->count, 255 - e->count));
	}
}

void	ft_segment_color(t_env *e, int type)
{
	double			length;
	double			addx;
	double			addy;
	int				i;
	int				color;

	e->ps2.x = e->ps1.x - e->ps0.x;
	e->ps2.y = e->ps1.y - e->ps0.y;
	length = sqrt(e->ps2.x * e->ps2.x + e->ps2.y * e->ps2.y);
	addx = e->ps2.x / length;
	addy = e->ps2.y / length;
	ft_process_color(e, length);
	i = 0;
	while (i < length)
	{
		if (e->ps2.x > 0 && e->ps2.x < 1600 && e->ps2.y > 0 && e->ps2.y < 1080)
		{
			color = ft_switch_color(e);
			e->count += e->decal;
			ft_process_segment(e, color, type);
		}
		e->ps2.x += addx;
		e->ps2.y += addy;
		i++;
	}
}

void	ft_segment_white(t_env *e, int type)
{
	double			length;
	double			addx;
	double			addy;
	int				i;
	int				color;

	e->ps2.x = e->ps1.x - e->ps0.x;
	e->ps2.y = e->ps1.y - e->ps0.y;
	length = sqrt(e->ps2.x * e->ps2.x + e->ps2.y * e->ps2.y);
	addx = e->ps2.x / length;
	addy = e->ps2.y / length;
	e->ps2.x = e->ps0.x;
	e->ps2.y = e->ps0.y;
	i = 0;
	while (i < length)
	{
		if (e->ps2.x > 0 && e->ps2.x < 1600 && e->ps2.y > 0 && e->ps2.y < 1080)
		{
			color = ft_get_color(255, 255, 255);
			ft_process_segment(e, color, type);
		}
		e->ps2.x += addx;
		e->ps2.y += addy;
		i++;
	}
}
