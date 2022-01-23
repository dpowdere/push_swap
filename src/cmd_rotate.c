/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:46:06 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/23 21:46:30 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "push_swap.h"

void	cmd_rotate_a(t_stack *a, t_stack *b)
{
	ft_stack_rotate(a);
	(void)b;
}

void	cmd_rotate_b(t_stack *a, t_stack *b)
{
	(void)a;
	ft_stack_rotate(b);
}

void	cmd_rotate_both(t_stack *a, t_stack *b)
{
	ft_stack_rotate(a);
	ft_stack_rotate(b);
}
