/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 14:13:42 by hcorrale          #+#    #+#             */
/*   Updated: 2016/10/18 11:52:45 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_step(t_var *v)
{
	if (v->w->raydirx < 0)
	{
		v->w->stepx = -1;
		v->w->sidedistx = (v->w->rayposx - (double)v->w->mapx) * v->w->deltadistx;
	}
	else
	{
		v->w->stepx = 1;
		v->w->sidedistx = ((double)v->w->mapx + 1.0 - v->w->rayposx) * v->w->deltadistx;
	}
	if (v->w->raydiry < 0)
	{
		v->w->stepy = -1;
		v->w->sidedisty = (v->w->rayposy - (double)v->w->mapy) * v->w->deltadisty;
	}
	else
	{
		v->w->stepy = 1;
		v->w->sidedisty = ((double)v->w->mapy + 1.0 - v->w->rayposy) * v->w->deltadisty;
	}
}

static void	ft_hit(t_var *v)
{
	while (v->w->hit != 1)
	{
		if (v->w->sidedistx < v->w->sidedisty)
		{
			v->w->sidedistx += v->w->deltadistx;
			v->w->mapx += v->w->stepx;
			v->w->side = 0;
		}
		else
		{
			v->w->sidedisty += v->w->deltadisty;
			v->w->mapy += v->w->stepy;
			v->w->side = 1;
		}
		if (v->map[v->w->mapy][v->w->mapx] == '1')
			v->w->hit = 1;
	}
}

static void	ft_wall(t_var *v)
{
	if (v->w->side == 0)
		v->w->perpwalldist = fabs((v->w->mapx - v->w->rayposx + (1 - v->w->stepx) / 2) / v->w->raydirx);
	else
		v->w->perpwalldist = fabs((v->w->mapy - v->w->rayposy + (1 - v->w->stepy) / 2) / v->w->raydiry);
	if (v->w->perpwalldist <= 0.05)
		v->w->perpwalldist = 0.05;
}

void		ft_raycast(t_var *v)
{
	double	dh;

	dh = 2.0;
	ft_step(v);
	ft_hit(v);
	ft_wall(v);
	v->w->lineheight = fabs(v->win_h / v->w->perpwalldist);
	if ((v->w->drawstart = -(v->w->lineheight) / dh + v->win_h / 2) < 0)
		v->w->drawstart = 0;
	if ((v->w->drawend = v->w->lineheight / 2 + v->win_h / 2) >= v->win_h)
		v->w->drawend = v->win_h - 1;
}
