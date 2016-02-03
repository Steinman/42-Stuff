/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:53:02 by hcorrale          #+#    #+#             */
/*   Updated: 2016/02/03 16:11:19 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static int		ft_read(int const fd, char **stock)
{
	static char	buff[BUFF_SIZE + 1] = { '\n' };
	int			bytes;
	char		*str;

	if (BUFF_SIZE > 147483647 || BUFF_SIZE < 1)
		return (-1);
	bytes = read(fd, buff, BUFF_SIZE);
	if (bytes > 0)
	{
		buff[bytes] = '\0';
		str = ft_strjoin(*stock, buff);
		if (!str)
			return (-1);
		free(*stock);
		*stock = str;
	}
	return (bytes);
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
