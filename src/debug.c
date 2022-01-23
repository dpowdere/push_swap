#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <libftdbg.h>

static void	print(void *x)
{
	printf("%d ", *(int *)x);
}

void debug(void)
{
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

	rbt_clear(&tree, free);
}
