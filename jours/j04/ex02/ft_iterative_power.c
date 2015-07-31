/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 19:00:45 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/13 19:57:37 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int i;
	int result;

	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	result = nb;
	i = 1;
	while (i < power)
	{
		result = result * nb;
		i++;
	}
	return (result);
}
