/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 12:18:04 by hcorrale          #+#    #+#             */
/*   Updated: 2016/10/18 12:14:28 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_move(t_var *v, int keycode)
{
	if (keycode == 126)
	{
		v->w->posx += v->w->dirx * v->w->spd;
		v->w->posy += v->w->diry * v->w->spd;
	}
	if (keycode == 125)
	{
		v->w->posx -= v->w->dirx * v->w->spd;
		v->w->posy -= v->w->diry * v->w->spd;
	}
}

int			ft_key_hook(int keycode, t_var *v)
{
	printf("keycode = %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_image(v->mlx, v->img);
		mlx_destroy_window(v->mlx, v->win);
		free(v);
		exit(0);
	}
	ft_move(v, keycode);
	ft_draw(v);
	return (0);
}
