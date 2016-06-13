/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:05:00 by hcorrale          #+#    #+#             */
/*   Updated: 2016/06/13 12:18:55 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				ft_hsv(double v, t_var *env, int i)
{
	t_hsv	hsv;

	if (i >= env->imax)
		return (0x000000);
	hsv.i = floor(v / 60);
	hsv.f = (v / 60) - hsv.i;
	hsv.l = v * (1 - v);
	hsv.m = v * (1 - hsv.f * v);
	hsv.n = v * (1 - (1 - hsv.f) * v);
	hsv.l *= 255;
	hsv.m *= 255;
	hsv.n *= 255;
	v *= 255;
	if (hsv.i == 0)
		return (((int)v << 16) + ((int)hsv.n << 8) + (int)hsv.l);
	else if (hsv.i == 1)
		return (((int)hsv.m << 16) + ((int)v << 8) + (int)hsv.l);
	else if (hsv.i == 2)
		return (((int)hsv.l << 16) + ((int)v << 8) + (int)hsv.n);
	else if (hsv.i == 3)
		return (((int)hsv.l << 16) + ((int)hsv.m << 8) + (int)v);
	else if (hsv.i == 4)
		return (((int)hsv.n << 16) + ((int)hsv.l << 8) + (int)v);
	else
		return (((int)v << 16) + ((int)hsv.l << 8) + (int)hsv.m);
}

void			ft_mandelbrot(t_var *v)
{
	int			x;
	int			y;
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	double		zoomx;
	double		zoomy;
	double		i;
	t_complex	c;
	t_complex	z;
	double		tmp;

	x1 = -2.1;
	x2 = 0.6;
	y1 = -1.2;
	y2 = 1.2;
	v->imax = 50;
	zoomx = v->win_w / (x2 - x1);
	zoomy = v->win_h / (y2 - y1);
	x = 0;
	y = 0;
	while (y < v->win_h)
	{
		while (x < v->win_w)
		{
			c.r = x / zoomx + x1;
			c.i = y / zoomy + y1;
			z.r = 0;
			z.i = 0;
			i = 0;
			while ((z.r * z.r + z.i * z.i) < 4 && i < v->imax)
			{
				tmp = z.r;
				z.r = z.r * z.r - z.i * z.i + c.r;
				z.i = 2 * z.i * tmp + c.i;
				i++;
			}
			if (i == v->imax)
				ft_pixel_put(v, x, y, 0x000000);
			else
				ft_pixel_put(v, x, y, ft_hsv((int)i % 256, v, i));
			x++;
		}
		x = 0;
		y++;
	}
}
