/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 12:18:04 by hcorrale          #+#    #+#             */
/*   Updated: 2016/10/25 12:59:47 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_move(t_var *v, int keycode)
{
	if (keycode == 126)
	{
		if (v->map[(int)v->w->posy][(int)(v->w->posx + v->w->dirx *
					v->w->spd)] != '1')
			v->w->posx += v->w->dirx * v->w->spd;
		if (v->map[(int)(v->w->posy + v->w->diry *
					v->w->spd)][(int)v->w->posx] != '1')
			v->w->posy += v->w->diry * v->w->spd;
	}
	if (keycode == 125)
	{
		if (v->map[(int)v->w->posy][(int)(v->w->posx - v->w->dirx *
					v->w->spd)] != '1')
			v->w->posx -= v->w->dirx * v->w->spd;
		if (v->map[(int)(v->w->posy - v->w->diry *
					v->w->spd)][(int)v->w->posx] != '1')
			v->w->posy -= v->w->diry * v->w->spd;
	}
}

static void	ft_rotate(int keycode, t_var *v, double tmpdir, double tmpplane)
{
	if (keycode == 123)
	{
		v->w->dirx = v->w->dirx * cos(v->w->rtspd) -
			v->w->diry * sin(v->w->rtspd);
		v->w->diry = tmpdir * sin(v->w->rtspd) +
			v->w->diry * cos(v->w->rtspd);
		v->w->planex = v->w->planex * cos(v->w->rtspd) -
			v->w->planey * sin(v->w->rtspd);
		v->w->planey = tmpplane * sin(v->w->rtspd) +
			v->w->planey * cos(v->w->rtspd);
	}
	if (keycode == 124)
	{
		v->w->dirx = v->w->dirx * cos(-v->w->rtspd) -
			v->w->diry * sin(-v->w->rtspd);
		v->w->diry = tmpdir * sin(-v->w->rtspd) +
			v->w->diry * cos(-v->w->rtspd);
		v->w->planex = v->w->planex * cos(-v->w->rtspd) -
			v->w->planey * sin(-v->w->rtspd);
		v->w->planey = tmpplane * sin(-v->w->rtspd) +
			v->w->planey * cos(-v->w->rtspd);
	}
}

int			ft_key_hook(int keycode, t_var *v)
{
	if (keycode == 53)
	{
		mlx_destroy_image(v->mlx, v->img);
		mlx_destroy_window(v->mlx, v->win);
		free(v);
		exit(0);
	}
	ft_move(v, keycode);
	ft_rotate(keycode, v, v->w->dirx, v->w->planex);
	ft_draw(v);
	return (0);
}
