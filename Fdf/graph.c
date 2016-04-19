/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 13:56:33 by hcorrale          #+#    #+#             */
/*   Updated: 2016/04/19 14:02:27 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <math.h>

static void	ft_draw_line(t_point a, t_point b, t_var v)
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
		mlx_pixel_put(v.mlx, v.win, x0, y0, 0x00FFFFFF);
		tx += 1. / sqrtf((dx * dx) + (dy * dy));
	}
}

static void	ft_drawtab(t_var v, int j)
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
		v.a.y += v.tab[j][i];
		ft_draw_line(v.a, v.b, v);
		v.a.x += mul / 2;
		v.a.y -= mul / 2;
		v.b.x += mul / 2;
		v.b.y -= mul / 2;
		i++;
	}
}

int			main(int ac, char **av)
{
	t_var	v;

	v.err = 0;
	if (ac!= 2)
		return (-1);
	else
	{
		if ((v = ft_open(av[1], v, 0)).err == -1)
			ft_putstr("wallah sa march pa");
	}
	v.winx = 800;
	v.winy = 800;
	v.mlx = mlx_init();
	v.win = mlx_new_window(v.mlx, v.winx, v.winy, "mlx_win");
	ft_drawtab(v, 0);
	mlx_loop(v.mlx);
	return (0);
}