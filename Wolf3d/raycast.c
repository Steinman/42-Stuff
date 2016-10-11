/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 14:13:42 by hcorrale          #+#    #+#             */
/*   Updated: 2016/10/11 13:39:16 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_raycast(t_var *v)
{
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	camx;
	double	rayposx;
	double	rayposy;
	double	raydirx;
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	double	dh;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		color;
	int		x;
	int		y;

	dirx = -1;
	diry = 0;
	planex = 0;
	planey = 0.66;
	dh = 2.0;
	x = 0;
	while (x < v->win_w)
	{
		camx = 2 * x / (double)v->win_w - 1;
		side = 0;
		hit = 0;
		rayposx = v->posx;
		rayposy = v->posy;
		raydirx = dirx + planex * camx;
		raydiry = diry + planey * camx;
		mapx = (int)rayposx;
		mapy = (int)rayposy;
		deltadistx = sqrt(1 + pow(raydiry / raydirx, 2));
		deltadisty = sqrt(1 + pow(raydirx / raydiry, 2));
		ft_putendl("initialized");
		if (raydirx < 0)
		{
			stepx = -1;
			sidedistx = (rayposx - (double)mapx) * deltadistx;
		}
		else
		{
			stepx = 1;
			sidedistx = ((double)mapx + 1.0 - rayposx) * deltadistx;
		}
		if (raydiry < 0)
		{
			stepy = -1;
			sidedisty = (rayposy - (double)mapy) * deltadisty;
		}
		else
		{
			stepy = 1;
			sidedisty = ((double)mapy + 1.0 - rayposy) * deltadisty;
		}
		ft_putendl("step done");
		while (hit != 1)
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
		ft_putendl("hit done");
		if (side == 0)
			perpwalldist = fabs((mapx - rayposx + (1 - stepx) / 2) / raydirx);
		else
			perpwalldist = fabs((mapy - rayposy + (1 - stepy) / 2) / raydiry);
		if (perpwalldist <= 0.05)
			perpwalldist = 0.05;
		lineheight = fabs(v->win_h / perpwalldist);
		if ((drawstart = -(lineheight) / dh + v->win_h / 2) < 0)
			drawstart = 0;
		if ((drawend = lineheight / 2 + v->win_h / 2) >= v->win_h)
			drawend = v->win_h - 1;
		ft_putendl("draw init done");
		y = 0;
		while (y < v->win_h)
		{
			if (y < drawstart)
				color = 0x5AD4EC;
			else if (y > drawend)
				color = 0x000000;
			else
			{
				if (hit == 1)
					color = 0x00B2F2;
			}
			ft_pixel_put(v, x, y, color);
			y++;
			ft_putendl("colum readed");
		}
		x++;
		ft_putendl("line readed");
	}
	ft_putendl("loop finished");
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
}
