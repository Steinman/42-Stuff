/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/11 17:22:38 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/12 11:41:04 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_lines(int x)
{
	int i;

	i = 0;
	ft_putchar('o');
	while (i < (x - 2))
	{
		ft_putchar('-');
		i++;
	}
	if (x > 1)
		ft_putchar('o');
	ft_putchar('\n');
}

void	colle(int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (x < 1 || y < 1)
		return ;
	ft_lines(x);
	while (i <= (y - 3))
	{
		ft_putchar('|');
		while (j <= (x - 3))
		{
			ft_putchar(' ');
			j++;
		}
		j = 0;
		if (x >= 2)
			ft_putchar('|');
		ft_putchar('\n');
		i++;
	}
	if (y >= 2)
		ft_lines(x);
}
