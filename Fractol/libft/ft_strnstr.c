/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:56:50 by hcorrale          #+#    #+#             */
/*   Updated: 2015/12/17 14:26:48 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (*s2 == '\0')
		return ((char *)s1);
	i = ft_strlen(s2);
	while (*s1 && n-- >= i)
	{
		if (*s1 == *s2 && ft_memcmp(s1, s2, i) == 0)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
