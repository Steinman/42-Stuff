/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:33:36 by hcorrale          #+#    #+#             */
/*   Updated: 2015/12/22 12:02:31 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*lnext;

	list = *alst;
	while (list)
	{
		lnext = list->next;
		del((list->content), list->content_size);
		free(list);
		list = lnext;
	}
	*alst = NULL;
}
