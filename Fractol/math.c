/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:05:00 by hcorrale          #+#    #+#             */
/*   Updated: 2016/07/12 16:42:44 by hcorrale         ###   ########.fr       */
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
	t_ftl		*ftl;

	ftl = (t_ftl *)malloc(sizeof(t_ftl) * 1);
	ftl->x1 = -2.1 + v->s;
	ftl->x2 = 0.6 - v->s;
	ftl->y1 = -1.2 + v->s;
	ftl->y2 = 1.2 - v->s;
	ftl->imax = 50;
	ftl->zoomx = (v->win_w / (ftl->x2 - ftl->x1));
	ftl->zoomy = (v->win_h / (ftl->y2 - ftl->y1));
	ftl->a.x = 0;
	ftl->a.y = 0;
	while (ftl->a.y < v->win_h)
	{
		while (ftl->a.x < v->win_w)
		{
			ftl->c.r = ftl->a.x / ftl->zoomx + ftl->x1;
			ftl->c.i = ftl->a.y / ftl->zoomy + ftl->y1;
			ftl->z.r = 0;
			ftl->z.i = 0;
			ftl->i = 0;
			while ((ftl->z.r * ftl->z.r + ftl->z.i * ftl->z.i) < 4 && ftl->i < ftl->imax)
			{
				ftl->tmp = ftl->z.r;
				ftl->z.r = ftl->z.r * ftl->z.r - ftl->z.i * ftl->z.i + ftl->c.r;
				ftl->z.i = 2 * ftl->z.i * ftl->tmp + ftl->c.i;
				ftl->i++;
			}
			if (ftl->i == ftl->imax)
				ft_pixel_put(v, ftl->a.x, ftl->a.y, 0x000000);
			else
				ft_pixel_put(v, ftl->a.x, ftl->a.y, ft_hsv((int)ftl->i % 256, ftl, ftl->i));
			ftl->a.x++;
		}
		ftl->a.x = 0;
		ftl->a.y++;
	}
	free(ftl);
}

void			ft_julia(t_var *v)
{
	t_ftl		*ftl;

	ftl = (t_ftl *)malloc(sizeof(t_ftl) * 1);
	ftl->x1 = -1 + v->s;
	ftl->x2 = 1 - v->s;
	ftl->y1 = -1.2 + v->s;
	ftl->y2 = 1.2 - v->s;
	ftl->imax = 150;
	ftl->zoomx = (v->win_w / (ftl->x2 - ftl->x1));
	ftl->zoomy = (v->win_h / (ftl->y2 - ftl->y1));
	ftl->a.x = 0;
	ftl->a.y = 0;
	while (ftl->a.y < v->win_h)
	{
		while (ftl->a.x < v->win_w)
		{
			v->c.r = 0.285;
			v->c.i = 0.01;
			ftl->z.r = ftl->a.x / ftl->zoomx + ftl->x1;
			ftl->z.i = ftl->a.y / ftl->zoomy + ftl->y1;
			ftl->i = 0;
			while ((ftl->z.r * ftl->z.r + ftl->z.i * ftl->z.i) < 4 && ftl->i < ftl->imax)
			{
				ftl->tmp = ftl->z.r;
				ftl->z.r = ftl->z.r * ftl->z.r - ftl->z.i * ftl->z.i + v->c.r;
				ftl->z.i = 2 * ftl->z.i * ftl->tmp + v->c.i;
				ftl->i++;
			}
			if (ftl->i == ftl->imax)
				ft_pixel_put(v, ftl->a.x, ftl->a.y, 0x000000);
			else
				ft_pixel_put(v, ftl->a.x, ftl->a.y, ft_hsv((int)ftl->i % 256, ftl, ftl->i));
			ftl->a.x++;
		}
		ftl->a.x = 0;
		ftl->a.y++;
	}
	free(ftl);
}

void			ft_mandelbar(t_var *v)
{
	t_ftl		*ftl;

	ftl = (t_ftl *)malloc(sizeof(t_ftl) * 1);
	ftl->x1 = -2.1 + v->s;
	ftl->x2 = 0.6 - v->s;
	ftl->y1 = -1.2 + v->s;
	ftl->y2 = 1.2 - v->s;
	ftl->imax = 50;
	ftl->zoomx = (v->win_w / (ftl->x2 - ftl->x1));
	ftl->zoomy = (v->win_h / (ftl->y2 - ftl->y1));
	ftl->a.x = 0;
	ftl->a.y = 0;
	while (ftl->a.y < v->win_h)
	{
		while (ftl->a.x < v->win_w)
		{
			ftl->c.r = ftl->a.x / ftl->zoomx + ftl->x1;
			ftl->c.i = ftl->a.y / ftl->zoomy + ftl->y1;
			ftl->z.r = 0;
			ftl->z.i = 0;
			ftl->i = 0;
			while ((ftl->z.r * ftl->z.r + ftl->z.i * ftl->z.i) < 4 && ftl->i < ftl->imax)
			{
				ftl->tmp = ftl->z.r;
				ftl->z.r = ftl->z.r * ftl->z.r - ftl->z.i * ftl->z.i + ftl->c.r;
				ftl->z.i = -2 * ftl->z.i * ftl->tmp + ftl->c.i;
				ftl->i++;
			}
			if (ftl->i == ftl->imax)
				ft_pixel_put(v, ftl->a.x, ftl->a.y, 0x000000);
			else
				ft_pixel_put(v, ftl->a.x, ftl->a.y, ft_hsv((int)ftl->i % 256, ftl, ftl->i));
			ftl->a.x++;
		}
		ftl->a.x = 0;
		ftl->a.y++;
	}
	free(ftl);
}
