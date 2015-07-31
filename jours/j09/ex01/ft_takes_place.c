/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 18:14:15 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/16 20:56:05 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_takes_place(int hour)
{
	if ((hour < 0) || (hour > 23))
		return ;
	if ((hour > 0) && (hour < 11))
	{
		printf("THE FOLLOWING TAKES PLACE BETWEEN ");
		printf("%d A.M. and %d A.M.\n", hour, (hour + 1));
	}
	if ((hour > 12) && (hour < 23))
	{
		printf("THE FOLLOWING TAKES PLACE BETWEEN ");
		printf("%d P.M. and %d P.M.\n", (hour - 12), (hour - 11));
	}
	if (hour == 0)
		printf("THE FOLLOWING TAKES PLACE BETWEEN 12 A.M. AND 1 A.M.\n");
	if (hour == 12)
		printf("THE FOLLOWING TAKES PLACE BETWEEN 12 P.M. AND 1 P.M.\n");
	if (hour == 11)
		printf("THE FOLLOWING TAKES PLACE BETWEEN 11 A.M. AND 12 P.M.\n");
	if (hour == 23)
		printf("THE FOLLOWING TAKES PLACE BETWEEN 11 P.M. AND 12 A.M.\n");
}
