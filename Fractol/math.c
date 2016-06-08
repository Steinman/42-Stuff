/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:05:00 by hcorrale          #+#    #+#             */
/*   Updated: 2016/06/08 16:43:37 by hcorrale         ###   ########.fr       */
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
	t_point		p;
	t_complex	pix;
	t_complex	old;
	t_complex	new;
	double		zoom;
	double		movex;
	double		movey;
	int			color;
	int			imax;
	int			i;

	zoom = 1;
	movex = -0.5;
	movey = 0;
	imax = 300;
	p.x = 0;
	p.y = 0;
	while (p.y < v->win_h)
	{
		while (p.x < v->win_w)
		{
			pix.r = 1.5 * (p.x - v->win_w / 2) / (0.5 * zoom * v->win_w) + movex;
			pix.i = (p.y - v->win_h / 2) / (0.5 * zoom * v->win_h) + movey;
			new.r = new.i = old.r = old.i = 0;
			i = 0;
			while (i < imax)
			{
				old.r = new.r;
				old.i = new.i;
				new.r = old.r * old.r - old.i * old.i + pix.r;
				new.i = 2 * old.r * old.i + pix.i;
				if ((new.r * new.r + new.i * new.i) > 4)
					break;
				i++;
			}
			ft_pixel_put(v, p.x, p.y, color = ft_hsv(i % 256, v, i));
			p.x++;
		}
		p.x = 0;
		p.y++;
	}
	return;
}
