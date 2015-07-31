/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 16:03:31 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/27 17:11:59 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int swap;

	swap = *a;
	*a = *a / *b;
	*b = swap % *b;
}

int		main()
{
	int a;
	int b;

	a = 13;
	b = 2;
	ft_ultimate_div_mod(&a, &b);
	printf("%d", a);
	printf("%d", b);
	return (0);
}
