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

void	rbt_delete(t_rbtree **root, void (*delete)(void *), t_rbtree *z)
{
	t_rbtree	*x;
	t_rbtree	*y;
	void		*tmp;

	if (!root || !*root || !z || !delete)
		return ;
	if (!z->left || !z->right)
		y = z;
	else
		y = rbt_next(z);
	if (y->left)
		x = y->left;
	else
		x = y->right;
	if (x)
		x->parent = y->parent;
	if (!y->parent)
		*root = x;
	else if (y == y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;
	if (y != z)
	{
		tmp = z->key;
		z->key = y->key;
		y->key = tmp;
	}
	delete(y->key);
	free(y);
}
