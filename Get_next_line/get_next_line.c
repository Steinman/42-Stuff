/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:53:02 by hcorrale          #+#    #+#             */
/*   Updated: 2016/01/20 16:46:14 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_free_list(t_clist **begin)
{
	t_clist		*lst;

	lst = *begin;
	*begin = lst->next;
	free(lst);
	lst = NULL;
}

static int		ft_len(t_clist *lst)
{
	t_clist		*browse;
	int			i;

	i = 0;
	browse = lst;
	while (browse || browse->c != c)
	{
		browse = browse->next;
		i++;
	}
	return (i);
}

static t_clist	*ft_pushlst(t_clist *begin, char c, int fd, int n)
{
	t_clist		list;
	t_clist		rev;

	list = (t_clist *)malloc(sizeof(t_clist));
	if (!list)
		return (NULL);
	list->fd = fd;
	list->c = c;
	if (!begin)
		list->next = NULL;
	else
		list->next = begin;
	if (n == 0)
	{
		rev = NULL;
		while (list)
		{
			rev = ft_free_list(rev, list->c, fd, 1);
			free(&list);
		}
		return (rev);
	}
	return (list);
}

static t_clist	*ft_read(int fd);
