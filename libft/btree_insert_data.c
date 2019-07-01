/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 15:09:13 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/11/04 15:09:14 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_insert_data(t_btree *root,
	void *item, int (*cmpf)(void *, void *))
{
	if (!root)
	{
		root = btree_create_node(item);
		return ;
	}
	if (cmpf(item, root->item) < 0)
	{
		if (!root->left)
			root->left = btree_create_node(item);
		else
			btree_insert_data(root->left, item, cmpf);
	}
	else
	{
		if (!root->right)
			root->right = btree_create_node(item);
		else
			btree_insert_data(root->right, item, cmpf);
	}
}
