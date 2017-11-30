/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 21:38:41 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/26 15:35:01 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mouse_color_1(int x, t_env *e)
{
	if (x >= 60 && x <= 90)
	{
		if (e->color_1 == 0)
		{
			e->color_1 = 1;
			e->color_2 = 0;
			e->color_3 = 0;
			e->color_4 = 0;
		}
		else
		{
			e->color_1 = 0;
			e->color = 0;
		}
	}
}

void	ft_mouse_color_2(int x, t_env *e)
{
	if (x >= 116 && x <= 146)
	{
		if (e->color_2 == 0)
		{
			e->color_1 = 0;
			e->color_2 = 1;
			e->color_3 = 0;
			e->color_4 = 0;
		}
		else
		{
			e->color_2 = 0;
			e->color = 0;
		}
	}
}

void	ft_mouse_color_3(int x, t_env *e)
{
	if (x >= 172 && x <= 202)
	{
		if (e->color_3 == 0)
		{
			e->color_1 = 0;
			e->color_2 = 0;
			e->color_3 = 1;
			e->color_4 = 0;
		}
		else
		{
			e->color_3 = 0;
			e->color = 0;
		}
	}
}

void	ft_mouse_color_4(int x, t_env *e)
{
	if (x >= 228 && x <= 258)
	{
		if (e->color_4 == 0)
		{
			e->color_1 = 0;
			e->color_2 = 0;
			e->color_3 = 0;
			e->color_4 = 1;
		}
		else
		{
			e->color_4 = 0;
			e->color = 0;
		}
	}
}

void	ft_mouse_color(int x, t_env *e)
{
	ft_mouse_color_1(x, e);
	ft_mouse_color_2(x, e);
	ft_mouse_color_3(x, e);
	ft_mouse_color_4(x, e);
	ft_display_map(e);
	ft_display_menu(e);
	ft_display_image(e);
}
