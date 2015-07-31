/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 09:46:43 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/17 11:07:17 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	unsigned int i;

	i = 1;
	if (base % 2 == 0)
	{
		base = base / 2;
	}
	if (base % 2 != 0)
	{
		if (base != 1)
		{
			base = (base * 3) + 1;
			i++;
		}
		else
			return (i);
	}
	i = i + ft_collatz_conjecture(base);
	return (i);
}
