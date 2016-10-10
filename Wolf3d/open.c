/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:23:15 by hcorrale          #+#    #+#             */
/*   Updated: 2016/10/10 13:31:53 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	ft_char_error(char *buf)
{
	int		i;

	i = 0;
	if (buf[0] == '\0' || buf[0] == '\n')
		return (1);
	while (buf[i] != '\0')
		i++;
	buf[i - 1] = '\0';
	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] != '0' && buf[i] != '1' && buf[i] != 'X' && buf[i] != '\n')
			return (1);
		if (buf[i] == '\n' && (buf[i + 1] == '\n' || buf[i + 1] == '\0'))
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


static int	ft_file_error(int line, char *buf, t_var *v)
{
	size_t	len;

	if (ft_char_error(buf) == 1)
	{
		v->err = 4;
		free(buf);
		return (1);
	}
	free(buf);
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
	char	*buf;

	v->line_nb = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		v->err = 1;
		return (1);
	}
	buf = ft_strnew(1);
	while ((v->err = get_next_line(fd, &line)) > 0)
	{
		buf = ft_strjoin(buf, line);
		buf = ft_strjoin(buf, "\n");
		v->line_nb++;
	}
	free(line);
	if (v->err == -1)
	{
		v->err = 2;
		return (1);
	}
	v->map = ft_strsplit(buf, '\n');
	if (ft_file_error(v->line_nb, buf, v) == 1)
		return (1);
	return (0);
}
