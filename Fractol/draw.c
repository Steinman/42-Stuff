/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 16:28:01 by hcorrale          #+#    #+#             */
/*   Updated: 2016/06/17 14:40:04 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_pixel_put(t_var *v, int x, int y, int color)
{
	int		i;
	char	*rgb;

	i = x * (v->bpp / 8) + (y * v->line);
	rgb = (char *)&color;
	v->add[i] = rgb[0];
	v->add[++i] = rgb[1];
	v->add[++i] = rgb[2];
}

int			ft_draw_fractal(t_var *v)
{
	mlx_clear_window(v->mlx, v->win);
	if (v->type == 1)
		ft_mandelbrot(v);
	if (v->type == 2)
		ft_julia(v);
	if (v->type == 3)
		ft_mandelbar(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	return (1);
}
