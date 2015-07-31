/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 16:43:05 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/30 16:55:01 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

int		main()
{
	int a;
	int b;

	a = 42;
	b = 7;
	printf("%d", a);
	printf("%d", b);
	ft_swap(&a, &b);
	printf("%d", a);
	printf("%d", b);
	return (0);
}
