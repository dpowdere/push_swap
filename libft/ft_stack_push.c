/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:44:27 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/17 20:44:38 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stack_push(t_stack *stack, void *data)
{
	t_dlist	*new;

	if (!stack || !data)
		return ;
	new = dl_new(data);
	if (!new)
		return ;
	dl_add_front(&stack->top, new);
	if (!stack->bottom)
		stack->bottom = stack->top;
	++stack->size;
}
