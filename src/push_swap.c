/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:55:08 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/18 15:55:17 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include <libft.h>
#include "push_swap.h"

int	*new_int(int n)
{
	int	*p;

	p = (int *)malloc(sizeof(int));
	if (!p)
		return NULL;
	*p = n;
	return p;
}

void	print_stack(t_stack *stack)
{
	t_dlist	*cursor;

	printf(AEC_BOLD "STACK" AEC_RESET ": top=");
	if (stack->top)
		printf("%d, bottom=", *(int *)stack->top->content);
	else
		printf("x, bottom=");
	if (stack->bottom)
		printf("%d, size=%d\n", *(int *)stack->bottom->content, stack->size);
	else
		printf("x, size=%d\n", stack->size);

	printf("top-to-bottom[ " AEC_YELLOW);
	cursor = stack->top;
	while (cursor)
	{
		printf("%d ", *(int *)cursor->content);
		cursor = cursor->next;
	}

	printf(AEC_RESET "], bottom-to-top[ " AEC_YELLOW);
	cursor = stack->bottom;
	while (cursor)
	{
		printf("%d ", *(int *)cursor->content);
		cursor = cursor->prev;
	}
	printf(AEC_RESET "]\n");
}

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
	ft_stack_push(stack, new_int(-2));
	ft_stack_push(stack, new_int(-1));
	ft_stack_push(stack, new_int(0));
	ft_stack_push(stack, new_int(1));
	ft_stack_push(stack, new_int(2));
	print_stack(stack);

	dl_erase(&stack->top->next->next, free);
	print_stack(stack);

	dl_nxt_insert_head(&stack->top->next, dl_new(new_int(77)));
	print_stack(stack);

	dl_nxt_insert_head(&stack->top->next, dl_new(new_int(7)));
	print_stack(stack);

	dl_prv_insert_head(&stack->top->next->next, dl_new(new_int(5)));
	print_stack(stack);

	dl_prv_insert_head(&stack->top->next->next, dl_new(new_int(55)));
	print_stack(stack);

	ft_stack_destroy(&stack, free);
	return (EXIT_SUCCESS);
}
