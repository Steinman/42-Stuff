/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 21:13:52 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/26 21:27:07 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int num;

	num = 0;
	while (str[num] != '\0')
	{
		ft_putchar(str[num]);
		num++;
	}
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

int		ft_print(int num, int x, int y)
{
	if (num != -1)
	{
		ft_putstr("[colle-0");
		ft_putnbr(num);
		ft_putstr("] [");
		ft_putnbr(x);
		ft_putstr("] [");
		ft_putnbr(y);
		ft_putstr("]");
		if (num >= 2 && x == 1 && y == 1 && num < 4)
			ft_putstr(" || ");
		if (num == 2 && x == 1 && y == 2)
			ft_putstr(" || ");
		if (num == 3 && x == 2 && y == 1)
			ft_putstr(" || ");
	}
	return (num);
}
