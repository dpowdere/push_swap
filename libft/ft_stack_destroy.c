/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:44:27 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/17 20:46:02 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "libft.h"

void	ft_stack_destroy(t_stack **stack, void (*f)(void *))
{
	if (!stack || !*stack || !f)
		return ;
	ft_stack_clear(*stack, f);
	free(*stack);
	*stack = NULL;
}
