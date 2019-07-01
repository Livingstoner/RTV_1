/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 15:04:23 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/11/04 15:04:24 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*btree_create_node(void *item)
{
	t_btree *tree;

	tree = malloc(sizeof(tree));
	if (tree)
	{
		tree->left = NULL;
		tree->right = NULL;
		tree->item = item;
	}
	return (tree);
}
