/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 21:35:13 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/26 13:35:28 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mouse_proj(int y, t_env *e)
{
	if (y >= 110 && y <= 170)
		e->proj = AXO;
	if (y >= 190 && y <= 250)
		e->proj = OBLI;
	if (y >= 270 && y <= 330)
		e->proj = CURVI;
	ft_reset_map(e);
	ft_display_map(e);
	ft_display_menu(e);
	ft_display_image(e);
}

void	ft_mouse_settings(int y, t_env *e)
{
	if (y >= 390 && y <= 450)
	{
		if (e->color == 0)
		{
			if (e->color_1 == 0 && e->color_2 == 0 &&
					e->color_3 == 0 && e->color_4 == 0)
				e->color_1 = 1;
			else
				e->color = 1;
		}
		else
			e->color = 0;
	}
	ft_display_map(e);
	ft_display_menu(e);
	ft_display_image(e);
}

int		ft_button_release_hook(int button, int x, int y, t_env *e)
{
	if (button == 1)
	{
		e->b1 = 0;
		e->p_b1.x = x;
		e->p_b1.y = y;
	}
	if (button == 2)
	{
		e->b2 = 0;
		e->p_b2.x = x;
		e->p_b2.y = y;
	}
	return (0);
}

void	ft_motion_notify_process(int x, int y, t_env *e)
{
	if (e->b2 == 1)
	{
		e->pad_x += x - e->p_b2.x;
		e->pad_y += y - e->p_b2.y;
		e->p_b2.x = x;
		e->p_b2.y = y;
		ft_display_map(e);
		ft_display_image(e);
	}
	if (x >= 10 && x <= 310 && y >= 591 && y <= 773)
	{
		e->image_show = 1;
		ft_display_menu(e);
		ft_display_image(e);
	}
	else
	{
		e->image_show = 0;
		ft_display_menu(e);
		ft_display_image(e);
	}
}

int		ft_motion_notify_hook(int x, int y, t_env *e)
{
	if (e->b1 == 1)
	{
		if (e->proj == AXO)
		{
			e->gamma += (y - e->p_b1.y) * (M_PI / 1024);
			e->omega += (e->p_b1.x - x) * (M_PI / 1024);
		}
		if (e->proj == OBLI)
			e->alpha += (x - e->p_b1.x) * (M_PI / 512);
		if (e->proj == CURVI)
			e->beta += (x - e->p_b1.x) * 0.1;
		e->p_b1.x = x;
		e->p_b1.y = y;
		ft_display_map(e);
		ft_display_image(e);
	}
	ft_motion_notify_process(x, y, e);
	return (0);
}
