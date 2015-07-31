/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle04.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 21:50:53 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/26 21:51:07 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_lines04(int a, int b, int i, int x)
{
	char	*tab;
	int		j;

	j = 0;
	tab = malloc(sizeof(char) * (x + 1));
	if (x > 0)
	{
		tab[j] = a;
		j++;
		while (i < x - 1)
		{
			tab[j] = 'B';
			j++;
			i++;
		}
		if (x > 1)
		{
			tab[j] = b;
			j++;
			i++;
		}
		tab[j] = '\n';
	}
	return (tab);
}

char	*ft_column04(int count_x, int count_y, int x, int y)
{
	char	*tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char) * (x * (y - 2) + x));
	if (y >= 3)
	{
		while (count_y < y - 1)
		{
			tab[i] = 'B';
			i++;
			while (count_x < x - 1)
			{
				tab[i] = ' ';
				i++;
				count_x++;
			}
			tab[i] = 'B';
			tab[i + 1] = '\n';
			i += 2;
			count_y++;
			count_x = 1;
		}
	}
	return (tab);
}

char	*colle04(int x, int y)
{
	char	*tab;

	tab = 0;
	if (!(x <= 0) || !(y <= 0))
	{
		tab = malloc(sizeof(char) * ((x * y) + y));
		tab = ft_strcpy(tab, ft_lines04('A', 'C', 1, x));
		tab = ft_strcat(tab, ft_column04(1, 1, x, y));
		if (y > 1)
			tab = ft_strcat(tab, ft_lines04('C', 'A', 1, x));
	}
	return (tab);
}
