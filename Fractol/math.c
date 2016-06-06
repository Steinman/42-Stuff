/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:05:00 by hcorrale          #+#    #+#             */
/*   Updated: 2016/06/06 15:41:12 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fract_init(t_var *v)
{
	v->ftl_arr = (t_fractal *)malloc(sizeof(t_fractal) * 1);
	v->ftl_ptr = NULL;
	v->ftl_arr[0] = (t_fractal){{0, 0}, {0, 0}, -0.9, 0, 0, 0,
		v->win_w / (0.6 + 2.1), v->win_h / (1.2 * 1.2),
		0.5, 0, 0, 50, ft_mandelbrot};
	v->ftl_ptr = &(v->ftl_arr[0]);
}

int		ft_mandelbrot(t_point a, t_var *v, t_fractal f)
{
	f.c.r = 1.0 * (a.x - v->win_w / 2) / (0.5 * v->win_w) + f.x1;
	f.c.i = (a.y - v->win_h / 2) / (0.5 * v->win_h) + f.y1;
	while ((f.z.r * f.z.r - f.z.i * f.z.i) < 4 && (f.i < f.imax))
	{
		f.tmp = f.z.r;
		f.z.r = f.z.r * f.z.r - f.z.i * f.z.i + f.c.r;
		f.z.i = 2 * f.z.i * f.tmp + f.c.i;
		f.i += 1;
	}
	return (0);
}
