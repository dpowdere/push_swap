/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:50:14 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/17 21:16:07 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stack_rotate(t_stack *stack)
{
	t_dlist	*frame;

	if (!stack || !stack->bottom || stack->top == stack->bottom)
		return ;
	stack->top->prev = stack->bottom;
	stack->top->next = NULL;
	stack->bottom->next = stack->top;
	if (stack->bottom->prev == stack->top)
		stack->bottom->prev = NULL;
	frame = stack->top;
	stack->top = stack->top->next;
	stack->bottom = frame;
}
