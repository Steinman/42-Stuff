/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 13:56:33 by hcorrale          #+#    #+#             */
/*   Updated: 2016/04/11 17:36:32 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_draw_line(int 1x, int 1y, int 2x, int 2y void *mlx, void *win)
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		dx;
	int		dy;

	if (1x > 2x)
	{
		x1 = 2x;
		x2 = 1x;
		y1 = 2y;
		y2 = 1y;
	}
	else
	{
		x1 = 1x;
		x2 = 2x;
		y1 = 1y;
		y2 = 2y;
	}
	dx = x2 - x1;
	dy = y2 - y1;
	if ((!dx) && (!dy))
		return;
	if (dy < 0)
		dy = -dy;
}

int			main(void)
{
	void	*mlx;
	void	*win;
	t_point	a;
	t_point	b;

	a.x = 500;
	a.y = 100;
	b.x = 700;
	b.y = 400;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 800, "mlx_win");
	ft_draw_line(a, b, mlx, win);
	mlx_pixel_put(mlx, win, a.x, a.y, 0x00FF0000);
	mlx_pixel_put(mlx, win, b.x, b.y, 0x00FF0000);
	mlx_loop(mlx);
	return (0);
}
