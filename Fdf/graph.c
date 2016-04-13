/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 13:56:33 by hcorrale          #+#    #+#             */
/*   Updated: 2016/04/13 17:58:15 by hcorrale         ###   ########.fr       */
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

	i = 0;
	while (i < v.len)
	{
		
	}
}

int			main(void)
{
	t_var	v;
	v.winx = 800;
	v.winy = 800;

	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, v.winx, v.winy, "mlx_win");
	mlx_loop(mlx);
	return (0);
}
