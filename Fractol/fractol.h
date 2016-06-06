/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:41:00 by hcorrale          #+#    #+#             */
/*   Updated: 2016/06/06 14:47:27 by hcorrale         ###   ########.fr       */
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
	double			r;
	double			i;
}					t_complex;

typedef struct		s_fractal
{
	t_complex		c;
	t_complex		z;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			tmp;
	int				i;
	int				imax;

}					t_fractal;

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
	t_fractal		*ftl_ptr;
	t_fractal		*ftl_arr;
}					t_var;

void				ft_draw_line(t_point a, t_point b, t_var *v, int color);


#endif