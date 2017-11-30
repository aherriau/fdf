/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 21:38:26 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/26 15:14:10 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_menu_1(t_env *e)
{
	e->ps0.x = 0;
	e->ps0.y = 0;
	e->ps1.x = 320;
	e->ps1.y = 1080;
	ft_color_image(e, 0x00C0C0C0, 2);
	e->ps0.x = 0;
	e->ps0.y = 0;
	e->ps1.x = 320;
	e->ps1.y = 80;
	ft_color_image(e, 0x00FFFFFF, 2);
	e->ps0.x = 30;
	e->ps0.y = 820;
	e->ps1.x = 260;
	e->ps1.y = 230;
	ft_color_image(e, 0x00FFFFFF, 2);
	e->ps0.x = 0;
	e->ps0.y = 79;
	e->ps1.x = 320;
	e->ps1.y = 2;
	ft_color_image(e, 0x00000000, 2);
	e->ps0.x = 0;
	e->ps0.y = 359;
	e->ps1.x = 320;
	e->ps1.y = 2;
	ft_color_image(e, 0x00000000, 2);
}

void	ft_menu_2(t_env *e)
{
	e->ps0.x = 0;
	e->ps0.y = 574;
	e->ps1.x = 320;
	e->ps1.y = 2;
	ft_color_image(e, 0x00000000, 2);
	e->ps0.x = 0;
	e->ps0.y = 789;
	e->ps1.x = 320;
	e->ps1.y = 2;
	ft_color_image(e, 0x00000000, 2);
	e->ps0.x = 80;
	e->ps0.y = 110;
	e->ps1.x = 160;
	e->ps1.y = 60;
	if (e->proj == AXO)
		ft_color_image(e, 0x00606060, 2);
	else
		ft_color_image(e, 0x00FFFFFF, 2);
}

void	ft_menu_3(t_env *e)
{
	e->ps0.x = 80;
	e->ps0.y = 190;
	e->ps1.x = 160;
	e->ps1.y = 60;
	if (e->proj == OBLI)
		ft_color_image(e, 0x00606060, 2);
	else
		ft_color_image(e, 0x00FFFFFF, 2);
	e->ps0.x = 80;
	e->ps0.y = 270;
	e->ps1.x = 160;
	e->ps1.y = 60;
	if (e->proj == CURVI)
		ft_color_image(e, 0x00606060, 2);
	else
		ft_color_image(e, 0x00FFFFFF, 2);
	e->ps0.x = 80;
	e->ps0.y = 390;
	e->ps1.x = 160;
	e->ps1.y = 60;
	if (e->color == 1)
		ft_color_image(e, 0x00606060, 2);
	else
		ft_color_image(e, 0x00FFFFFF, 2);
}

void	ft_menu_4(t_env *e)
{
	if (e->color_1 == 1)
	{
		e->ps0.x = 55;
		e->ps0.y = 480;
		e->ps1.x = 40;
		e->ps1.y = 70;
		ft_color_image(e, 0x00606060, 2);
	}
	e->ps0.x = 60;
	e->ps0.y = 485;
	e->ps1.x = 30;
	e->ps1.y = 30;
	ft_color_image(e, 0x00FFFFFF, 2);
	e->ps0.x = 60;
	e->ps0.y = 515;
	e->ps1.x = 30;
	e->ps1.y = 30;
	ft_color_image(e, 0x00000000, 2);
}

void	ft_display_menu(t_env *e)
{
	e->img2 = mlx_new_image(e->mlx, 320, 1080);
	if (e->img2 == NULL)
		exit(ft_error("Error\n"));
	e->data2 = mlx_get_data_addr(e->img2, &(e->bpp2), &(e->sl2), &(e->endian2));
	ft_menu_1(e);
	ft_menu_2(e);
	ft_menu_3(e);
	ft_menu_4(e);
	ft_menu_5(e);
	ft_menu_6(e);
	ft_menu_7(e);
	ft_menu_8(e);
	ft_menu_9(e);
	mlx_destroy_image(e->mlx, e->img2);
}
