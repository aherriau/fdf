/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:18:05 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/26 13:35:18 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_button_1_process(int x, int y, t_env *e)
{
	if (x >= 320 && x <= 1920 && y >= 0 && y <= 1080)
	{
		e->b1 = 1;
		e->p_b1.x = x;
		e->p_b1.y = y;
	}
	if (x >= 10 && x <= 310 && y >= 591 && y <= 773)
	{
		if (e->image == 0)
			e->image = 1;
		else
			e->image = 0;
		ft_display_menu(e);
		ft_display_image(e);
	}
}

void	ft_button_1(int x, int y, t_env *e)
{
	if (x >= 80 && x <= 240)
	{
		if ((y >= 110 && y <= 170) || (y >= 190 && y <= 250) ||
				(y >= 270 && y <= 330))
			ft_mouse_proj(y, e);
		if (y >= 390 && y <= 450)
			ft_mouse_settings(y, e);
	}
	if (y >= 485 && y <= 545)
		if ((x >= 60 && x <= 90) || (x >= 116 && x <= 146) ||
				(x >= 172 && x <= 202) || (x >= 228 && x <= 258))
			ft_mouse_color(x, e);
	ft_button_1_process(x, y, e);
}

void	ft_button_4(int x, int y, t_env *e)
{
	if (x >= 320 && x <= 1920 && y >= 0 && y <= 1080)
	{
		if (e->proj == AXO)
			e->scale_axo += e->scale_axo / 10;
		if (e->proj == OBLI)
			e->scale_obli += e->scale_obli / 10;
		if (e->proj == CURVI)
			e->scale_curvi += e->scale_curvi / 10;
		ft_display_map(e);
		ft_display_image(e);
	}
}

void	ft_button_5(int x, int y, t_env *e)
{
	if (x >= 320 && x <= 1920 && y >= 0 && y <= 1080)
	{
		if (e->proj == AXO)
		{
			if ((e->scale_axo - e->scale_axo / 10) > 0)
				e->scale_axo -= e->scale_axo / 10;
		}
		if (e->proj == OBLI)
		{
			if ((e->scale_obli - e->scale_obli / 10) > 0)
				e->scale_obli -= e->scale_obli / 10;
		}
		if (e->proj == CURVI)
		{
			if ((e->scale_curvi - e->scale_curvi / 10) > 0)
				e->scale_curvi -= e->scale_curvi / 10;
		}
		ft_display_map(e);
		ft_display_image(e);
	}
}

int		ft_button_press_hook(int button, int x, int y, t_env *e)
{
	if (button == 1)
		ft_button_1(x, y, e);
	if (button == 2)
	{
		if (x >= 320 && x <= 1920 && y >= 0 && y <= 1080)
		{
			e->b2 = 1;
			e->p_b2.x = x;
			e->p_b2.y = y;
		}
	}
	if (button == 4)
		ft_button_4(x, y, e);
	if (button == 5)
		ft_button_5(x, y, e);
	return (0);
}
