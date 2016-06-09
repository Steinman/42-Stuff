/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 16:28:01 by hcorrale          #+#    #+#             */
/*   Updated: 2016/06/09 12:16:22 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_pixel_put(t_var *v, int x, int y, int color)
{
	int		i;
	char	*rgb;

	i = x * (v->bpp / 8) + (y * v->line);
	color = mlx_get_color_value(v->mlx, color);
	rgb = (char *)&color;
	v->add[i] = rgb[0];
	v->add[++i] = rgb[1];
	v->add[++i] = rgb[2];
}

void		ft_draw_line(t_point a, t_point b, t_var *v, int color)
{
	double	x0;
	double	y0;
	float	dx;
	float	dy;
	double	tx;

	tx = 0.0;
	dx = b.x - a.x;
	dy = b.y - a.y;
	while (tx <= 1)
	{
		x0 = a.x + (dx * tx);
		y0 = a.y + (dy * tx);
		ft_pixel_put(v, x0, y0, color);
		tx += 1. / sqrtf((dx * dx) + (dy * dy));
	}
}

int			ft_draw_fractal(t_var *v)
{
	mlx_clear_window(v->mlx, v->win);
	if (v->type == 1)
		ft_mandelbrot(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	return (1);
}
