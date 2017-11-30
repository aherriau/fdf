/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:50:20 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/27 19:26:25 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "./../minilibx/mlx.h"
# include "./../libft/libft.h"

# define AXO	1
# define OBLI	2
# define CURVI	3

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*img2;
	void		*img3;
	char		*data;
	char		*data2;
	char		*data3;
	int			bpp;
	int			bpp2;
	int			bpp3;
	int			sl;
	int			sl2;
	int			sl3;
	int			endian;
	int			endian2;
	int			endian3;
	int			local_endian;
	int			opp;
	int			dec;
	int			color2;
	int			xpm_x;
	int			xpm_y;
	int			**map;
	int			width;
	int			height;
	int			alt_min;
	int			alt_max;
	int			proj;
	int			b1;
	int			b2;
	int			color;
	int			color_1;
	int			color_2;
	int			color_3;
	int			color_4;
	int			image;
	int			image_show;
	double		x_grav;
	double		y_grav;
	double		z_grav;
	double		scale_axo;
	double		scale_obli;
	double		scale_curvi;
	double		pad_x;
	double		pad_y;
	double		alt;
	double		theta;
	double		omega;
	double		gamma;
	double		alpha;
	double		beta;
	double		count;
	double		decal;
	double		d;
	t_point		p0;
	t_point		p1;
	t_point		proj_p0;
	t_point		proj_p1;
	t_point		ps0;
	t_point		ps1;
	t_point		ps2;
	t_point		p_b1;
	t_point		p_b2;
}				t_env;

int				ft_error(char *msg);
int				ft_get_map_dim(char *filename, t_env *e);
int				ft_init_mlx(t_env *e, char *filename);
int				ft_keypress_hook(int keycode, t_env *e);
int				ft_button_press_hook(int button, int x, int y, t_env *e);
int				ft_button_release_hook(int button, int x, int y, t_env *e);
int				ft_motion_notify_hook(int x, int y, t_env *e);
int				ft_expose_hook(t_env *e);
int				**ft_create_map(char *filename, t_env *e);
void			ft_display_map(t_env *e);
double			ft_scale_axo(t_env *e);
double			ft_scale_obli(t_env *e);
double			ft_scale_curvi(t_env *e);
void			ft_reset_map(t_env *e);
void			ft_segment(t_env *e, int type);
void			ft_display_axo(t_env *e);
void			ft_display_obli(t_env *e);
void			ft_display_curvi(t_env *e);
void			ft_color_image(t_env *e, int color, int type);
void			ft_display_menu(t_env *e);
void			ft_display_image(t_env *e);
int				ft_get_color(int r, int g, int b);
void			ft_segment_color(t_env *e, int type);
void			ft_segment_white(t_env *e, int type);
void			ft_fill_image(t_env *e, unsigned char *ptr, int x, int type);
void			ft_color_image(t_env *e, int color, int type);
void			ft_menu_5(t_env *e);
void			ft_menu_6(t_env *e);
void			ft_menu_7(t_env *e);
void			ft_menu_8(t_env *e);
void			ft_menu_9(t_env *e);
void			ft_mouse_proj(int y, t_env *e);
void			ft_mouse_settings(int y, t_env *e);
void			ft_mouse_color(int y, t_env *e);

#endif
