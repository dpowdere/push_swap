/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:52:01 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/17 21:17:39 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

void	ft_stack_reverse_rotate(t_stack *stack)
{
	t_dlist	*frame;

	if (!stack || !stack->bottom || stack->top == stack->bottom)
		return ;
	stack->bottom->next = stack->top;
	stack->bottom->prev = NULL;
	stack->top->prev = stack->bottom;
	if (stack->top->next == stack->bottom)
		stack->top->next = NULL;
	frame = stack->bottom;
	stack->bottom = stack->bottom->prev;
	stack->top = frame;
}
