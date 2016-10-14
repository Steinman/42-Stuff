/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 14:13:42 by hcorrale          #+#    #+#             */
/*   Updated: 2016/10/14 14:14:13 by hcorrale         ###   ########.fr       */
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

static void	ft_step(t_w3d *w)
{
	if (w->raydirx < 0)
	{
		w->stepx = -1;
		w->sidedistx = (w->rayposx - (double)w->mapx) * w->deltadistx;
	}
	else
	{
		w->stepx = 1;
		w->sidedistx = ((double)w->mapx + 1.0 - w->rayposx) * w->deltadistx;
	}
	if (w->raydiry < 0)
	{
		w->stepy = -1;
		w->sidedisty = (w->rayposy - (double)w->mapy) * w->deltadisty;
	}
	else
	{
		w->stepy = 1;
		w->sidedisty = ((double)w->mapy + 1.0 - w->rayposy) * w->deltadisty;
	}
}

void		ft_hit(t_var *v, t_w3d *w)
{
	while (w->hit != 1 && w->mapy > 0 &&
			w->mapy < (int)ft_linelen(v->map[w->mapx], 0) &&
			w->mapx > 0 && w->mapx <= v->line_nb)
	{
		if (w->sidedistx < w->sidedisty)
		{
			w->sidedistx += w->deltadistx;
			w->mapx += w->stepx;
			w->side = 0;
		}
		else
		{
			w->sidedisty += w->deltadisty;
			w->mapy += w->stepy;
			w->side = 1;
		}
		if (v->map[w->mapx][w->mapy] == '1')
			w->hit = 1;
	}
}

void		ft_raycast(t_var *v, t_w3d *w)
{
	double	dh;
	int		x;
	int		y;

	w->dirx = -1;
	w->diry = 0;
	w->planex = 0;
	w->planey = 0.66;
	dh = 2.0;
	x = 0;
	while (x < v->win_w)
	{
		ft_ray_init(v, w, x);
		ft_step(w);
		ft_hit(v, w);
		if (w->side == 0)
			w->perpwalldist = fabs((w->mapx - w->rayposx + (1 - w->stepx) / 2) / w->raydirx);
		else
			w->perpwalldist = fabs((w->mapy - w->rayposy + (1 - w->stepy) / 2) / w->raydiry);
		if (w->perpwalldist <= 0.05)
			w->perpwalldist = 0.05;
		w->lineheight = fabs(v->win_h / w->perpwalldist);
		if ((w->drawstart = -(w->lineheight) / dh + v->win_h / 2) < 0)
			w->drawstart = 0;
		if ((w->drawend = w->lineheight / 2 + v->win_h / 2) >= v->win_h)
			w->drawend = v->win_h - 1;
		//ft_putendl("draw init done");
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
		x++;
	}
	//ft_putendl("loop finished");
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
}
