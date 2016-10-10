/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 14:13:42 by hcorrale          #+#    #+#             */
/*   Updated: 2016/10/10 15:22:46 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			ft_raycast(t_var *v)
{
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	time;
	double	oldtime;
	double	camx;
	double	rayx;
	double	rayy;
	double	raydirx;
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		mapx;
	int		may;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		color;
	int		x;

	posx = 22;
	posy = 12;
	dirx = -1;
	diry = 0;
	planex = 0;
	planey = 0.66;
	time = 0;
	oldtime = 0;
	x = 0;
	hit = 0;
	color = 0x0000FF;
	while (x < v->win_w)
	{
		camx = 2 * x / double(v->win_w) - 1;
		rayposx = v->posx;
		rayposy = v->posy;
		raydirx = dirx + planex * camx;
		raydiry = diry + planey * camx;
		mapx = int(rayposx);
		mapy = int(rayposy);
		deltadistx = sqrt(1 + (raydiry * raydiry) / (raydirx * raydirx));
		deltadisty = sqrt(1 + (raydirx * raydirx) / (raydiry * raydiry));
		if (raydirx < 0)
		{
			stepx = -1;
			sidedistx = (rayposx - mapx) * deltadistx;
		}
		else
		{
			stepx = 1;
			sidedistx = (mapx + 1.0 - rayposx) * deltadistx;
		}
		if (raydiry < 0)
		{
			stepy = -1;
			sidedisty = (rayposy - mapy) * deltadisty;
		}
		else
		{
			stepy = 1;
			sidedisty = (mapy + 1.0 - rayposy) * deltadisty;
		}
		while (hit == 0)
		{
			if (sidedistx < sidedisty)
			{
				sidedistx += deltadistx;
				mapx += stepx;
				side = 0;
			}
			else
			{
				sidedisty += deltadisty;
				mapy += stepy;
				side = 1;
			}
			if (v->map[mapx][mapy] == '1')
				hit = 1;
		}
		if (side == 0)
			perpwalldist = (mapx - rayposx + (1 - stepx) / 2) / raydirx;
		else
			perpwalldist = (mapy - rayposy + (1 - stepy) / 2) / raydiry;
		lineheight = int(v->win_h / perpwalldist);
		drawstart = -lineheight / 2 + v->win_h / 2;
		if (drawstart < 0)
			drawstart = 0;
		drawend = lineheight / 2 + v->win_h / 2;
		if (drawend >= v->win_h)
			drawend = v->win_h - 1;
		if (side == 1)
			color = color / 2;
	}
}
