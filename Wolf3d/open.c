/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:23:15 by hcorrale          #+#    #+#             */
/*   Updated: 2016/10/06 15:50:01 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	ft_char_error(t_var *v)
{
	int		i;

	i = 0;
	if (v->buf[0] == '\0' || v->buf[0] == '\n')
		return (1);
	while (v->buf[i] != '\0')
		i++;
	v->buf[i - 1] = '\0';
	i = 0;
	while (v->buf[i] != '\0')
	{
		if (v->buf[i] != '0' && v->buf[i] != '1' && v->buf[i] != 'X' && v->buf[i] != '\n')
			return (1);
		if (v->buf[i] == '\n' && (v->buf[i + 1] == '\n' || v->buf[i + 1] == '\0'))
			return(1);
		i++;
	}
	return (0);
}

static int	ft_line_error(t_var *v, size_t len, int line)
{
	int		i;

	i = 0;
	while (i < (line - 1))
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

	if (ft_char_error(v) == 1)
	{
		v->err = 4;
		return (1);
	}
	len = ft_strlen(v->map[0]);
	if (ft_line_error(v, len, line) == 1)
	{
		v->err = 3;
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
		return (1);
	}
	v->buf = ft_strnew(1);
	while ((v->err = get_next_line(fd, &line)) > 0)
	{
		v->buf = ft_strjoin(v->buf, line);
		v->buf = ft_strjoin(v->buf, "\n");
		line_nb++;
	}
	printf("line = %d\n", line_nb);
	if (v->err == -1)
	{
		v->err = 2;
		return (1);
	}
	v->map = ft_strsplit(v->buf, '\n');
	if (ft_file_error(line_nb, v) == 1)
		return (1);
	return (0);
}
