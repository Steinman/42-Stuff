/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:39:45 by hcorrale          #+#    #+#             */
/*   Updated: 2015/12/15 15:03:39 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*tmp;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if ((str = (char *)malloc(sizeof(char) * (i + j + 1))) == NULL)
		return (NULL);
	tmp = str;
	while (*s1)
		*tmp++ = *s1++;
	while (*s2)
		*tmp++ = *s2++;
	*tmp = '\0';
	return (str);
}
