/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 21:39:44 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/26 15:50:21 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_display_image(t_env *e)
{
	e->img3 = mlx_xpm_file_to_image(e->mlx, "./srcs/images/42.xpm", &(e->xpm_x),
			&(e->xpm_y));
	if (e->img3 == NULL)
		exit(ft_error("Error\n"));
	mlx_get_data_addr(e->img3, &(e->bpp3), &(e->sl3), &(e->endian3));
	mlx_put_image_to_window(e->mlx, e->win, e->img3, 1740, 40);
	mlx_destroy_image(e->mlx, e->img3);
	if (e->image == 0)
		e->img3 = mlx_xpm_file_to_image(e->mlx, "./srcs/images/placebo.xpm",
				&(e->xpm_x), &(e->xpm_y));
	if (e->image == 1)
		e->img3 = mlx_xpm_file_to_image(e->mlx,
				"./srcs/images/joy_division.xpm", &(e->xpm_x), &(e->xpm_y));
	if (e->img3 == NULL)
		exit(ft_error("Error\n"));
	mlx_get_data_addr(e->img3, &(e->bpp3), &(e->sl3), &(e->endian3));
	mlx_put_image_to_window(e->mlx, e->win, e->img3, 10, 591);
	mlx_destroy_image(e->mlx, e->img3);
}
