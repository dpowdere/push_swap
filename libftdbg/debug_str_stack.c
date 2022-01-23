/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_str_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:00:22 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/21 21:12:24 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "libftdbg.h"

static inline void	debug_str_stack_header(t_stack *stack)
{
	ft_eprint(AEC_BOLD "STACK" AEC_RESET ": top=");
	if (stack->top)
		ft_eprint((char *)stack->top->content);
	else
		ft_eprint("x");
	ft_eprint(", bottom=");
	if (stack->bottom)
		ft_eprint((char *)stack->bottom->content);
	else
		ft_eprint("x");
	ft_eprint(", size=");
	ft_putnbr_fd(stack->size, STDERR_FILENO);
	ft_eprint("\n");
}

void	ft_stack_strDebug(t_stack *stack)
{
	t_dlist	*cursor;

	debug_str_stack_header(stack);
	ft_eprint("top-to-bottom:" AEC_YELLOW);
	cursor = stack->top;
	while (cursor)
	{
		ft_eprint(" ");
		ft_eprint((char *)cursor->content);
		cursor = cursor->next;
	}
	ft_eprint(AEC_RESET "\nbottom-to-top:" AEC_YELLOW);
	cursor = stack->bottom;
	while (cursor)
	{
		ft_eprint(" ");
		ft_eprint((char *)cursor->content);
		cursor = cursor->prev;
	}
	ft_eprint(AEC_RESET "\n");
}

static inline void	debug_int_stack_header(t_stack *stack)
{
	ft_eprint(AEC_BOLD "STACK" AEC_RESET ": top=");
	if (stack->top)
		ft_putnbr_fd(*(int *)stack->top->content, STDERR_FILENO);
	else
		ft_eprint("x");
	ft_eprint(", bottom=");
	if (stack->bottom)
		ft_putnbr_fd(*(int *)stack->bottom->content, STDERR_FILENO);
	else
		ft_eprint("x");
	ft_eprint(", size=");
	ft_putnbr_fd(stack->size, STDERR_FILENO);
	ft_eprint("\n");
}

void	ft_stack_intDebug(t_stack *stack)
{
	t_dlist	*cursor;

	debug_int_stack_header(stack);
	ft_eprint("top-to-bottom:" AEC_YELLOW);
	cursor = stack->top;
	while (cursor)
	{
		ft_eprint(" ");
		ft_putnbr_fd(*(int *)cursor->content, STDERR_FILENO);
		cursor = cursor->next;
	}
	ft_eprint(AEC_RESET "\nbottom-to-top:" AEC_YELLOW);
	cursor = stack->bottom;
	while (cursor)
	{
		ft_eprint(" ");
		ft_putnbr_fd(*(int *)cursor->content, STDERR_FILENO);
		cursor = cursor->prev;
	}
	ft_eprint(AEC_RESET "\n");
}
