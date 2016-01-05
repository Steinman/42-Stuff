/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:00:17 by hcorrale          #+#    #+#             */
/*   Updated: 2015/12/15 15:37:31 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_number(const char *s, char c)
{
	size_t		number;
	size_t		sub;

	sub = 0;
	number = 0;
	while (*s)
	{
		if (sub == 1 && *s == c)
			sub = 0;
		if (sub == 0 && *s != c)
		{
			sub = 1;
			number++;
		}
		s++;
	}
	return (number);
}

static size_t	ft_wordlen(const char *s, char c)
{
	size_t		i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**t;
	size_t		num;
	size_t		i;

	i = 0;
	num = ft_number(s, c);
	if ((t = (char **)malloc(sizeof(*t) * num + 1)) == NULL)
		return (NULL);
	while (num--)
	{
		while (*s == c && *s)
			s++;
		t[i] = ft_strsub(s, 0, ft_wordlen(s, c));
		if (t[i] == NULL)
			return (NULL);
		s = s + ft_wordlen(s, c);
		i++;
	}
	t[i] = NULL;
	return (t);
}
