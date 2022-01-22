/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:55:08 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/22 13:26:58 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include <libftdbg.h>

#include "push_swap.h"

void	print(void *x)
{
	printf("%d ", *(int *)x);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	// - split args into array of integers
	// - check for duplicates with self-balancing trees?
	// - create stacks
	// - populate stack a

	t_rbtree	*tree;
	t_rbtree	*tmp;

	tree = rbt_new(ft_new_int(17));
	rbt_insert(&tree, ft_intcmp, ft_new_int(5));
	rbt_insert(&tree, ft_intcmp, ft_new_int(2));
	rbt_insert(&tree, ft_intcmp, ft_new_int(7));
	rbt_intDebug(tree);

	rbt_right_rotate(&tree, tree);
	rbt_intDebug(tree);

	rbt_left_rotate(&tree, tree);
	rbt_intDebug(tree);

	rbt_insert(&tree, ft_intcmp, ft_new_int(3));
	rbt_insert(&tree, ft_intcmp, ft_new_int(20));
	rbt_insert(&tree, ft_intcmp, ft_new_int(17));
	rbt_intDebug(tree);

	tmp = rbt_prev(tree);
	assert(tmp && *(int *)tmp->key == 7);
	tmp = rbt_prev(tmp);
	assert(tmp && *(int *)tmp->key == 5);
	tmp = rbt_prev(tmp);
	assert(tmp && *(int *)tmp->key == 3);

	rbt_right_rotate(&tree, tree);
	rbt_intDebug(tree);

	printf("in order: ");
	rbt_iter_in_order(tree, print);
	printf("\n");

	printf("pre order: ");
	rbt_iter_pre_order(tree, print);
	printf("\n");

	printf("post order: ");
	rbt_iter_post_order(tree, print);
	printf("\n");

	printf("level order: ");
	rbt_iter_level_order(tree, print);
	printf("\n");

	tmp = rbt_next(tree);
	assert(tmp && *(int *)tmp->key == 7);
	tmp = rbt_next(tmp);
	assert(tmp && *(int *)tmp->key == 17);
	tmp = rbt_next(tmp);
	assert(tmp && *(int *)tmp->key == 17);
	tmp = rbt_next(tmp);
	assert(tmp && *(int *)tmp->key == 20);

	rbt_erase(&tree, free, tree->right);
	rbt_intDebug(tree);

	rbt_erase(&tree, free, tree->left);
	rbt_intDebug(tree);

	rbt_erase(&tree, free, tree->right);
	rbt_intDebug(tree);

	rbt_erase(&tree, free, tree);
	rbt_intDebug(tree);

	rbt_destroy(&tree, free);

	return (EXIT_SUCCESS);
}
