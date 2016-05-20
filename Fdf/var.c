/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 16:27:29 by hcorrale          #+#    #+#             */
/*   Updated: 2016/05/20 16:59:32 by hcorrale         ###   ########.fr       */
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
