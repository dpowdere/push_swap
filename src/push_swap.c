/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:55:08 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/18 18:03:50 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	debug_str_stack(stack);

	ft_stack_push(stack, ft_new_str("A"));
	debug_str_stack(stack);

	ft_stack_push(stack, ft_new_str("B"));
	debug_str_stack(stack);

	ft_stack_push(stack, ft_new_str("C"));
	debug_str_stack(stack);

	ft_stack_push(stack, ft_new_str("D"));
	debug_str_stack(stack);

	ft_stack_push(stack, ft_new_str("E"));
	debug_str_stack(stack);

	dl_erase(&stack->top->next->next, free);
	debug_str_stack(stack);

	dl_nxt_insert_head(&stack->top->next, dl_new(ft_new_str("x")));
	debug_str_stack(stack);

	dl_nxt_insert_tail(&stack->top->next, dl_new(ft_new_str("y")));
	debug_str_stack(stack);

	dl_prv_insert_head(&stack->top->next->next, dl_new(ft_new_str("n")));
	debug_str_stack(stack);

/*
	dl_prv_insert_head(&stack->top->next->next, dl_new(ft_new_str("m")));
	debug_str_stack(stack);
*/
	ft_stack_destroy(&stack, free);
	return (EXIT_SUCCESS);
}
