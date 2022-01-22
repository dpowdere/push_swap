/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 22:18:28 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/21 22:26:16 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rbtree	*rbt_find(t_rbtree *root, int (*cmp)(void *, void *), void *key)
{
	t_rbtree	*cursor;
	int			order;

	cursor = root;
	while (cursor)
	{
		order = cmp(key, cursor->key);
		if (order < 0)
			cursor = cursor->left;
		else if (order > 0)
			cursor = cursor->right;
		else
			break ;
	}
	return (cursor);
}

t_rbtree	*rbt_max(t_rbtree *node)
{
	while (node && node->right)
		node = node->right;
	return (node);
}

t_rbtree	*rbt_min(t_rbtree *node)
{
	while (node && node->left)
		node = node->left;
	return (node);
}

t_rbtree	*rbt_next(t_rbtree *x)
{
	t_rbtree	*y;

	if (x->right)
		return (rbt_min(x->right));
	y = x->parent;
	while (y && x == y->right)
	{
		x = y;
		y = y->parent;
	}
	return (y);
}

t_rbtree	*rbt_prev(t_rbtree *x)
{
	t_rbtree	*y;

	if (x->left)
		return (rbt_max(x->left));
	y = x->parent;
	while (y && x == y->left)
	{
		x = y;
		y = y->parent;
	}
	return (y);
}
