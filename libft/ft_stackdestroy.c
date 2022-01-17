/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackdestroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:36:46 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/17 16:22:49 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "libft.h"

void	ft_stackdestroy(t_stack **stack, void (*f)(void *))
{
	if (!stack || !*stack || !f)
		return ;
	ft_stackclear(*stack, f);
	free(*stack);
	*stack = NULL;
}
