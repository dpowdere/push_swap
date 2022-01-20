/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:29:36 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/20 17:38:50 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "libft.h"

t_rbtree	*rbt_new(void *key)
{
	t_rbtree	*rbt;

	rbt = (t_rbtree *)malloc(sizeof(t_rbtree));
	if (!rbt)
		return (NULL);
	rbt->key = key;
	rbt->color = RBTREE_BLACK;
	rbt->left = NULL;
	rbt->right = NULL;
	rbt->parent = NULL;
	return (rbt);
}
