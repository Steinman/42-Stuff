/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 20:07:33 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/30 23:15:51 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	ft_rot13(char c)
{
	if ((c >= 97 && c <= 109) || (c >= 65 && c <= 77))
	{
		c = (c + 13);
		return (c);
	}
	if ((c >= 110 && c <= 122) || (c >= 78 && c <= 90))
	{
		c = (c - 13);
		return (c);
	}
	return (c);
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc != 2)
		ft_putchar('\n');
	else
	{
		while (argv[1][i] != '\0')
		{
			ft_putchar(ft_rot13(argv[1][i]));
			i++;
		}
		ft_putchar('\n');
	}
	return (0);
}
