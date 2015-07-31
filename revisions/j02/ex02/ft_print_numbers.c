/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 12:27:20 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/27 12:32:06 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_print_numbers()
{
	int start;
	int end;

	start = '0';
	end = '9';
	while (start <= end)
	{
		ft_putchar(start);
		start ++;
	}
}

int     main()
{
	ft_print_numbers();
	return (0);
}
