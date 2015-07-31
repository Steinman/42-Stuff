/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 23:18:09 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/17 23:18:29 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int **t;
	int m;

	if (min >= max)
		return (0);
	m = max - min - 1;
	if ((t = (int **)malloc(sizeof(int) * m)) == NULL)
		return (0);
	m++;
	while (m > min)
		t[m--] = m;
	range = t;
	return (m);
}
