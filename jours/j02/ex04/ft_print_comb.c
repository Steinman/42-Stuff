/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 23:20:20 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/10 23:38:19 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	affichage(int a, int b, int c)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(c);
	ft_putchar('\n');
}

void	ft_print_comb(int d, int e, int f)
{
	int a;
	int b;
	int c;

	a = '0';
	b = '0';
	c = '0';
	while (a <= '9')
	{
		while (b <= '9')
		{
			while (c <= '9')
			{
				if (a < b && a < c && b < c)
				{
					affichage(a, b, c);
				}
				c++;
			}
			c = '0';
			b++;
		}
		b = '0';
		a++;
	}
}
