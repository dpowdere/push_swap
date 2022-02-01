/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planner_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:50:19 by dpowdere          #+#    #+#             */
/*   Updated: 2022/02/01 16:50:30 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline int	search_backward(t_dlist *elem, t_stack *stack)
{
	int		ix;
	t_dlist	*prev;
	t_dlist	*curr;

	prev = stack->top;
	curr = stack->bottom;
	ix = stack->size;
	while (curr && *(int *)curr->content < *(int *)prev->content
		&& *(int *)elem->content < *(int *)curr->content)
	{
		--ix;
		prev = curr;
		curr = curr->prev;
	}
	return (ix);
}

static inline int	search_forward(t_dlist *elem, t_stack *stack)
{
	int		ix;
	t_dlist	*prev;
	t_dlist	*curr;

	prev = stack->top;
	curr = stack->top->next;
	ix = 1;
	while (curr && *(int *)curr->content > *(int *)prev->content
		&& *(int *)elem->content > *(int *)curr->content)
	{
		++ix;
		prev = curr;
		curr = curr->next;
	}
	return (ix);
}

int	find_sorted_position_in_rotated_sorted_stack(t_dlist *elem, t_stack *stack)
{
	t_dlist	*prev;

	prev = stack->top;
	if (*(int *)elem->content < *(int *)prev->content)
		return (search_backward(elem, stack));
	else
		return (search_forward(elem, stack));
}

void	final_rotation(t_config *c)
{
	int		i;
	int		ix;
	t_op	cmd;
	t_dlist	*dl;

	i = 0;
	ix = 0;
	dl = c->a->top;
	while (dl && dl->next)
	{
		++i;
		if (*(int *)dl->content > *(int *)dl->next->content)
		{
			ix = i;
			break ;
		}
		dl = dl->next;
	}
	cmd = PSCMD_RA;
	if (c->a->size - ix < ix)
	{
		cmd = PSCMD_RRA;
		ix = c->a->size - ix;
	}
	resolve_cmd_sequence(c, cmd, ix);
}
