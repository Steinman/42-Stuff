/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:53:02 by hcorrale          #+#    #+#             */
/*   Updated: 2016/01/19 17:40:56 by hcorrale         ###   ########.fr       */
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

static t_clist	*ft_read(int fd);
