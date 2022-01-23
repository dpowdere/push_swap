/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:36:01 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/23 21:40:02 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "push_swap.h"

void	cmd_push_a(t_stack *a, t_stack *b)
{
	void	*data;

	data = ft_stack_pop(b);
	if (data)
		ft_stack_push(a, data);
}

void	cmd_push_b(t_stack *a, t_stack *b)
{
	void	*data;

	data = ft_stack_pop(a);
	if (data)
		ft_stack_push(b, data);
}
