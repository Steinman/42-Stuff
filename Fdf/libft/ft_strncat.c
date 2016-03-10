/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:56:47 by hcorrale          #+#    #+#             */
/*   Updated: 2015/12/14 15:57:35 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	k = i + j;
	j = 0;
	while (i <= k && src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
