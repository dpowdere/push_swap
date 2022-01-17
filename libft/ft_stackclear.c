/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:29:11 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/17 16:26:46 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackclear(t_stack *stack, void (*f)(void *))
{
	if (!stack || !f)
		return ;
	dl_clear(&stack->top, f);
	stack->bottom = NULL;
	stack->size = 0;
}
