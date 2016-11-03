/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 12:55:23 by hcorrale          #+#    #+#             */
/*   Updated: 2016/11/03 12:09:19 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ft_mlx_init(t_var *v)
{
	v->win_w = 800;
	v->win_h = 800;
	v->line_nb = 0;
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, v->win_w, v->win_h, "Wolf3D");
	v->img = mlx_new_image(v->mlx, v->win_w, v->win_h);
	v->add = mlx_get_data_addr(v->img, &v->bpp, &v->line, &v->endian);
	v->w = (t_w3d *)malloc(sizeof(t_w3d) * 1);
}

static int		ft_error(int err)
{
	if (err == 1)
	{
		ft_putendl("ERROR: Invalid parameter");
		return (1);
	}
	else if (err == 2)
	{
		ft_putendl("ERROR: Invalid file");
		return (1);
	}
	else if (err == 3)
	{
		ft_putendl("ERROR: Invalid map file");
		return (1);
	}
	else if (err == 4)
	{
		ft_putendl("ERROR: Invalid character in map file");
		return (1);
	}
	return (0);
}

int				main(int ac, char **av)
{
	t_var	*v;
	int		exit;

	if (ac != 2 || !av[1])
	{
		ft_putendl("ERROR: only one parameter allowed");
		return (0);
	}
	v = (t_var *)malloc(sizeof(t_var) * 1);
	ft_mlx_init(v);
	if (ft_open(v, av[1], 0) == 1)
	{
		if ((exit = ft_error(v->err)) == 1)
			return (0);
	}
	ft_map_check(v, 0, 0);
	if (ft_find_player(v, 0, 0) == -1)
	{
		ft_putendl("ERROR: Missing player spawnpoint in map file");
		return (0);
	}
	mlx_expose_hook(v->win, ft_draw, v);
	mlx_hook(v->win, 2, 1L << 0, ft_key_hook, v);
	mlx_loop(v->mlx);
	return (0);
}
