/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 23:06:37 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/17 23:12:25 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_strlen(char *str)
{
	int l;

	l = 0;
	while (*str++ != '\0')
		l++;
	return (l);
}

char		*ft_strdup(char *src)
{
	int		i;
	char	*cpy;

	i = ft_strlen(src);
	if ((cpy = malloc(sizeof(*src) * (i + 1))) == NULL)
		return (NULL);
	while (i >= 0)
	{
		cpy[i] = src[i];
		i--;
	}
	return (cpy);
}
