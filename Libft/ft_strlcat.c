/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:24:07 by hcorrale          #+#    #+#             */
/*   Updated: 2015/12/14 16:13:43 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (dest[i] != '\0' && i < n)
		i++;
	k = i;
	while (src[j] != '\0' && i < n - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (k < n)
		dest[i] = '\0';
	return (k + ft_strlen(src));
}
