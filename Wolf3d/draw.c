/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:23:43 by hcorrale          #+#    #+#             */
/*   Updated: 2016/10/18 13:54:02 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_ray_init(t_var *v, int x)
{
	v->w->camx = 2 * x / (double)v->win_w - 1;
	v->w->side = 0;
	v->w->hit = 0;
	v->w->rayposx = v->w->posx;
	v->w->rayposy = v->w->posy;
	v->w->raydirx = v->w->dirx + v->w->planex * v->w->camx;
	v->w->raydiry = v->w->diry + v->w->planey * v->w->camx;
	v->w->mapx = (int)v->w->rayposx;
	v->w->mapy = (int)v->w->rayposy;
	v->w->deltadistx = sqrt(1 + pow(v->w->raydiry / v->w->raydirx, 2));
	v->w->deltadisty = sqrt(1 + pow(v->w->raydirx / v->w->raydiry, 2));
}

static void	ft_colors(t_var *v, int x)
{
	int		y;

	y = 0;
	while (y < v->win_h)
	{
		if (y < v->w->drawstart)
			v->w->color = 0x5AD4EC;
		else if (y > v->w->drawend)
			v->w->color = 0x000000;
		else
		{
			if (v->w->hit == 1)
				v->w->color = 0x00B2F2;
		}
		ft_pixel_put(v, x, y, v->w->color);
		y++;
	}
}

int			ft_draw(t_var *v)
{
	int		x;

	x = 0;
	while (x < v->win_w)
	{
		ft_ray_init(v, x);
		ft_raycast(v);
		ft_colors(v, x);
		x++;
	}
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	return (0);
}
