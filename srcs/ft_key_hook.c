/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:04:47 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/26 13:35:07 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_keypress_axo(int k, t_env *e)
{
	if (k == 125 || k == 126 || k == 123 || k == 124 || k == 24 || k == 27)
	{
		if (k == 125)
			e->gamma += e->theta;
		if (k == 126)
			e->gamma -= e->theta;
		if (k == 123)
			e->omega += e->theta;
		if (k == 124)
			e->omega -= e->theta;
		if (k == 24)
			e->scale_axo += e->scale_axo / 10;
		if (k == 27)
		{
			if ((e->scale_axo - e->scale_axo / 10) > 0)
				e->scale_axo -= e->scale_axo / 10;
		}
		ft_display_map(e);
		ft_display_image(e);
	}
}

void	ft_keypress_obli(int k, t_env *e)
{
	if (k == 123 || k == 124 || k == 24 || k == 27)
	{
		if (k == 123)
			e->alpha += e->theta;
		if (k == 124)
			e->alpha -= e->theta;
		if (k == 24)
			e->scale_obli += e->scale_obli / 10;
		if (k == 27)
		{
			if ((e->scale_obli - e->scale_obli / 10) > 0)
				e->scale_obli -= e->scale_obli / 10;
		}
		ft_display_map(e);
		ft_display_image(e);
	}
}

void	ft_keypress_curvi(int k, t_env *e)
{
	if (k == 123 || k == 124 || k == 24 || k == 27)
	{
		if (k == 123)
			e->beta += 1;
		if (k == 124)
			e->beta -= 1;
		if (k == 24)
			e->scale_curvi += e->scale_curvi / 10;
		if (k == 27)
		{
			if ((e->scale_curvi - e->scale_curvi / 10) > 0)
				e->scale_curvi -= e->scale_curvi / 10;
		}
		ft_display_map(e);
		ft_display_image(e);
	}
}

void	ft_keypress_setting(int k, t_env *e)
{
	if (k == 86 || k == 88 || k == 87 || k == 91 ||
			k == 69 || k == 78 || k == 76)
	{
		if (k == 86)
			e->pad_x -= 30;
		if (k == 88)
			e->pad_x += 30;
		if (k == 87)
			e->pad_y += 30;
		if (k == 91)
			e->pad_y -= 30;
		if (k == 69)
			e->alt += 0.1;
		if (k == 78)
			e->alt -= 0.1;
		if (k == 76)
			e->alt = 1;
		ft_display_map(e);
		ft_display_image(e);
	}
}

int		ft_keypress_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (e->proj == AXO)
		ft_keypress_axo(keycode, e);
	if (e->proj == OBLI)
		ft_keypress_obli(keycode, e);
	if (e->proj == CURVI)
		ft_keypress_curvi(keycode, e);
	ft_keypress_setting(keycode, e);
	return (0);
}
