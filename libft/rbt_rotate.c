/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:46:59 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/20 18:07:32 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

t_rbtree	*rbt_left_rotate(t_rbtree *x)
{
	t_rbtree	*y;
	t_rbtree	*subtree_root;

	if (x->right == NULL)
		return (x);
	y = x->right;
	x->right = y->left;
	if (y->left != NULL)
		y->left->parent = x;
	y->parent = x->parent;
	if (x->parent == NULL)
		subtree_root = y;
	else
	{
		if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}

t_rbtree	*rbt_right_rotate(t_rbtree *x)
{
	return (x);
}
