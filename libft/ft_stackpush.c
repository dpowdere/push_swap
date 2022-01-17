/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:42:45 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/17 16:25:13 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackpush(t_stack *stack, void *data)
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
