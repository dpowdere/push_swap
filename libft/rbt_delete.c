/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:46:09 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/22 13:46:23 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

static void	_swap_keys(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	rbt_delete(t_rbtree **root, void (*delete)(void *), t_rbtree *z)
{
	t_rbtree	*x;
	t_rbtree	*y;

	if (!root || !*root || !z || !delete)
		return ;
	y = z;
	if (z->left && z->right)
		y = rbt_next(z);
	x = y->right;
	if (y->left)
		x = y->left;
	if (x)
		x->parent = y->parent;
	if (!y->parent)
		*root = x;
	else if (y == y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;
	if (y != z)
		_swap_keys(&z->key, &y->key);
	delete(y->key);
	free(y);
}
