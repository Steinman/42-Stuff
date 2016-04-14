/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 13:56:33 by hcorrale          #+#    #+#             */
/*   Updated: 2016/04/14 17:16:34 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <math.h>

void		ft_draw_line(t_point a, t_point b, void *mlx, void *win)
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
		mlx_pixel_put(mlx, win, x0, y0, 0x00FFFFFF);
		tx += 1. / sqrtf((dx * dx) + (dy * dy));
	}
}

void		ft_drawtab(t_var v)
{
	int		i;
	int		mul;

	mul = 300;
	i = 0;
	while ((v.len * mul) > (v.winx - 200))
			mul--;
	v.a.x = 100;
	v.a.y = v.winy / 2;
	v.b.x = v.a.x + mul / 2;
	v.b.y = v.a.y - mul / 2;
	while (i < v.len)
	{
		ft_draw_line(v.a, v.b, v.mlx, v.win);
		v.b.y += mul;
		ft_draw_line(v.a, v.b, v.mlx, v.win);
		v.a.x += mul / 2;
		v.a.y -= mul / 2;
		v.b.x += mul / 2;
		v.b.y -= (mul + mul / 2);
		i++;
	}
	v.b.y += mul;
	ft_draw_line(v.a, v.b, v.mlx, v.win);
}

int			main(void)
{
	t_var	v;

	v.len = 19;
	v.winx = 800;
	v.winy = 800;
	v.mlx = mlx_init();
	v.win = mlx_new_window(v.mlx, v.winx, v.winy, "mlx_win");
	ft_drawtab(v);
	mlx_loop(v.mlx);
	return (0);
}
