/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:23:15 by hcorrale          #+#    #+#             */
/*   Updated: 2016/10/03 12:51:22 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	ft_char_error(t_var *v, size_t len, int line)
{
	size_t	i;
	int		j;

	j = 0;
	while (j < line)
	{
		i = 0;
		while (i != len)
		{
			if (v->map[j][i] != '0' || v->map[j][i] != '1' || v->map[j][i] != 'X')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

static int	ft_line_error(t_var *v, size_t len, int line)
{
	int		i;

	i = 0;
	while (i < line)
	{
		if (ft_strlen(v->map[i]) != len)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_file_error(int line, t_var *v)
{
	size_t	len;

	len = ft_strlen(v->map[0]);
	if (ft_line_error(v, len, line) == 1)
	{
		v->err = 3;
		return (1);
	}
	else if (ft_char_error(v, len, line) == 1)
	{
		v->err = 4;
		return (1);
	}
	return (0);
}

int			ft_open(t_var *v, char *file, int fd)
{
	char	*line;
	int		line_nb;

	line_nb = 0;
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
		line_nb++;
	}
	if (v->err == -1)
	{
		v->err = 2;
		return (0);
	}
	v->map = ft_strsplit(v->buf, '\n');
	if (ft_file_error(line_nb, v) == 1)
		return (0);
	return (0);
}
