/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:58:44 by hcorrale          #+#    #+#             */
/*   Updated: 2015/12/14 11:22:47 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((UC)s1[i] == (UC)s2[i] && (UC)s1[i] && (UC)s2[i])
		i++;
	return ((UC)s1[i] - (UC)s2[i]);
}
