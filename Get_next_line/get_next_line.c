/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:53:02 by hcorrale          #+#    #+#             */
/*   Updated: 2016/02/17 14:36:56 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static int		ft_read(int const fd, char **stock)
{
	char		buff[BUFF_SIZE + 1];
	int			bytes;
	char		*str;

	if (BUFF_SIZE > 147483647 || BUFF_SIZE < 1)
		return (-1);
	if (bytes = read(fd, buff, BUFF_SIZE) == -1)
		return (-1);
	buff[bytes] = '\0';
	str = *stock;
	*stock = ft_strjoin(*stock, buff);
	if (*str != 0)
		free (str);
	return (bytes);
}

static int		ft_get_line(char **stock, char **line, char *str)
{
	int			n;
	char		*join;

	i = 0;
	if (*str == '\n')
		i = 1;
	*str = 0;
	*line = ft_strjoin("", *stock);
	
}

int				get_next_line(int const fd, char **line)
{
	static char	*stock = NULL;
	char		*index;
	int			ret;

	if (!stock && (stock = (char *)ft_memalloc(sizeof(char))) == NULL)
		return (-1);
	index = ft_strchr(stock, '\n');
	while (index == NULL)
	{
		ret = ft_read(fd, &stock);
		if (ret == 0)
		{
			if ((index = ft_strchr(stock, '\0')) == stock)
				return (0);
		}
		else if (ret < 0)
			return (-1);
		else
			index = ft_strchr(stock, '\n');
	}
	*line = ft_strsub(stock, 0, index - stock);
	if (!*line)
		return (-1);
	index = ft_strdup(index + 1);
	free(stock);
	stock = index;
	return (1);
}
