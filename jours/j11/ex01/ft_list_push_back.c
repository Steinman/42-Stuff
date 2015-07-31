/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 18:42:01 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/22 23:43:45 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*tmp;
	int		i;

	i = 0;
	while (begin_list[i])
		i++;
	tmp = ft_create_elem(data);
	if (tmp)
		begin_list[i]->next = tmp;
}
