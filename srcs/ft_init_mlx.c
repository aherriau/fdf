/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:20:41 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/27 21:33:22 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_expose_hook(t_env *e)
{
	ft_display_map(e);
	ft_display_menu(e);
	ft_display_image(e);
	return (0);
}

void	ft_init_hook(t_env *e)
{
	e->scale_axo = ft_scale_axo(e);
	e->scale_obli = ft_scale_obli(e);
	e->scale_curvi = ft_scale_curvi(e);
	mlx_hook(e->win, KEYPRESS, KEYPRESSMASK, ft_keypress_hook, e);
	mlx_hook(e->win, BUTTONPRESS, BUTTONPRESSMASK, ft_button_press_hook, e);
	mlx_hook(e->win, BUTTONRELEASE, BUTTONRELEASEMASK,
			ft_button_release_hook, e);
	mlx_hook(e->win, MOTIONNOTIFY, BUTTONMOTIONMASK, ft_motion_notify_hook, e);
	mlx_expose_hook(e->win, ft_expose_hook, e);
}

void	ft_init_env(t_env *e)
{
	int		a;

	a = 0x11223344;
	if (((unsigned char *)&a)[0] == 0x11)
		e->local_endian = 1;
	else
		e->local_endian = 0;
	e->color = 0;
	e->color_1 = 0;
	e->color_2 = 0;
	e->color_3 = 0;
	e->color_4 = 0;
	e->image = 0;
	e->image_show = 0;
	e->x_grav = (double)(e->width - 1) / 2;
	e->y_grav = (double)(e->height - 1) / 2;
	e->z_grav = (double)(e->alt_min + e->alt_max) / 2;
	e->pad_x = 700;
	e->pad_y = 540;
	e->alt = 1;
	e->theta = M_PI / 32;
	e->omega = (5 * M_PI) / 32;
	e->gamma = (5 * M_PI) / 32;
	e->alpha = 1;
	e->beta = 10;
}

int		ft_init_mlx(t_env *e, char *filename)
{
	char	*name;

	name = ft_strjoin("fdf: ", filename);
	e->mlx = mlx_init();
	if (e->mlx == NULL)
		return (0);
	e->win = mlx_new_window(e->mlx, 1920, 1080, name);
	if (e->win == NULL)
		return (0);
	ft_strdel(&name);
	e->map = ft_create_map(filename, e);
	if (e->map == NULL)
		return (0);
	e->proj = AXO;
	ft_init_env(e);
	ft_init_hook(e);
	return (1);
}
