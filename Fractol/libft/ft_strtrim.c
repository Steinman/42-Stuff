/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 10:39:11 by hcorrale          #+#    #+#             */
/*   Updated: 2015/12/15 15:30:18 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	char		*str;
	int			i;
	int			j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j--;
	if (j != -1)
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
	}
	j = j - i + 1;
	if ((str = (char *)malloc(sizeof(char) * j + 1)) == NULL)
		return (NULL);
	s = s + i;
	i = 0;
	while (i < j)
		str[i++] = *s++;
	str[i] = '\0';
	return (str);
}
