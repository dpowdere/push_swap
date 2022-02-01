/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:36:22 by dpowdere          #+#    #+#             */
/*   Updated: 2022/02/01 16:36:31 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "push_swap.h"

void	find_and_execute_optimal_plan(t_config *c)
{
	t_dlist		*x;
	t_dlist		*y;
	t_precalc	x_best;
	t_precalc	best;
	int			i;

	y = c->b->top;
	while (y)
	{
		i = 0;
		best = find_optimal_plan(c, i++, y);
		x = y->next;
		while (x)
		{
			x_best = find_optimal_plan(c, i++, x);
			if (x_best.best < best.best)
				ft_memcpy(&best, &x_best, sizeof(t_precalc));
			x = x->next;
		}
		execute_optimal_plan(c, &best);
		y = c->b->top;
	}
	final_rotation(c);
}

t_precalc	find_optimal_plan(t_config *c, int i, t_dlist *x)
{
	t_precalc	p;

	p.rb = i;
	p.rrb = c->b->size - i;
	p.ra = find_sorted_position_in_rotated_sorted_stack(x, c->a);
	p.rra = c->a->size - p.ra;
	p.best = ft_max(p.rb, p.ra);
	p.script = PSS_RR;
	if (p.best > ft_max(p.rrb, p.rra))
	{
		p.best = ft_max(p.rrb, p.rra);
		p.script = PSS_RRR;
	}
	if (p.best > p.rrb + p.ra)
	{
		p.best = p.rrb + p.ra;
		p.script = PSS_RRB_RA;
	}
	if (p.best > p.rb + p.rra)
	{
		p.best = p.rb + p.rra;
		p.script = PSS_RB_RRA;
	}
	p.best += 1;
	return (p);
}

static inline void	resolve_rr(t_config *c, t_precalc *p)
{
	resolve_cmd_sequence(c, PSCMD_RR, ft_min(p->rb, p->ra));
	if (p->rb > p->ra)
		resolve_cmd_sequence(c, PSCMD_RB, p->rb - p->ra);
	else if (p->rb < p->ra)
		resolve_cmd_sequence(c, PSCMD_RA, p->ra - p->rb);
}

static inline void	resolve_rrr(t_config *c, t_precalc *p)
{
	resolve_cmd_sequence(c, PSCMD_RRR, ft_min(p->rrb, p->rra));
	if (p->rrb > p->rra)
		resolve_cmd_sequence(c, PSCMD_RRB, p->rrb - p->rra);
	else if (p->rrb < p->rra)
		resolve_cmd_sequence(c, PSCMD_RRA, p->rra - p->rrb);
}

void	execute_optimal_plan(t_config *c, t_precalc *p)
{
	if (p->script == PSS_RB_RRA)
	{
		resolve_cmd_sequence(c, PSCMD_RB, p->rb);
		resolve_cmd_sequence(c, PSCMD_RRA, p->rra);
	}
	else if (p->script == PSS_RRB_RA)
	{
		resolve_cmd_sequence(c, PSCMD_RRB, p->rrb);
		resolve_cmd_sequence(c, PSCMD_RA, p->ra);
	}
	else if (p->script == PSS_RR)
		resolve_rr(c, p);
	else if (p->script == PSS_RRR)
		resolve_rrr(c, p);
	resolve_cmd(c, PSCMD_PA);
}
