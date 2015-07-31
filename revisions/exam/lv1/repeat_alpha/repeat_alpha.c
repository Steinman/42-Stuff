/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 17:02:25 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/30 19:53:45 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_howmany(char c)
{
	int num;

	if (c >= 97 && c <= 122)
	{
		num = (c - 96);
		return (num);
	}
	if (c >= 65 && c <= 90)
	{
		num = (c - 64);
		return (num);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int i;
	int num;

	i = 0;
	if (argc != 2)
		ft_putchar('\n');
	else
	{
		while (argv[1][i] != '\0')
		{
			num = ft_howmany(argv[1][i]);
			while(num > 0)
			{
				ft_putchar(argv[1][i]);
				num--;
			}
			i++;
		}
		ft_putchar('\n');
	}
	return (0);
} 
