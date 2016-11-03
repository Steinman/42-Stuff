/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 12:37:11 by hcorrale          #+#    #+#             */
/*   Updated: 2016/11/03 11:53:47 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_pixel_put(t_var *v, int x, int y, int color)
{
	int		i;
	char	*rgb;

	if (x > 0 && x <= v->win_w && y > 0 && y <= v->win_h)
	{
		i = x * (v->bpp / 8) + (y * v->line);
		rgb = (char *)&color;
		v->add[i] = rgb[0];
		v->add[++i] = rgb[1];
		v->add[++i] = rgb[2];
	}
}

int			ft_find_player(t_var *v, int i, int j)
{
	while (j < v->line_nb)
	{
		i = 0;
		while (v->map[j][i] != '\0')
		{
			if (v->map[j][i] == 'X')
			{
				v->w->posx = i;
				v->w->posy = j;
				v->w->dirx = -1;
				v->w->diry = 0;
				v->w->planex = 0;
				v->w->planey = 0.6;
				v->w->spd = 0.2;
				v->w->rtspd = 0.05;
				return (0);
			}
			i++;
		}
		j++;
	}
	return (-1);
}

int			ft_map_check(t_var *v, int i, int j)
{
	int		len;

	len = ft_strlen(v->map[0]);
	while (j < v->line_nb)
	{
		i = 0;
		if (j == 0 || j == v->line_nb - 1)
		{
			while (v->map[j][i] != '\0')
			{
				v->map[j][i] = '1';
				i++;
			}
		}
		i = 0;
		while (v->map[j][i] != '\0')
		{
			if (i == 0 || i == len - 1)
				v->map[j][i] = '1';
			i++;
		}
		j++;
	}
	return (0);
}

int			ft_linelen(char *str, int i)
{
	int		len;

	len = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}
