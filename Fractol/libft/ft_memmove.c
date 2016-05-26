/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:05:56 by hcorrale          #+#    #+#             */
/*   Updated: 2015/12/22 13:27:22 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	UC		*str1;
	UC		*str2;

	str1 = (UC *)dest;
	str2 = (UC *)src;
	if (dest > src)
	{
		str1 += n;
		str2 += n;
		while (n--)
			*--str1 = *--str2;
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
