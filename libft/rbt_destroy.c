/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:46:16 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/22 15:22:52 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "libft.h"

void	rbt_destroy(t_rbtree **root, void (*key_free)(void *))
{
	t_rbtree	*cursor;
	t_rbtree	*tmp;

	if (!root || !*root || !key_free)
		return ;
	cursor = *root;
	while (cursor)
	{
		if (cursor->left)
			cursor = cursor->left;
		else if (cursor->right)
			cursor = cursor->right;
		else
		{
			if (cursor->parent && cursor == cursor->parent->left)
				cursor->parent->left = NULL;
			else if (cursor->parent && cursor == cursor->parent->right)
				cursor->parent->right = NULL;
			key_free(cursor->key);
			tmp = cursor;
			cursor = cursor->parent;
			free(tmp);
		}
	}
	*root = NULL;
}
