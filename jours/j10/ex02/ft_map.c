/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 22:17:29 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/21 23:42:20 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *r;

	i = 0;
	r = (int *)malloc(sizeof(int) * length);
	while (i < length)
	{
		r[i] = f(tab[i]);
		i++;
	}
	return (r);
}
