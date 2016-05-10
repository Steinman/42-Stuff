/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 13:53:18 by hcorrale          #+#    #+#             */
/*   Updated: 2016/05/10 16:18:21 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_charerror(char **str, t_var v)
{
	int		i;
	int		j;

	j = 0;
	while (j < v->l)
	{
		i = 0;
		while (str[j][i] != '\0')
		{
			if (ft_isdigitchar(str[i]) == 0 && str[i] != ' ' && str[i] !+ '-')
					return(-1);
		}
		j++;
	}
	return (0);
}

int			ft_lineerror(char **str, t_var v)
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
