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
