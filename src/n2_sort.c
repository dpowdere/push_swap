/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n2_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:18:54 by dpowdere          #+#    #+#             */
/*   Updated: 2022/02/01 16:18:57 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_triplet(t_config *c)
{
	t_stack *const	stack = c->a;
	int const		x = *(int *)stack->top->content;
	int const		y = *(int *)stack->top->next->content;
	int const		z = *(int *)stack->bottom->content;

	if ((x > y && y > z) || (x > y && y < z && x < z)
		|| (x < y && y > z && x < z))
		resolve_cmd(c, PSCMD_SA);
	if (*(int *)stack->top->content > *(int *)stack->top->next->content)
		resolve_cmd(c, PSCMD_RA);
	if (*(int *)stack->top->next->content > *(int *)stack->bottom->content)
		resolve_cmd(c, PSCMD_RRA);
}

void	quadratic_sort_with_planner(t_config *c)
{
	int	i;

	i = c->a->size - 3;
	while (i-- > 0)
	{
		if (c->a->size > 3 && c->b->size > 1
			&& *(int *)c->a->top->content > *(int *)c->a->top->next->content
			&& *(int *)c->b->top->content < *(int *)c->b->top->next->content)
			resolve_cmd(c, PSCMD_SS);
		resolve_cmd(c, PSCMD_PB);
	}
	sort_triplet(c);
	find_and_execute_optimal_plan(c);
}
