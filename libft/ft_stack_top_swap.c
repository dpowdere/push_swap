/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_top_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 21:22:11 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/17 21:31:32 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stack_top_swap(t_stack *stack)
{
	t_dlist	*second;

	if (!stack || stack->top == stack->bottom)
		return ;
	second = stack->top->next;
	stack->top->next = second->next;
	stack->top->prev = second;
	second->next = stack->top;
	second->prev = NULL;
	if (stack->bottom == second)
		stack->bottom = stack->top;
	stack->top = second;
}
