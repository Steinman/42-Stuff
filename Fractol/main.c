/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:09:33 by hcorrale          #+#    #+#             */
/*   Updated: 2016/09/15 15:06:30 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_key(int keycode, t_var *v)
{
	printf("keycode = %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_image(v->mlx, v->img);
		mlx_destroy_window(v->mlx, v->win);
		free(v);
		exit(0);
	}
	return (0);
}

static void	ft_check_param(int ac, char **av, t_var *v)
{
	v->type = 0;
	if (ac != 2)
	{
		ft_putstr("ERROR: only one parameter is allowed! try with mandelbrot, julia or mandelbar\n");
		free(v);
		exit(0);
	}
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		v->type = 1;
	if (ft_strcmp(av[1], "julia") == 0)
		v->type = 2;
	if (ft_strcmp(av[1], "mandelbar") == 0)
		v->type = 3;
	if (v->type == 0)
	{
		ft_putstr("ERROR: invalid parameter! try with mandelbrot, julia or mandelbar\n");
		free(v);
		exit(0);
	}
}

static void	ft_mandel_check(t_var *v)
{
	v->mandel = 0;
	if (v->type == 1 || v->type == 2)
		v->mandel = 2;
	else if (v->type == 3)
		v->mandel = -2;
}

int			main(int ac, char **av)
{
	t_var	*v;

	v = (t_var *)malloc(sizeof(t_var) * 1);
	ft_check_param(ac, av, v);
	ft_mandel_check(v);
	v->win_w = 800;
	v->win_h = 800;
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, v->win_w, v->win_h, "mlx_win");
	v->img = mlx_new_image(v->mlx, v->win_w, v->win_h);
	v->add = mlx_get_data_addr(v->img, &v->bpp, &v->line, &v->endian);
	v->s = 0;
	v->ftl = (t_ftl *)malloc(sizeof(t_ftl) * 1);
	v->minx = -3.2;
	v->miny = -3.2;
	v->maxx = 3.4;
	v->maxy = 3.4;
	mlx_key_hook(v->win, ft_key, v);
	mlx_hook(v->win, 6, (1L << 6), ft_motion, v);
	mlx_mouse_hook(v->win, ft_mouse, v);
	mlx_expose_hook(v->win, ft_draw_fractal, v);
	mlx_loop(v->mlx);
	return (0);
}
