/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:40:27 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/23 21:43:08 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "push_swap.h"

void	cmd_swap_a(t_stack *a, t_stack *b)
{
	ft_stack_swap(a);
	(void)b;
}

void	cmd_swap_b(t_stack *a, t_stack *b)
{
	(void)a;
	ft_stack_swap(b);
}

void	cmd_swap_both(t_stack *a, t_stack *b)
{
	ft_stack_swap(a);
	ft_stack_swap(b);
}
