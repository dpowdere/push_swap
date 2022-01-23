/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:47:18 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/23 21:48:49 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "push_swap.h"

void	cmd_reverse_rotate_a(t_stack *a, t_stack *b)
{
	ft_stack_rotate_reverse(a);
	(void)b;
}

void	cmd_reverse_rotate_b(t_stack *a, t_stack *b)
{
	(void)a;
	ft_stack_rotate_reverse(b);
}

void	cmd_reverse_rotate_both(t_stack *a, t_stack *b)
{
	ft_stack_rotate_reverse(a);
	ft_stack_rotate_reverse(b);
}
