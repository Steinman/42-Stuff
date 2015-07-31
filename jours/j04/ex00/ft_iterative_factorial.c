/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 11:38:51 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/13 16:00:04 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int result;
	int i;

	if (nb < 0 || nb > 13)
		return (0);
	result = nb;
	i = 1;
	while (i < nb)
	{
		result = result * (nb - i);
		i++;
	}
	return (result);
}
