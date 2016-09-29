/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:08:22 by hcorrale          #+#    #+#             */
/*   Updated: 2015/12/11 14:51:52 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memalloc(size_t size)
{
	unsigned char	*str;
	size_t			i;

	str = NULL;
	str = (unsigned char *)malloc(size);
	if (str)
	{
		i = 0;
		while (size--)
			str[i++] = 0;
	}
	return ((void *)str);
}
