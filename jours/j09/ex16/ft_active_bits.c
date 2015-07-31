/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 12:13:04 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/17 12:26:49 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_active_bits(int value)
{
	unsigned int i;

	i = 0;
	while (value > 0)
	{
		if (value & 1)
		{
			value >>= 1;
			i++;
		}
		else
			value >>= 1;
	}
	return (i);
}
