/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 11:23:01 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/31 12:06:48 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_mirror(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'm')
			ft_putchar('a' - str[i] + 'z');
		else if (str[i] >= 'n' && str[i] <= 'z')
			ft_putchar('z' - str[i] + 'a');
		else if (str[i] >= 'A' && str[i] <= 'M')
			ft_putchar('A' - str[i] + 'Z');
		else if (str[i] >= 'N' && str[i] <= 'Z')
			ft_putchar('Z' - str[i] + 'A');
		else
			ft_putchar(str[i]);
		i++;
	}
	return (str);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		ft_putchar('\n');
	else
	{
		ft_mirror(argv[1]);
		ft_putchar('\n');
	}
	return (0);
}
