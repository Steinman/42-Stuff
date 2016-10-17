/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:23:43 by hcorrale          #+#    #+#             */
/*   Updated: 2016/10/17 14:43:33 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_ray_init(t_var *v, t_w3d *w, int x)
{
	w->camx = 2 * x / (double)v->win_w - 1;
	w->side = 0;
	w->hit = 0;
	w->rayposx = w->posx;
	w->rayposy = w->posy;
	w->raydirx = w->dirx + w->planex * w->camx;
	w->raydiry = w->diry + w->planey * w->camx;
	w->mapx = (int)w->rayposx;
	w->mapy = (int)w->rayposy;
	w->deltadistx = sqrt(1 + pow(w->raydiry / w->raydirx, 2));
	w->deltadisty = sqrt(1 + pow(w->raydirx / w->raydiry, 2));
}

static void	ft_colors(t_var *v, t_w3d *w, int x)
{
	int		y;

	y = 0;
	while (y < v->win_h)
	{
		if (y < w->drawstart)
			w->color = 0x5AD4EC;
		else if (y > w->drawend)
			w->color = 0x000000;
		else
		{
			if (w->hit == 1)
				w->color = 0x00B2F2;
		}
		ft_pixel_put(v, x, y, w->color);
		y++;
	}
}

void		ft_draw(t_var *v, t_w3d *w)
{
	int		x;

	x = 0;
	while (x < v->win_w)
	{
		ft_ray_init(v, w, x);
		ft_raycast(v, w);
		ft_colors(v, w, x);
		x++;
	}
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
}
