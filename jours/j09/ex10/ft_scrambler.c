/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scrambler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 13:45:41 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/17 14:23:59 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_scrambler(int ***a, int *b, int *******c, int ****d)
{
	int swapa;
	int swapb;
	int swapc;
	int swapd;

	swapc = ***a;
	swapb = ****d;
	swapa = *b;
	swapd = *******c;
	***a = swapa;
	*b = swapb;
	*******c = swapc;
	****d = swapd;
}
