/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_fdf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:14:46 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/26 15:14:20 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_get_color(int r, int g, int b)
{
	int		result;

	result = 0;
	result += r << 16;
	result += g << 8;
	result += b;
	return (result);
}

void	ft_reset_map(t_env *e)
{
	e->pad_x = 700;
	e->pad_y = 540;
	e->alt = 1;
	e->theta = M_PI / 32;
	e->omega = (5 * M_PI) / 32;
	e->gamma = (5 * M_PI) / 32;
	e->alpha = 1;
	e->beta = 10;
	e->scale_axo = ft_scale_axo(e);
	e->scale_obli = ft_scale_obli(e);
	e->scale_curvi = ft_scale_curvi(e);
}

void	ft_display_map(t_env *e)
{
	e->img = mlx_new_image(e->mlx, 1600, 1080);
	if (e->img == NULL)
		exit(ft_error("Error\n"));
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->sl), &(e->endian));
	if (e->proj == AXO)
		ft_display_axo(e);
	if (e->proj == OBLI)
		ft_display_obli(e);
	if (e->proj == CURVI)
		ft_display_curvi(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 320, 0);
	mlx_destroy_image(e->mlx, e->img);
}
