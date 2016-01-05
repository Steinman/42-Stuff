/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 15:33:06 by hcorrale          #+#    #+#             */
/*   Updated: 2016/01/05 17:31:44 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_read(char *argv, int fd)
{
	char	*buf;
	int		ret;

	if ((fd = open(argv, O_RDONLY)) == -1)
		return (NULL);
	if (!(buf = (char *)malloc(sizeof(char) * BUF_SIZE)))
		return (NULL);
	if ((ret = read(fd, buf, BUF_SIZE)) == -1 || ret == 0)
		return (NULL);
}
