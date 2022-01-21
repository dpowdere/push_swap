/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:55:08 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/21 21:10:53 by dpowdere         ###   ########.fr       */
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

	t_stack	*stack;

	stack = ft_stack_new();
	ft_stack_push(stack, ft_new_str("A"));
	ft_stack_push(stack, ft_new_str("B"));
	ft_stack_push(stack, ft_new_str("C"));
	ft_stack_push(stack, ft_new_str("D"));
	ft_stack_push(stack, ft_new_str("E"));
	ft_stack_strDebug(stack);

	assert(dl_nxt_size(stack->top) == 5);
	assert(dl_prv_size(stack->bottom) == 5);
	assert(dl_first(stack->bottom) == stack->top);
	assert(dl_last(stack->top) == stack->bottom);

	dl_erase(&stack->top->next->next, free);
	ft_stack_strDebug(stack);

	dl_nxt_insert_head(&stack->top->next, dl_new(ft_new_str("x")));
	ft_stack_strDebug(stack);

	dl_nxt_insert_tail(&stack->top->next, dl_new(ft_new_str("y")));
	ft_stack_strDebug(stack);

	dl_prv_insert_head(&stack->top->next->next, dl_new(ft_new_str("8")));
	ft_stack_strDebug(stack);

	dl_prv_insert_head(&stack->top->next->next, dl_new(ft_new_str("9")));
	ft_stack_strDebug(stack);

	t_dlist *dl;
	t_dlist *dl2;

	dl = dl_new(ft_new_str("!"));
	dl_extend_head_tail(&dl, dl_new(ft_new_str("@")));
	dl2 = dl_new(ft_new_str("#"));
	dl_extend_tail_tail(&dl2, dl_last(dl));
	dl2 = dl_last(dl);
	dl = dl_first(dl);

	dl_extend_head_tail(&stack->top, dl2);
	ft_stack_strDebug(stack);

	free(ft_stack_pop(stack));
	ft_stack_strDebug(stack);

	free(ft_stack_pop(stack));
	ft_stack_strDebug(stack);

	free(dl_pop(&stack->top->next));
	ft_stack_strDebug(stack);

	ft_stack_destroy(&stack, free);
	return (EXIT_SUCCESS);
}
