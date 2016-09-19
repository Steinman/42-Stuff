/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 16:28:01 by hcorrale          #+#    #+#             */
/*   Updated: 2016/09/19 15:19:25 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_pixel_put(t_var *v, int x, int y, int color)
{
	int		i;
	char	*rgb;

	if (x > 0 && x <= v->win_w && y > 0 && y <= v->win_h)
	{
		i = x * (v->bpp / 8) + (y * v->line);
		rgb = (char *)&color;
		v->add[i] = rgb[0];
		v->add[++i] = rgb[1];
		v->add[++i] = rgb[2];
	}
}

int			ft_mouse(int button, int x, int y, t_var *v)
{
	double	dx;
	double	dy;

	dx = v->maxx - v->minx;
	dy = v->maxy - v->miny;
	v->mx = ((double)x / v->win_w * dx) - dx / 2 + v->mx;
	v->my = ((double)y / v->win_h * dy) - dy / 2 + v->my;
	if (x >= 0 && x <= v->win_w && y >= 0 && y <= v->win_h)
	{
		if (button == 4 || button == 2)
		{
			v->minx = v->mx - (dx * 1.1) / 2;
			v->miny = v->my - (dy * 1.1) / 2;
			v->maxx = v->mx + (dx * 1.1) / 2;
			v->maxy = v->my + (dx * 1.1) / 2;
		}
		else if (button == 5 || button == 1)
		{
			v->minx = v->mx - (dx / 1.1) / 2;
			v->miny = v->my - (dy / 1.1) / 2;
			v->maxx = v->mx + (dx / 1.1) / 2;
			v->maxy = v->my + (dy / 1.1) / 2;
		}
		ft_draw_fractal(v);
	}
	return (0);
}

int			ft_motion(int x, int y, t_var *v)
{
	if (x >= 0 && x <= v->win_w && y >= 0 && y <= v->win_h && v->type == 2)
	{
		v->c.r = v->minx + ((x * v->maxx) / v->win_w);
		v->c.i = v->miny + ((y * v->maxy) / v->win_h);
		ft_draw_fractal(v);
	}
	return (0);
}

int			ft_move(int keycode, t_var *v)
{
	double	c;

	c = ((v->maxx - v->minx) / v->win_w) * 10;
	if (keycode == 123)
	{
		v->maxx -= c;
		v->minx -= c;
	}
	else if (keycode == 124)
	{
		v->maxx += c;
		v->minx += c;
	}
	else if (keycode == 125)
	{
		v->maxy += c;
		v->miny += c;
	}
	else if (keycode == 126)
	{
		v->maxy -= c;
		v->miny -= c;
	}
	ft_draw_fractal(v);
	return (0);
}
