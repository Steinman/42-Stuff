/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:34:26 by hcorrale          #+#    #+#             */
/*   Updated: 2016/05/30 15:55:26 by hcorrale         ###   ########.fr       */
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

int			main()
{
	t_var	*v;
	t_point	a;
	t_point	b;

	a.x = 100;
	a.y = 100;
	b.x = 500;
	b.y = 750;
	v = (t_var *)malloc(sizeof(t_var) * 1);
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, 800, 800, "mlx_win");
	v->img = mlx_new_image(v->mlx, 800, 800);
	v->add = mlx_get_data_addr(v->img, &v->bpp, &v->line, &v->endian);
	printf("bpp = %d\n", v->bpp);
	printf("line = %d\n", v->line);
	printf("endian = %d\n", v->endian);
	ft_draw_line(a, b, v, 0xFFFFFF);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	mlx_key_hook(v->win, ft_escape, v);
	mlx_loop(v->mlx);
}
