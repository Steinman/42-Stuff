/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 12:13:32 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/27 12:18:40 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_alphabet()
{
	int start;
	int end;

	start = 'a';
	end = 'z';
	while(start <= end)
	{
		ft_putchar(start);
		start++;
	}
}

int		main()
{
	ft_print_alphabet();
	return (0);
}
