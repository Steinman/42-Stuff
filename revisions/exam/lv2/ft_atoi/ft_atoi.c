/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 15:55:49 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/31 23:41:30 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_atoi(char *str)
{
	int i;
	int nb;
	int sign;
	int a;
	
	sign = 1;
	nb = 0;
	a = 0;
	i = 0;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
		a++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		i++;
	while (a < i)
	{
		nb = nb * 10 + (str[a] - '0');
		a++;
	}
	return (nb * sign);
}

int		main()
{
	char str[] = "42";

	printf("%d", ft_atoi(str));
	return (0);
}
