/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 12:55:23 by hcorrale          #+#    #+#             */
/*   Updated: 2016/09/29 14:28:19 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_mlx	ft_mlx_init(t_var *v)
{
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, v->win_w, v->win_h, "Wolf3D");
	v->img = mlx_new_image(v->mlx, v->win_w, v->win_h);
	v->add = mlx_get_data_addr(v->img, &v->bpp, &v->line, &v->endian);
}

int				main(int ac, char **av)
{
	t_var	*v;

	if (ac != 2 || !av[1])
	{
		ft_putendl("ERROR: only one parameter allowed");
		return (0);
	}
	v = (t_var *)malloc(sizeof(t_var) * 1);
	v->win_w = 800;
	v->win_h = 800;
	ft_mlx_init(v);
	return (0);
}
