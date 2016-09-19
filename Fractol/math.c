/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:05:00 by hcorrale          #+#    #+#             */
/*   Updated: 2016/09/19 15:20:48 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				ft_hsv(double v, t_ftl *env, int i)
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

static int		ft_mandel(t_var *v, int x, int y)
{
	int			i;

	ft_mandel_init(v);
	v->ftl->c.r = v->minx + ((double)x * (v->maxx - v->minx) / v->win_w);
	v->ftl->c.i = v->miny + ((double)y * (v->maxy - v->miny) / v->win_h);
	v->ftl->z.r = 0;
	v->ftl->z.i = 0;
	i = -1;
	while ((v->ftl->z.r * v->ftl->z.r + v->ftl->z.i * v->ftl->z.i) < 4 && ++i < v->ftl->imax)
	{
		v->ftl->tmp = v->ftl->z.r;
		v->ftl->z.r = v->ftl->z.r * v->ftl->z.r - v->ftl->z.i * v->ftl->z.i + v->ftl->c.r;
		v->ftl->z.i = v->mandel * v->ftl->z.i * v->ftl->tmp + v->ftl->c.i;
	}
	return (i);
}

static int		ft_julia(t_var *v, int x, int y)
{
	int			i;

	ft_julia_init(v);
	v->ftl->z.r = v->minx + ((double)x * (v->maxx - v->minx) / v->win_w);
	v->ftl->z.i = v->miny + ((double)y * (v->maxy - v->miny) / v->win_h);
	i = -1;
	while ((v->ftl->z.r * v->ftl->z.r + v->ftl->z.i * v->ftl->z.i) < 4 && ++i < v->ftl->imax)
	{
		v->ftl->tmp = v->ftl->z.r;
		v->ftl->z.r = v->ftl->z.r * v->ftl->z.r - v->ftl->z.i * v->ftl->z.i + v->c.r;
		v->ftl->z.i = 2 * v->ftl->z.i * v->ftl->tmp + v->c.i;
	}
	return (i);
}

int				ft_draw_fractal(t_var *v)
{
	int color;
	int x;
	int y;
	int	i;

	y = 0;
	while (y < v->win_h)
	{
		x = 0;
		while (x < v->win_w)
		{
			if (v->type == 1 || v->type == 3)
			{
				i = ft_mandel(v, x, y);
				color = ft_hsv(i % 256, v->ftl, i);
			}
			else if (v->type == 2)
			{
				i = ft_julia(v, x, y);
				color = ft_hsv(i % 256, v->ftl, i);
			}
			ft_pixel_put(v, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	return (0);
}
