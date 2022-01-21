/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:55:08 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/21 22:53:44 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <libftdbg.h>

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	// - split args into array of integers
	// - check for duplicates with self-balancing trees?
	// - create stacks
	// - populate stack a

	t_rbtree	*tree;
	tree = rbt_new(ft_new_int(17));
	rbt_insert(&tree, ft_intcmp, ft_new_int(5));
	rbt_insert(&tree, ft_intcmp, ft_new_int(2));
	rbt_insert(&tree, ft_intcmp, ft_new_int(7));
	rbt_insert(&tree, ft_intcmp, ft_new_int(3));
	rbt_insert(&tree, ft_intcmp, ft_new_int(20));
	rbt_insert(&tree, ft_intcmp, ft_new_int(17));
	rbt_intDebug(tree);
	return (EXIT_SUCCESS);
}
