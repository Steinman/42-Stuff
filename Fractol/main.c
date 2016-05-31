/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:09:33 by hcorrale          #+#    #+#             */
/*   Updated: 2016/05/31 16:51:27 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

	v = (t_var *)malloc(sizeof(t_var) * 1);
	v->type = 0;
	if (ac != 2)
	{
		ft_putstr("ERROR: invalid parameter! try with mandelbrot or julia\n");
		return(0);
	}
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		v->type = 1;
	if (ft_strcmp(av[1], "julia") == 0)
		v->type = 2;
	if (v->type == 0)
	{
		ft_putstr("ERROR: invalid parameter! try with mandelbrot or julia\n");
		return (0);
	}
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, 800, 800, "mlx_win");
	mlx_key_hook(v->win, ft_escape, v);
	mlx_loop(v->mlx);
	return (0);
}
