/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 13:54:40 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/23 14:36:24 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*tmp;

	tmp = ft_create_elem(data);
	if (tmp)
	{
		tmp->next = begin_list[0]->next;
		begin_list[0]->next = tmp;
	}
}

t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*begin_list;

	i = 0;
	if (ac == 0)
		return (NULL);
	while (i < ac)
	{
		ft_list_push_front(&begin_list, av[i]);
		i++;
	}
	return (begin_list);
}
