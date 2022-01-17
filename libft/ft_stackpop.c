/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:11:00 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/17 16:18:32 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

void	*ft_stackpop(t_stack *stack)
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
