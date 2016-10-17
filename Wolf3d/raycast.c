/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 14:13:42 by hcorrale          #+#    #+#             */
/*   Updated: 2016/10/17 14:39:12 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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

static void	ft_hit(t_var *v, t_w3d *w)
{
	while (w->hit != 1)
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
		if (v->map[w->mapy][w->mapx] == '1')
			w->hit = 1;
	}
}

static void	ft_wall(t_w3d *w)
{
	if (w->side == 0)
		w->perpwalldist = fabs((w->mapx - w->rayposx + (1 - w->stepx) / 2) / w->raydirx);
	else
		w->perpwalldist = fabs((w->mapy - w->rayposy + (1 - w->stepy) / 2) / w->raydiry);
	if (w->perpwalldist <= 0.05)
		w->perpwalldist = 0.05;
}

void		ft_raycast(t_var *v, t_w3d *w)
{
	double	dh;

	dh = 2.0;
	ft_step(w);
	ft_hit(v, w);
	ft_wall(w);
	w->lineheight = fabs(v->win_h / w->perpwalldist);
	if ((w->drawstart = -(w->lineheight) / dh + v->win_h / 2) < 0)
		w->drawstart = 0;
	if ((w->drawend = w->lineheight / 2 + v->win_h / 2) >= v->win_h)
		w->drawend = v->win_h - 1;
}
