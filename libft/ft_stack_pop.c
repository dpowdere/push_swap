/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:44:27 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/17 20:45:26 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

void	*ft_stack_pop(t_stack *stack)
{
	void	*data;

	if (!stack)
		return NULL;
	data = dl_pop(&stack->top);
	if (!stack->top)
		stack->bottom = NULL;
	--stack->size;
	return data;
}
