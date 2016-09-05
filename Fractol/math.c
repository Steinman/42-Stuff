/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:05:00 by hcorrale          #+#    #+#             */
/*   Updated: 2016/09/05 15:39:09 by hcorrale         ###   ########.fr       */
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

void			ft_mandelbrot(t_var *v)
{
	//printf("start drawing\n");
	v->ftl = (t_ftl *)malloc(sizeof(t_ftl) * 1);
	v->ftl->x1 = -2.1 + v->s;
	v->ftl->x2 = 0.6 - v->s;
	v->ftl->y1 = -1.2 + v->s;
	v->ftl->y2 = 1.2 - v->s;
	v->ftl->imax = 30;
	v->ftl->zoomx = (v->win_w / (v->ftl->x2 - v->ftl->x1));
	v->ftl->zoomy = (v->win_h / (v->ftl->y2 - v->ftl->y1));
	v->ftl->a.x = 0;
	v->ftl->a.y = 0;
	while (v->ftl->a.y < v->win_h)
	{
		while (v->ftl->a.x < v->win_w)
		{
			v->ftl->c.r = v->ftl->a.x / v->ftl->zoomx + v->ftl->x1;
			v->ftl->c.i = v->ftl->a.y / v->ftl->zoomy + v->ftl->y1;
			v->ftl->z.r = 0;
			v->ftl->z.i = 0;
			v->ftl->i = 0;
			while ((v->ftl->z.r * v->ftl->z.r + v->ftl->z.i * v->ftl->z.i) < 4 && v->ftl->i < v->ftl->imax)
			{
				v->ftl->tmp = v->ftl->z.r;
				v->ftl->z.r = v->ftl->z.r * v->ftl->z.r - v->ftl->z.i * v->ftl->z.i + v->ftl->c.r;
				v->ftl->z.i = 2 * v->ftl->z.i * v->ftl->tmp + v->ftl->c.i;
				v->ftl->i++;
			}
			if (v->ftl->i == v->ftl->imax)
				ft_pixel_put(v, v->ftl->a.x, v->ftl->a.y, 0x000000);
			else
				ft_pixel_put(v, v->ftl->a.x, v->ftl->a.y, ft_hsv((int)v->ftl->i % 256, v->ftl, v->ftl->i));
			v->ftl->a.x++;
		}
		v->ftl->a.x = 0;
		v->ftl->a.y++;
	}
	free(v->ftl);
	//printf("finished drawing\n");
}

void			ft_julia(t_var *v)
{
	v->ftl = (t_ftl *)malloc(sizeof(t_ftl) * 1);
	v->ftl->x1 = -1 + v->s;
	v->ftl->x2 = 1 - v->s;
	v->ftl->y1 = -1.2 + v->s;
	v->ftl->y2 = 1.2 - v->s;
	v->ftl->imax = 150;
	v->ftl->zoomx = (v->win_w / (v->ftl->x2 - v->ftl->x1));
	v->ftl->zoomy = (v->win_h / (v->ftl->y2 - v->ftl->y1));
	v->ftl->a.x = 0;
	v->ftl->a.y = 0;
	while (v->ftl->a.y < v->win_h)
	{
		while (v->ftl->a.x < v->win_w)
		{
			//v->c.r = 0.285;
			//v->c.i = 0.01;
			v->ftl->z.r = v->ftl->a.x / v->ftl->zoomx + v->ftl->x1;
			v->ftl->z.i = v->ftl->a.y / v->ftl->zoomy + v->ftl->y1;
			v->ftl->i = -1;
			while ((v->ftl->z.r * v->ftl->z.r + v->ftl->z.i * v->ftl->z.i) < 4 && ++v->ftl->i < v->ftl->imax)
			{
				v->ftl->tmp = v->ftl->z.r;
				v->ftl->z.r = v->ftl->z.r * v->ftl->z.r - v->ftl->z.i * v->ftl->z.i + v->c.r;
				v->ftl->z.i = 2 * v->ftl->z.i * v->ftl->tmp + v->c.i;
			}
			if (v->ftl->i == v->ftl->imax)
				ft_pixel_put(v, v->ftl->a.x, v->ftl->a.y, 0x000000);
			else
				ft_pixel_put(v, v->ftl->a.x, v->ftl->a.y, ft_hsv((int)v->ftl->i % 256, v->ftl, v->ftl->i));
			v->ftl->a.x++;
		}
		v->ftl->a.x = 0;
		v->ftl->a.y++;
	}
	free(v->ftl);
}

void			ft_mandelbar(t_var *v)
{
	v->ftl = (t_ftl *)malloc(sizeof(t_ftl) * 1);
	v->ftl->x1 = -2.1 + v->s;
	v->ftl->x2 = 0.6 - v->s;
	v->ftl->y1 = -1.2 + v->s;
	v->ftl->y2 = 1.2 - v->s;
	v->ftl->imax = 50;
	v->ftl->zoomx = (v->win_w / (v->ftl->x2 - v->ftl->x1));
	v->ftl->zoomy = (v->win_h / (v->ftl->y2 - v->ftl->y1));
	v->ftl->a.x = 0;
	v->ftl->a.y = 0;
	while (v->ftl->a.y < v->win_h)
	{
		while (v->ftl->a.x < v->win_w)
		{
			v->ftl->c.r = v->ftl->a.x / v->ftl->zoomx + v->ftl->x1;
			v->ftl->c.i = v->ftl->a.y / v->ftl->zoomy + v->ftl->y1;
			v->ftl->z.r = 0;
			v->ftl->z.i = 0;
			v->ftl->i = 0;
			while ((v->ftl->z.r * v->ftl->z.r + v->ftl->z.i * v->ftl->z.i) < 4 && v->ftl->i < v->ftl->imax)
			{
				v->ftl->tmp = v->ftl->z.r;
				v->ftl->z.r = v->ftl->z.r * v->ftl->z.r - v->ftl->z.i * v->ftl->z.i + v->ftl->c.r;
				v->ftl->z.i = -2 * v->ftl->z.i * v->ftl->tmp + v->ftl->c.i;
				v->ftl->i++;
			}
			if (v->ftl->i == v->ftl->imax)
				ft_pixel_put(v, v->ftl->a.x, v->ftl->a.y, 0x000000);
			else
				ft_pixel_put(v, v->ftl->a.x, v->ftl->a.y, ft_hsv((int)v->ftl->i % 256, v->ftl, v->ftl->i));
			v->ftl->a.x++;
		}
		v->ftl->a.x = 0;
		v->ftl->a.y++;
	}
	free(v->ftl);
}
