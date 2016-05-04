/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 13:56:33 by hcorrale          #+#    #+#             */
/*   Updated: 2016/05/04 17:01:52 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <math.h>

static void	ft_draw_line(t_point a, t_point b, t_var *v)
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
		mlx_pixel_put(v->mlx, v->win, x0, y0, 0x00FFFFFF);
		tx += 1. / sqrtf((dx * dx) + (dy * dy));
	}
}

static void	ft_drawtab(t_var *v, int j)
{
	int		i;

	i = 0;
	v->a.x = ((v->winx - (v->len * (v->mul / 2))) / 2) - ((v->l * (v->mul / 2)) / 2) + j * (v->mul / 2);
	v->a.y = v->winy - (v->l * (v->mul / 2)) + j * (v->mul / 2);
	v->b.x = v->a.x + v->mul / 2;
	v->b.y = v->a.y - v->mul / 2;
	while (i < v->len)
	{
		v->c.x = v->b.x;
		if (j < v->l - 1)
			v->c.y = v->a.y + (v->mul / 2) - v->tab[j + 1][i];
		v->a.y -= v->tab[j][i];
		v->b.y -= v->tab[j][i + 1];
		if (i < v->len - 1)
			ft_draw_line(v->a, v->b, v);
		if (j < v->l - 1)
			ft_draw_line(v->a, v->c, v);
		v->a.y += v->tab[j][i];
		v->b.y += v->tab[j][i + 1];
		v->a.x += v->mul / 2;
		v->a.y -= v->mul / 2;
		v->b.x += v->mul / 2;
		v->b.y -= v->mul / 2;
		i++;
	}
}

int			ft_escape(int keycode, t_var *v)
{
	if (keycode == 53)
		{
			mlx_destroy_window(v->mlx, v->win);
			exit(0);
		}
	return (0);
}

int			main(int ac, char **av)
{
	t_var	*v;
	int		i;

	i = 0;
	v = (t_var *)malloc(sizeof(t_var));
	v->err = 0;
	if (ac != 2)
		return (-1);
	else
	{
		if ((v = ft_open(av[1], v, 0))->err == -1)
			ft_putstr("wallah sa march pa");
	}
	printf("%d points par lignes\n", v->len);
	printf("%d points par colones\n", v->l);
	v->winx = 800;
	v->winy = 800;
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, v->winx, v->winy, "mlx_win");
	v->mul = v->winx;
	if (v->len > v->l)
	{
		while ((v->len * v->mul) > v->winy)
			v->mul--;
	}
	else
	{
		while ((v->l * v->mul) > v->winx)
			v->mul--;
	}
	printf("mul = %f\n", v->mul);
	while (i < v->l)
	{
		ft_drawtab(v, i);
		i++;
	}
	mlx_key_hook(v->win, ft_escape, v);
	mlx_loop(v->mlx);
	return (0);
}
