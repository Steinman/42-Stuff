/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 21:16:36 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/26 21:16:59 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_colle00(int x, int y, char *buf)
{
	char	*colle;

	colle = colle00(x, y);
	if (ft_strcmp(colle, buf) == 0)
		return (0);
	return (-1);
}

int		ft_colle01(int x, int y, char *buf)
{
	char	*colle;

	colle = colle01(x, y);
	if (ft_strcmp(colle, buf) == 0)
		return (1);
	return (-1);
}

int		ft_colle02(int x, int y, char *buf)
{
	char	*colle;

	colle = colle02(x, y);
	if (ft_strcmp(colle, buf) == 0)
		return (2);
	return (-1);
}

int		ft_colle03(int x, int y, char *buf)
{
	char	*colle;

	colle = colle03(x, y);
	if (ft_strcmp(colle, buf) == 0)
		return (3);
	return (-1);
}

int		ft_colle04(int x, int y, char *buf)
{
	char	*colle;

	colle = colle04(x, y);
	if (ft_strcmp(colle, buf) == 0)
		return (4);
	return (-1);
}
