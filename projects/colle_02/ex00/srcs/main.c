/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 21:17:19 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/26 21:26:42 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_read(void)
{
	int		ret;
	char	*str1;
	char	*str2;
	char	buffer[2];
	int		j;

	str1 = (char *)malloc(sizeof(char) + 1);
	str2 = (char *)malloc(sizeof(char) + 1);
	j = 1;
	while ((ret = read(0, buffer, 1)))
	{
		buffer[ret] = '\0';
		str2 = (char *)malloc(sizeof(char) * j + 1);
		ft_strcpy(str2, str1);
		str1 = (char *)malloc(sizeof(char) * j + 1);
		str1 = ft_strcat(str2, buffer);
		j++;
	}
	return (str1);
}

void	ft_output(char *str1, int x, int y)
{
	int		i;

	i = 0;
	if (str1[0] == 'A')
	{
		i += ft_print(ft_colle02(x, y, str1), x, y);
		i += ft_print(ft_colle03(x, y, str1), x, y);
		i += ft_print(ft_colle04(x, y, str1), x, y);
	}
	else if (str1[0] == 'o')
		i += ft_print(ft_colle00(x, y, str1), x, y);
	else if (str1[0] == '/')
		i += ft_print(ft_colle01(x, y, str1), x, y);
	else
		ft_putstr("aucune");
	if (i < 0)
		ft_putstr("aucune");
	ft_putchar('\n');
}

int		main(void)
{
	int		x;
	int		y;
	char	*str1;

	x = 0;
	y = 0;
	str1 = ft_read();
	while (str1[0] != '\0' && str1[x] != '\0')
	{
		while (str1[x] != '\n')
			x++;
		x = x + 1;
		y++;
	}
	x = 0;
	while (str1[0] != '\0' && str1[x] != '\n')
		x++;
	ft_output(str1, x, y);
	return (0);
}
