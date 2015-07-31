/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 12:19:35 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/27 12:25:48 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_reverse_alphabet()
{
	int start;
	int end;

	start = 'z';
	end = 'a';
	while (start >= end)
	{
		ft_putchar(start);
		start --;
	}
}

int		main()
{
	ft_print_reverse_alphabet();
	return (0);
}
