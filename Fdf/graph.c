/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 13:56:33 by hcorrale          #+#    #+#             */
/*   Updated: 2016/04/13 17:01:10 by hcorrale         ###   ########.fr       */
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

int			main(void)
{
	void	*mlx;
	void	*win;
	t_point	a;
	t_point	b;

	a.x = 700;
	a.y = 500;
	b.x = 300;
	b.y = 100;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 800, "mlx_win");
	ft_draw_line(a, b, mlx, win);
	mlx_pixel_put(mlx, win, a.x, a.y, 0x00FF0000);
	mlx_pixel_put(mlx, win, b.x, b.y, 0x00FF0000);
	mlx_loop(mlx);
	return (0);
}
