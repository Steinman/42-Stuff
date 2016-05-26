/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 13:56:33 by hcorrale          #+#    #+#             */
/*   Updated: 2016/05/26 16:29:10 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	v = ft_points_init(v, j);
	while (i < v->len)
	{
		v->c.x = v->b.x;
		if (j < v->l - 1)
			v->c.y = v->a.y + (v->mul / 3) - v->tab[j + 1][i];
		v->a.y -= v->tab[j][i];
		v->b.y -= v->tab[j][i + 1];
		if (i < v->len - 1)
			ft_draw_line(v->a, v->b, v);
		if (j < v->l - 1)
			ft_draw_line(v->a, v->c, v);
		v->a.y += v->tab[j][i];
		v->b.y += v->tab[j][i + 1];
		v->a.x += v->mul / 2;
		v->a.y -= v->mul / 3;
		v->b.x += v->mul / 2;
		v->b.y -= v->mul / 3;
		i++;
	}
}

int			ft_escape(int keycode, t_var *v)
{
	if (keycode == 53)
	{
		mlx_destroy_window(v->mlx, v->win);
		free(v);
		exit(0);
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_var	*v;
	int		i;

	i = 0;
	v = (t_var *)malloc(sizeof(t_var) * 1);
	v->err = 0;
	if (ac != 2)
		return (-1);
	else
	{
		if ((v = ft_open(av[1], v, 0))->err == -1)
		{
			free(v);
			exit(0);
		}
	}
	v = ft_graph_init(v);
	while (i < v->l)
		ft_drawtab(v, i++);
	free(v->tab);
	mlx_key_hook(v->win, ft_escape, v);
	mlx_loop(v->mlx);
	return (0);
}
