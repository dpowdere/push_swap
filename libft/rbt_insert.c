/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 22:09:00 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/23 14:58:20 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_rbt_insert(t_rbtree *cursor, t_rbtree *new,
						int (*cmp)(void *, void *))
{
	int	order;

	while (cursor)
	{
		order = cmp(new->key, cursor->key);
		if ((order < 0 && !cursor->left) || (order >= 0 && !cursor->right))
			break ;
		else if (order < 0)
			cursor = cursor->left;
		else
			cursor = cursor->right;
	}
	if (order < 0)
		cursor->left = new;
	else
		cursor->right = new;
	new->parent = cursor;
}

void	rbt_insert(t_rbtree **root, int (*cmp)(void *, void *), void *key)
{
	t_rbtree	*new;

	if (!root || !cmp || !key)
		return ;
	new = rbt_new(key);
	if (!new)
		return ;
	if (!*root)
		*root = new;
	else
		_rbt_insert(*root, new, cmp);
}
