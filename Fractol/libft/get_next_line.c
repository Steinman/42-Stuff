/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:53:02 by hcorrale          #+#    #+#             */
/*   Updated: 2016/03/07 16:44:15 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_read(char **stock, int fd)
{
	char		buff[BUFF_SIZE + 1];
	int			bytes;
	char		*str;

	if ((bytes = read(fd, buff, BUFF_SIZE)) == -1)
		return (-1);
	buff[bytes] = '\0';
	str = *stock;
	*stock = ft_strjoin(*stock, buff);
	if (*str != 0)
		free(str);
	return (bytes);
}

static int		ft_get_line(char **stock, char **line, char *str)
{
	int			n;
	char		*join;

	n = 0;
	if (*str == '\n')
		n = 1;
	*str = 0;
	*line = ft_strjoin("", *stock);
	if (n == 0 && ft_strlen(*stock) != 0)
	{
		*stock = ft_strnew(1);
		return (1);
	}
	else if (n == 0 && !ft_strlen(*stock))
		return (0);
	join = *stock;
	*stock = ft_strjoin(str + 1, "");
	free(join);
	return (n);
}

int				get_next_line(int const fd, char **line)
{
	static char	*stock;
	char		*str;
	int			ret;

	if (stock == 0)
		stock = "";
	if (!line || BUFF_SIZE < 1 || BUFF_SIZE > 147483647)
		return (-1);
	ret = BUFF_SIZE;
	while (line)
	{
		str = stock;
		while (*str || ret < BUFF_SIZE)
		{
			if (*str == '\n' || *str == 0 || *str == -1)
				return (ft_get_line(&stock, line, str));
			str++;
		}
		ret = ft_read(&stock, fd);
		if (ret == -1)
			return (-1);
	}
	return (0);
}
