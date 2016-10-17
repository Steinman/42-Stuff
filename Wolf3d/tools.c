/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 12:37:11 by hcorrale          #+#    #+#             */
/*   Updated: 2016/10/17 12:12:02 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_pixel_put(t_var *v, int x, int y, int color)
{
	int		i;
	char	*rgb;

	if (x > 0 && x<= v->win_w && y > 0 && y <= v->win_h)
	{
		i = x * (v->bpp / 8) + (y * v->line);
		rgb = (char *)&color;
		v->add[i] = rgb[0];
		v->add[++i] = rgb[1];
		v->add[++i] = rgb[2];
	}
}

int			ft_find_player(t_var *v, t_w3d *w)
{
	int		j;
	int		i;

	j = 0;
	while (j < v->line_nb)
	{
		i = 0;
		while (v->map[j][i] != '\0')
		{
			if (v->map[j][i] == 'X')
			{
				w->posx = i;
				w->posy = j;
				w->dirx = -1;
				w->diry = 0;
				w->planex = 0;
				w->planey = 0.6;
				return (0);
			}
			i++;
		}
		j++;
	}
	return (-1);
}

int			ft_linelen(char *str, int i)
{
	int		len;

	len = 0;
	while(str[i] != '\n' && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}
