/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 21:28:32 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/26 13:32:19 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_menu_5(t_env *e)
{
	if (e->color_2 == 1)
	{
		e->ps0.x = 111;
		e->ps0.y = 480;
		e->ps1.x = 40;
		e->ps1.y = 70;
		ft_color_image(e, 0x00606060, 2);
	}
	e->ps0.x = 116;
	e->ps0.y = 485;
	e->ps1.x = 30;
	e->ps1.y = 30;
	ft_color_image(e, 0x00FFFF00, 2);
	e->ps0.x = 116;
	e->ps0.y = 515;
	e->ps1.x = 30;
	e->ps1.y = 30;
	ft_color_image(e, 0x000000FF, 2);
}

void	ft_menu_6(t_env *e)
{
	if (e->color_3 == 1)
	{
		e->ps0.x = 167;
		e->ps0.y = 480;
		e->ps1.x = 40;
		e->ps1.y = 70;
		ft_color_image(e, 0x00606060, 2);
	}
	e->ps0.x = 172;
	e->ps0.y = 485;
	e->ps1.x = 30;
	e->ps1.y = 30;
	ft_color_image(e, 0x0000FF00, 2);
	e->ps0.x = 172;
	e->ps0.y = 515;
	e->ps1.x = 30;
	e->ps1.y = 30;
	ft_color_image(e, 0x00FF00FF, 2);
}

void	ft_menu_7(t_env *e)
{
	if (e->color_4 == 1)
	{
		e->ps0.x = 223;
		e->ps0.y = 480;
		e->ps1.x = 40;
		e->ps1.y = 70;
		ft_color_image(e, 0x00606060, 2);
	}
	e->ps0.x = 228;
	e->ps0.y = 485;
	e->ps1.x = 30;
	e->ps1.y = 30;
	ft_color_image(e, 0x00FF0000, 2);
	e->ps0.x = 228;
	e->ps0.y = 515;
	e->ps1.x = 30;
	e->ps1.y = 30;
	ft_color_image(e, 0x0000FFFF, 2);
}

void	ft_menu_8(t_env *e)
{
	if (e->image_show == 1)
	{
		e->ps0.x = 5;
		e->ps0.y = 586;
		e->ps1.x = 310;
		e->ps1.y = 192;
		ft_color_image(e, 0x00606060, 2);
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img2, 0, 0);
	mlx_string_put(e->mlx, e->win, 87, 30, 0x00000000, "FdF - MiniLibX");
	mlx_string_put(e->mlx, e->win, 50, 850, 0x00000000, " <  ^  > ");
	mlx_string_put(e->mlx, e->win, 50, 900, 0x00000000, " 4 5 6 8 ");
	mlx_string_put(e->mlx, e->win, 50, 950, 0x00000000, "  -   +  ");
	mlx_string_put(e->mlx, e->win, 50, 1000, 0x00000000, "- + Enter");
	mlx_string_put(e->mlx, e->win, 180, 850, 0x00000000, "Rotation");
	mlx_string_put(e->mlx, e->win, 180, 900, 0x00000000, "Movement");
	mlx_string_put(e->mlx, e->win, 180, 950, 0x00000000, "Zoom   ");
	mlx_string_put(e->mlx, e->win, 180, 1000, 0x00000000, "Altitude");
}

void	ft_menu_9(t_env *e)
{
	if (e->proj == AXO)
		mlx_string_put(e->mlx, e->win, 110, 130, 0x00FFFFFF, "Axonometric");
	else
		mlx_string_put(e->mlx, e->win, 110, 130, 0x00000000, "Axonometric");
	if (e->proj == OBLI)
		mlx_string_put(e->mlx, e->win, 125, 210, 0x00FFFFFF, "Oblique");
	else
		mlx_string_put(e->mlx, e->win, 125, 210, 0x00000000, "Oblique");
	if (e->proj == CURVI)
		mlx_string_put(e->mlx, e->win, 110, 290, 0x00FFFFFF, "Curvilinear");
	else
		mlx_string_put(e->mlx, e->win, 110, 290, 0x00000000, "Curvilinear");
	if (e->color == 1)
		mlx_string_put(e->mlx, e->win, 90, 410, 0x00FFFFFF, "Reverse Colors");
	else
		mlx_string_put(e->mlx, e->win, 90, 410, 0x00000000, "Reverse Colors");
}
