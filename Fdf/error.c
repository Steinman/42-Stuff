/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 13:53:18 by hcorrale          #+#    #+#             */
/*   Updated: 2016/05/17 17:58:18 by hcorrale         ###   ########.fr       */
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

int			ft_emptyline(char **str, t_var *v)
{
	int		i;

	i = 0;
	while (i < v->l)
	{
		if (str[i][0] == '\0')
			return (-1);
		i++;
	}
	return (0);
}
