/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 16:28:01 by hcorrale          #+#    #+#             */
/*   Updated: 2016/09/05 15:38:56 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_pixel_put(t_var *v, int x, int y, int color)
{
	int		i;
	char	*rgb;

	x = v->ftl->a.x;
	y = v->ftl->a.y;
	if (x > 0 && x <= v->win_w && y > 0 && y <= v->win_h)
	{
		i = x * (v->bpp / 8) + (y * v->line);
		rgb = (char *)&color;
		v->add[i] = rgb[0];
		v->add[++i] = rgb[1];
		v->add[++i] = rgb[2];
	}
}

int			ft_expose(t_var *v)
{
	v->img = mlx_new_image(v->mlx, v->win_w, v->win_h);
	v->add = mlx_get_data_addr(v->img, &v->bpp, &v->line, &v->endian);
	ft_draw_fractal(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	return (0);
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
	return (1);
}

int			ft_mouse(int button, int x, int y, t_var *v)
{
	if (x >= 0 && x <= v->win_w && y >= 0 && y <= v->win_h)
	{
		if (button == 5 || button == 1)
			v->s += 0.1;
		if (button == 4 || button == 2)
			v->s -= 0.1;
		mlx_destroy_image(v->mlx, v->img);
		mlx_clear_window(v->mlx, v->win);
		ft_expose(v);
	}
	return (0);
}

int			ft_motion(int x, int y, t_var *v)
{
	if (x >= 0 && x <= v->win_w && y>= 0 && y <= v->win_h && v->type == 2)
	{
		v->c.r = -3.2 + ((x * 3.4) / v->win_w);
		v->c.i = -3.2 + ((y * 3.4) / v->win_h);
		ft_expose(v);
	}
	return (0);
}
