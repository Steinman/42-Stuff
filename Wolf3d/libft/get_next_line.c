/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:04:20 by hcorrale          #+#    #+#             */
/*   Updated: 2016/11/02 14:04:28 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_free_one(t_slist **begin_list)
{
	t_slist	*to_free;

	to_free = *begin_list;
	*begin_list = to_free->next;
	free(to_free);
	to_free = NULL;
}

static t_slist	*ft_list_push_front(t_slist *begin_list, char c, int fd, int n)
{
	t_slist	*list;
	t_slist	*rev;

	list = (t_slist *)malloc(sizeof(t_slist));
	if (!list)
		return (NULL);
	list->fd = fd;
	list->c = c;
	if (!begin_list)
		list->next = NULL;
	else
		list->next = begin_list;
	if (n == 0)
	{
		rev = NULL;
		while (list)
		{
			rev = ft_list_push_front(rev, list->c, fd, 1);
			ft_free_one(&list);
		}
		return (rev);
	}
	return (list);
}

static t_slist	*ft_read(int fd)
{
	int		ret;
	int		n;
	char	*buf;
	t_slist	*bro_l;

	if (BUFF_SIZE > 2147483647 || BUFF_SIZE < 1)
		return (NULL);
	bro_l = NULL;
	ret = -1;
	while (ret)
	{
		if (!(buf = (char *)malloc(sizeof(char) * BUFF_SIZE)))
			return (NULL);
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (NULL);
		n = -1;
		while (++n < ret)
			bro_l = ft_list_push_front(bro_l, buf[n], fd, 1);
		free(buf);
	}
	bro_l = ft_list_push_front(bro_l, '\0', fd, 0);
	return (bro_l);
}

static int		ft_linelen(t_slist *begin_list)
{
	int		len;
	t_slist	*browse_list;

	browse_list = begin_list;
	len = 0;
	while (browse_list && browse_list->c != '\n')
	{
		len++;
		browse_list = browse_list->next;
	}
	return (len);
}

int				get_next_line(int const fd, char **line)
{
	char			*l;
	int				i;
	static	t_slist	*begin_list = NULL;

	if (begin_list && begin_list->fd == fd)
	{
		ft_free_one(&begin_list);
		if (!begin_list || !begin_list->next)
			return (0);
	}
	if (!begin_list || begin_list->fd != fd)
		if (!line || fd < 0 || !(begin_list = ft_read(fd)))
			return (-1);
	i = ft_linelen(begin_list);
	if (i < 0 || !(l = (char *)malloc(sizeof(char) * i + 1)))
		return (-1);
	i = 0;
	while (begin_list->next && begin_list->c != '\n')
	{
		l[i++] = begin_list->c;
		ft_free_one(&begin_list);
	}
	l[i] = '\0';
	*line = l;
	return (1);
}
