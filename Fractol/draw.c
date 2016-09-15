/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 16:28:01 by hcorrale          #+#    #+#             */
/*   Updated: 2016/09/15 15:06:27 by hcorrale         ###   ########.fr       */
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
	if (x >= 0 && x <= v->win_w && y >= 0 && y <= v->win_h)
	{
		if (button == 5 || button == 1)
			v->s += 0.1;
		if (button == 4 || button == 2)
			v->s -= 0.1;
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
