/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:55:08 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/20 16:39:45 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <libft.h>
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
	debug_str_stack(stack);

	assert(dl_nxt_size(stack->top) == 5);
	assert(dl_prv_size(stack->bottom) == 5);
	assert(dl_first(stack->bottom) == stack->top);
	assert(dl_last(stack->top) == stack->bottom);

	dl_erase(&stack->top->next->next, free);
	debug_str_stack(stack);

	dl_nxt_insert_head(&stack->top->next, dl_new(ft_new_str("x")));
	debug_str_stack(stack);

	dl_nxt_insert_tail(&stack->top->next, dl_new(ft_new_str("y")));
	debug_str_stack(stack);

	dl_prv_insert_head(&stack->top->next->next, dl_new(ft_new_str("8")));
	debug_str_stack(stack);

	dl_prv_insert_head(&stack->top->next->next, dl_new(ft_new_str("9")));
	debug_str_stack(stack);

	t_dlist *dl;
	t_dlist *dl2;

	dl = dl_new(ft_new_str("!"));
	dl_extend_head_tail(&dl, dl_new(ft_new_str("@")));
	dl2 = dl_new(ft_new_str("#"));
	dl_extend_tail_tail(&dl2, dl_last(dl));
	dl2 = dl_last(dl);
	dl = dl_first(dl);

	dl_extend_head_tail(&stack->top, dl2);
	debug_str_stack(stack);

	free(ft_stack_pop(stack));
	debug_str_stack(stack);

	free(ft_stack_pop(stack));
	debug_str_stack(stack);

	free(dl_pop(&stack->top->next));
	debug_str_stack(stack);

	ft_stack_destroy(&stack, free);
	return (EXIT_SUCCESS);
}
