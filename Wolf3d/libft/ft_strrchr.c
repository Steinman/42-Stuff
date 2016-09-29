/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:29:14 by hcorrale          #+#    #+#             */
/*   Updated: 2015/12/14 17:06:15 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	str = str + ft_strlen(s);
	while (*str != (char)c && str != s)
		str--;
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}
