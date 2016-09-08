/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:05:00 by hcorrale          #+#    #+#             */
/*   Updated: 2016/09/08 15:34:12 by hcorrale         ###   ########.fr       */
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

/*void			ft_mandelbrot(t_var *v)
{
	ft_mandel_init(v);
	while (v->ftl->a.y < v->win_h)
	{
		while (v->ftl->a.x < v->win_w)
		{
			v->ftl->c.r = v->ftl->a.x / v->ftl->zoomx + v->ftl->x1;
			v->ftl->c.i = v->ftl->a.y / v->ftl->zoomy + v->ftl->y1;
			v->ftl->z.r = 0;
			v->ftl->z.i = 0;
			v->ftl->i = -1;
			while ((v->ftl->z.r * v->ftl->z.r + v->ftl->z.i * v->ftl->z.i) < 4 && ++v->ftl->i < v->ftl->imax)
			{
				v->ftl->tmp = v->ftl->z.r;
				v->ftl->z.r = v->ftl->z.r * v->ftl->z.r - v->ftl->z.i * v->ftl->z.i + v->ftl->c.r;
				v->ftl->z.i = v->mandel * v->ftl->z.i * v->ftl->tmp + v->ftl->c.i;
			}
			ft_pixel_put(v, v->ftl->a.x, v->ftl->a.y, ft_hsv((int)v->ftl->i % 256, v->ftl, v->ftl->i));
			v->ftl->a.x++;
		}
		v->ftl->a.x = 0;
		v->ftl->a.y++;
	}
	free(v->ftl);
}

void			ft_julia(t_var *v)
{
	ft_julia_init(v);
	while (v->ftl->a.y < v->win_h)
	{
		while (v->ftl->a.x < v->win_w)
		{
			v->ftl->z.r = v->ftl->a.x / v->ftl->zoomx + v->ftl->x1;
			v->ftl->z.i = v->ftl->a.y / v->ftl->zoomy + v->ftl->y1;
			v->ftl->i = -1;
			while ((v->ftl->z.r * v->ftl->z.r + v->ftl->z.i * v->ftl->z.i) < 4 && ++v->ftl->i < v->ftl->imax)
			{
				v->ftl->tmp = v->ftl->z.r;
				v->ftl->z.r = v->ftl->z.r * v->ftl->z.r - v->ftl->z.i * v->ftl->z.i + v->c.r;
				v->ftl->z.i = 2 * v->ftl->z.i * v->ftl->tmp + v->c.i;
			}
			ft_pixel_put(v, v->ftl->a.x, v->ftl->a.y, ft_hsv((int)v->ftl->i % 256, v->ftl, v->ftl->i));
			v->ftl->a.x++;
		}
		v->ftl->a.x = 0;
		v->ftl->a.y++;
	}
	free(v->ftl);
}*/

static int		ft_mandel(t_var *v)
{
	int			i;

	ft_mandel_init(v);
	v->ftl->c.r = v->ftl->a.x / v->ftl->zoomx + v->ftl->x1;
	v->ftl->c.i = v->ftl->a.y / v->ftl->zoomy + v->ftl->y1;
	v->ftl->z.r = 0;
	v->ftl->z.i = 0;
	i = -1;
	while ((v->ftl->z.r * v->ftl->z.r + v->ftl->z.i * v->ftl->z.i) < 4 && ++i < v->ftl->imax)
	{
		v->ftl->tmp = v->ftl->z.r;
		v->ftl->z.r = v->ftl->z.r * v->ftl->z.r - v->ftl->z.i * v->ftl->z.i + v->ftl->c.r;
		v->ftl->z.i = 2 * v->ftl->z.i * v->ftl->tmp + v->ftl->c.i;
	}
	return(i);
}

static int		ft_julia(t_var *v)
{
	int			i;

	ft_julia_init(v);
	v->ftl->z.r = v->ftl->a.x / v->ftl->zoomx + v->ftl->x1;
	v->ftl->z.i = v->ftl->a.y / v->ftl->zoomy + v->ftl->y1;
	i = -1;
	while ((v->ftl->z.r * v->ftl->z.r + v->ftl->z.i * v->ftl->z.i) < 4 && ++i < v->ftl->imax)
	{
		v->ftl->tmp = v->ftl->z.r;
		v->ftl->z.r = v->ftl->z.r * v->ftl->z.r - v->ftl->z.i * v->ftl->z.i + v->c.r;
		v->ftl->z.i = 2 * v->ftl->z.i * v->ftl->tmp + v->c.i;
	}
	return(i);
}

int				ft_draw_fractal(t_var *v)
{
	int color;

	v->ftl->a.y = 0;
	while (v->ftl->a.y < v->win_h)
	{
		v->ftl->a.x = 0;
		while (v->ftl->a.x < v->win_w)
		{
			if (v->type == 1 || v->type == 3)
				color = ft_hsv(ft_mandel(v) % 256, v->ftl, ft_mandel(v));
			if (v->type == 2)
				color = ft_hsv(ft_julia(v) % 256, v->ftl, ft_julia(v));
			ft_pixel_put(v, v->ftl->a.x, v->ftl->a.y, color);
			v->ftl->a.x++;
		}
		v->ftl->a.y++;
	}
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	free(v->ftl);
	return(0);
}
