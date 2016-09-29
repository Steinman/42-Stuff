/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:16:44 by hcorrale          #+#    #+#             */
/*   Updated: 2015/12/14 13:33:25 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (UC *)dest;
	str2 = (UC *)src;
	i = 0;
	while (i < n)
	{
		if ((*str1++ = *str2++) == (UC)c)
			return (str1);
		i++;
	}
	return (NULL);
}
