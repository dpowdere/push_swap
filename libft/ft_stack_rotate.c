/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:50:14 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/18 14:00:51 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stack_rotate(t_stack *stack)
{
	t_dlist	*top0;
	t_dlist	*top1;

	if (!stack || !stack->bottom || stack->top == stack->bottom)
		return ;
	if (stack->top->next == stack->bottom)
		ft_stack_swap(stack);
	else
	{
		top0 = stack->top;
		top1 = stack->top->next;
		top0->prev = stack->bottom;
		top0->next = NULL;
		stack->bottom->next = stack->top;
		top1->prev = NULL;
		stack->top = top1;
		stack->bottom = top0;
	}
}

void	ft_stack_rotate_reverse(t_stack *stack)
{
	t_dlist	*bottom0;
	t_dlist	*bottom1;

	if (!stack || !stack->bottom || stack->top == stack->bottom)
		return ;
	if (stack->size == 2)
		ft_stack_swap(stack);
	else
	{
		bottom0 = stack->bottom;
		bottom1 = stack->bottom->prev;
		bottom0->next = stack->top;
		bottom0->prev = NULL;
		bottom1->next = NULL;
		stack->top->prev = bottom0;
		stack->top = bottom0;
		stack->bottom = bottom1;
	}
}
