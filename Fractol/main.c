/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:09:33 by hcorrale          #+#    #+#             */
/*   Updated: 2016/06/08 16:42:42 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_escape(int keycode, t_var *v)
{
	if (keycode == 53)
	{
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
		ft_putstr("ERROR: only one parameter is allowed! try with mandelbrot or julia\n");
		free(v);
		exit(0);
	}
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		v->type = 1;
	if (ft_strcmp(av[1], "julia") == 0)
		v->type = 2;
	if (v->type == 0)
	{
		ft_putstr("ERROR: invalid parameter! try with mandelbrot or julia\n");
		free(v);
		exit(0);
	}
}

int			main(int ac, char **av)
{
	t_var	*v;

	v = (t_var *)malloc(sizeof(t_var) * 1);
	ft_check_param(ac, av, v);
	v->win_w = 800;
	v->win_h = 800;
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, v->win_w, v->win_h, "mlx_win");
	v->img = mlx_new_image(v->mlx, v->win_w, v->win_h);
	v->add = mlx_get_data_addr(v->img, &v->bpp, &v->line, &v->endian);
	ft_mandelbrot;
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	mlx_key_hook(v->win, ft_escape, v);
	mlx_loop(v->mlx);
	return (0);
}
