/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 13:41:17 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/25 14:17:26 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree		*btree_create_node(void *item)
{
	t_btree *btree;

	btree = (t_btree*)malloc(sizeof(t_btree));
	if (btree)
	{
		btree->left = 0;
		btree->right = 0;
		btree->item = item;
	}
	return (btree);
}
