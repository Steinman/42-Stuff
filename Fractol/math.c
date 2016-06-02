/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:05:00 by hcorrale          #+#    #+#             */
/*   Updated: 2016/06/02 17:03:49 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_mandelbrot(t_point a, t_var *v, t_fractal f)
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
}
