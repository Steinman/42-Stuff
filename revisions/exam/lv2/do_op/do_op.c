/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 15:08:38 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/31 15:48:32 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_op(int a, int b, char c)
{
	if (c == '+')
		return (a + b);
	else if (c == '-')
		return (a - b);
	else if (c == '*')
		return (a * b);
	else if (c == '/')
		return (a / b);
	else if (c == '%')
		return (a % b);
	else
		return (0);
}

int		main(int argc, char **argv)
{
	int a;
	int b;

	if (argc != 4)
		ft_putchar('\n');
	else
	{
		a = atoi(argv[1]);
		b = atoi(argv[3]);
		printf("%d", ft_op(a, b, argv[2][0]));
		printf("%c", '\n');
	}
	return (0);
}	
