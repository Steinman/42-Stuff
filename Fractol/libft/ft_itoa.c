/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:40:03 by hcorrale          #+#    #+#             */
/*   Updated: 2015/12/15 17:20:33 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = n;
	if (n < 0)
		i++;
	while (j /= 10)
		i++;
	if ((str = (char *)malloc(sizeof(char) * i + 2)) == NULL)
		return (NULL);
	while (str[j])
		str[j++] = '\0';
	str[i--] = ft_abs(n % 10) + '0';
	while (n /= 10)
		str[i--] = ft_abs(n % 10) + '0';
	if (str[0] == '\0')
		str[0] = '-';
	return (str);
}
