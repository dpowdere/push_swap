/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_top_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:55:08 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/17 22:22:41 by dpowdere         ###   ########.fr       */
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

	cursor = stack->top;
	printf("stack: ");
	while (cursor)
	{
		printf("%d ", *(int *)cursor->content);
		cursor = cursor->next;
	}
	printf("\n");
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
	ft_stack_push(stack, new_int(10));
	ft_stack_push(stack, new_int(2));
	ft_stack_push(stack, new_int(33));
	ft_stack_push(stack, new_int(-345));
	print_stack(stack);

	ft_stack_top_swap(stack);
	print_stack(stack);

	int	*p;

	p = ft_stack_pop(stack);
	free(p);
	print_stack(stack);

	ft_stack_top_swap(stack);
	print_stack(stack);

	p = ft_stack_pop(stack);
	free(p);
	print_stack(stack);

	ft_stack_top_swap(stack);
	print_stack(stack);

	p = ft_stack_pop(stack);
	free(p);
	print_stack(stack);

	ft_stack_top_swap(stack);
	print_stack(stack);

	p = ft_stack_pop(stack);
	free(p);
	print_stack(stack);

	ft_stack_destroy(&stack, free);
	return (EXIT_SUCCESS);
}
