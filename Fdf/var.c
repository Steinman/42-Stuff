/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 16:27:29 by hcorrale          #+#    #+#             */
/*   Updated: 2016/05/26 13:19:45 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_var			*ft_graph_init(t_var *v)
{
	v->winx = 800;
	v->winy = 800;
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, v->winx, v->winy, "mlx_win");
	v->mul = v->winx;
	if (v->len > v->l)
		while ((v->len * v->mul) > v->winy)
			v->mul--;
	else
		while ((v->l * v->mul) > v->winx)
			v->mul--;
	return (v);
}

t_var			*ft_points_init(t_var *v, int j)
{
	v->a.x = ((v->winx - (v->len * (v->mul / 2))) / 2 -
			((v->l * (v->mul / 2)) / 2) + j * (v->mul / 2));
	if (v->len >= v->l)
		v->a.y = v->winy - ((v->len + v->l) / 2 * (v->mul / 2))
			+ j * (v->mul / 3);
	else
		v->a.y = v->winy - (v->l * (v->mul / 2)) + j * (v->mul / 3);
	v->b.x = v->a.x + v->mul / 2;
	v->b.y = v->a.y - v->mul / 3;
	return (v);
}
