/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 23:14:03 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/17 23:14:39 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *t;
	int m;

	if (min >= max)
		return (NULL);
	m = max - min - 1;
	if ((t = (int *)malloc(sizeof(int) * m)) == NULL)
		return (NULL);
	m++;
	while (m > min)
		t[m--] = m;
	return (t);
}
