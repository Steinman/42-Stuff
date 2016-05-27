/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:34:26 by hcorrale          #+#    #+#             */
/*   Updated: 2016/05/27 16:17:40 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_pixel_put(t_var *v, int color)
{
	int		i;
	char	*rgb;

	rgb = (char *)&color;
	v->add[i] = rgb[0];
	v->add[++i] = rgb[1];
	v->add[++i] = rgb[2];
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

int			main()
{
	t_var	*v;

	v = (t_var *)malloc(sizeof(t_var) * 1);
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, 800, 800, "mlx_win");
	v->img = mlx_new_image(v->mlx, 800, 800);
	v->add = mlx_get_data_addr(v->img, &v->bpp, &v->line, &v->endian);
	printf("bpp = %d\n", v->bpp);
	printf("line = %d\n", v->line);
	printf("endian = %d\n", v->endian);
	printf("white = %d\n", mlx_get_color_value(v->mlx, 0xFFFFFF));
	mlx_key_hook(v->win, ft_escape, v);
	mlx_loop(v->mlx);
}
