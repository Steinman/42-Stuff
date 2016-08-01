/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:41:00 by hcorrale          #+#    #+#             */
/*   Updated: 2016/08/01 13:52:57 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "libft/libft.h"

typedef struct		s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct		s_complex
{
	long double		r;
	long double		i;
}					t_complex;

typedef struct		s_hsv
{
	double			i;
	double			f;
	double			l;
	double			m;
	double			n;
}					t_hsv;

typedef struct		s_ftl
{
	t_point			a;
	float			x1;
	float			x2;
	float			y1;
	float			y2;
	double			zoomx;
	double			zoomy;
	double			i;
	double			imax;
	double			tmp;
	t_complex		c;
	t_complex		z;
}					t_ftl;

typedef struct		s_var
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*add;
	int				bpp;
	int				line;
	int				endian;
	int				type;
	int				win_w;
	int				win_h;
	float			s;
	t_complex		c;
	int				xmouse;
	int				ymouse;
}					t_var;

void				ft_draw_line(t_point a, t_point b, t_var *v, int color);
void				ft_mandelbrot(t_var *v);
void				ft_julia(t_var *v);
void				ft_mandelbar(t_var *v);
void				ft_pixel_put(t_var *v, int x, int y, int color);
int					ft_draw_fractal(t_var *v);
int					ft_julia_param(int button,int x, int y, t_var *v);

#endif
