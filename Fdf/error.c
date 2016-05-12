/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 13:53:18 by hcorrale          #+#    #+#             */
/*   Updated: 2016/05/12 17:38:19 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_lineerror(char **str, t_var *v)
{
	int		*t;
	int		i;

	i = 0;
	t = (int *)malloc(sizeof(int) * v->l);
	while (i < v->l)
	{
		t[i] = ft_intnb(str[i]);
		if (t[i] != t[0])
		{
			free(t);
			return (-1);
		}
		i++;
	}
	free(t);
	return (0);
}
