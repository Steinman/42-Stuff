/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 13:53:18 by hcorrale          #+#    #+#             */
/*   Updated: 2016/06/06 16:35:34 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_lineerror(char **str, t_var *v)
{
	int		*t;
	int		i;

	i = 0;
	t = (int *)malloc(sizeof(int) * v->l);
	while (i < v->l)
	{
		t[i] = ft_intnb(str[i]);
		if (t[i] != t[0])
		{
			free(t);
			return (-1);
		}
		i++;
	}
	free(t);
	return (0);
}

int			ft_emptyline(char *str)
{
	int		i;

	i = 0;
	if (str[0] == '\n' || str[0] == '\0')
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			if (str[i + 1] == '\n' || str[i - 1] == '\0')
				return (-1);
		}
		i++;
	}
	return (0);
}

t_var		*ft_fd_error(t_var *v, int fd, char *file)
{
	char	*line;

	v->l = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		v->err = -1;
		ft_putstr("ERROR: invalid file !\n");
		return (v);
	}
	v->buf = ft_strnew(1);
	while ((v->err = get_next_line(fd, &line)) > 0)
	{
		v->buf = ft_strjoin(v->buf, line);
		v->buf = ft_strjoin(v->buf, "\n");
		v->l++;
	}
	if (v->err == -1)
	{
		ft_putstr("ERROR: file error\n");
		return (v);
	}
	return (v);
}
