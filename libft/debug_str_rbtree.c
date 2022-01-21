/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_str_rbtree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:38:39 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/21 20:15:18 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_right_branch_height(t_rbtree *x)
{
	int	height;

	height = 0;
	while (x->right)
	{
		++height;
		x = x->right;
	}
	return (height);
}

static int	_left_branch_height(t_rbtree *x)
{
	int	height;

	height = 0;
	while (x->left)
	{
		++height;
		x = x->left;
	}
	return (height);
}

static void	_rbt_debug(t_rbtree *root, int line_end)
{
	int	lh;
	int	rh;

	lh = _left_branch_height(root);
	rh = _right_branch_height(root);
	while (lh--)
		ft_eprint(" ");
	ft_eprint((char *)root->key);
	while (rh--)
		ft_eprint(" ");
	if (root->right)
}

void	rbt_debug(t_rbtree *root)
{
	int	left_height;
	int	right_height;

	left_height = _left_branch_height(root);
	right_height = _right_branch_height(root);
	while (left_height--)
		ft_eprint(" ");
	ft_eprint((char *)root->key);
	while (right_height--)
		ft_eprint(" ");
}
