/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:58:02 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/18 13:58:05 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stack_swap(t_stack *stack)
{
	t_dlist	*tmp;

	if (!stack || !stack->top || stack->top == stack->bottom)
		return ;
	if (stack->top->next == stack->bottom)
	{
		stack->top->next = NULL;
		stack->top->prev = stack->bottom;
		stack->bottom->next = stack->top;
		stack->bottom->prev = NULL;
		tmp = stack->top;
		stack->top = stack->bottom;
		stack->bottom = tmp;
	}
	else
	{
		tmp = stack->top->next;
		tmp->next->prev = stack->top;
		stack->top->next = tmp->next;
		stack->top->prev = tmp;
		tmp->next = stack->top;
		tmp->prev = NULL;
		stack->top = tmp;
	}
}
