/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 10:01:11 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/22 10:01:13 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rbt_iter_in_order(t_rbtree *root, void (*f)(void *))
{
	if (!root || !f)
		return ;
	rbt_iter_in_order(root->left, f);
	f(root->key);
	rbt_iter_in_order(root->right, f);
}

void	rbt_iter_pre_order(t_rbtree *root, void (*f)(void *))
{
	if (!root || !f)
		return ;
	f(root->key);
	rbt_iter_pre_order(root->left, f);
	rbt_iter_pre_order(root->right, f);
}

void	rbt_iter_post_order(t_rbtree *root, void (*f)(void *))
{
	if (!root || !f)
		return ;
	rbt_iter_post_order(root->left, f);
	rbt_iter_post_order(root->right, f);
	f(root->key);
}

void	rbt_iter_level_order(t_rbtree *root, void (*f)(void *))
{
	t_queue		queue;
	t_rbtree	*node;

	if (!root || !f)
		return ;
	ft_q_init(&queue);
	ft_q_en(&queue, root);
	while (queue.size)
	{
		node = ft_q_de(&queue);
		f(node->key);
		if (node->left)
			ft_q_en(&queue, node->left);
		if (node->right)
			ft_q_en(&queue, node->right);
	}
}
