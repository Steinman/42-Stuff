/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 13:46:46 by hcorrale          #+#    #+#             */
/*   Updated: 2016/09/08 14:47:10 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_mandel_init(t_var *v)
{
	v->ftl = (t_ftl *)malloc(sizeof(t_ftl) * 1);
	v->ftl->x1 = -2.1 + v->s;
	v->ftl->x2 = 0.6 - v->s;
	v->ftl->y1 = -1.2 + v->s;
	v->ftl->y2 = 1.2 - v->s;
	v->ftl->imax = 30;
	v->ftl->zoomx = (v->win_w / (v->ftl->x2 - v->ftl->x1));
	v->ftl->zoomy = (v->win_h / (v->ftl->y2 - v->ftl->y1));
}

void		ft_julia_init(t_var *v)
{
	v->ftl = (t_ftl *)malloc(sizeof(t_ftl) * 1);
	v->ftl->x1 = -1 + v->s;
	v->ftl->x2 = 1 - v->s;
	v->ftl->y1 = -1.2 + v->s;
	v->ftl->y2 = 1.2 - v->s;
	v->ftl->imax = 150;
	v->ftl->zoomx = (v->win_w / (v->ftl->x2 - v->ftl->x1));
	v->ftl->zoomy = (v->win_h / (v->ftl->y2 - v->ftl->y1));
}
