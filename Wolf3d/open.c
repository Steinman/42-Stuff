/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:23:15 by hcorrale          #+#    #+#             */
/*   Updated: 2016/09/29 16:36:16 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			ft_open(t_var *v, char *file, int fd)
{
	char	*line;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		v->err = 1;
		return (0);
	}
	v->buf = ft_strnew(1);
	while ((v->err = get_next_line(fd, &line)) > 0)
	{
		v->buf = ft_strjoin(v->buf, line);
		v->buf = ft_strjoin(v->buf, "\n");
	}
	if (v->err == -1)
	{
		v->err = 2;
		return (0);
	}
	v->map = ft_strsplit(v->buf, '\n');
	return (0);
}
