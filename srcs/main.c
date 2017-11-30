/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:09:23 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/26 15:23:21 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_error(char *msg)
{
	ft_putstr(msg);
	return (1);
}

int		main(int argc, char **argv)
{
	t_env	e;
	int		error;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf source_file\n");
		return (1);
	}
	e.width = 0;
	e.height = 0;
	e.alt_min = 0;
	e.alt_max = 0;
	error = ft_get_map_dim(argv[1], &e);
	if (error == -1)
		return (ft_error("Invalid file\n"));
	if (error == 0 || e.height == 0)
		return (ft_error("Invalid map\n"));
	if (ft_init_mlx(&e, argv[1]) == 0)
		return (ft_error("Error\n"));
	mlx_loop(e.mlx);
	return (0);
}
