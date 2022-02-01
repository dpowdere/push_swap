/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 06:25:23 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/28 06:25:28 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "push_swap.h"

static void	resolve_cmd(t_config *c, enum e_cmd cmd)
{
	t_dlist	*elem;

	elem = dl_new(ft_new_int(cmd));
	dl_extend_head_head(&c->resolved_cmds, elem);
	c->cmds[cmd].cmd(c->a, c->b);
}

static void	resolve_cmd_sequence(t_config *c, enum e_cmd cmd, int i)
{
	while (i-- > 0)
		resolve_cmd(c, cmd);
}

static void	sort_triplet(t_config *c)
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

static int	find_sorted_position_in_rotated_sorted_stack(
				t_dlist *elem, t_stack *stack)
{
	int		ix;
	t_dlist	*prev;
	t_dlist	*curr;

	prev = stack->top;
	if (*(int *)elem->content < *(int *)prev->content)
	{
		curr = stack->bottom;
		ix = stack->size;
		while (curr && *(int *)curr->content < *(int *)prev->content
			&& *(int *)elem->content < *(int *)curr->content)
		{
			--ix;
			prev = curr;
			curr = curr->prev;
		}
	}
	else
	{
		curr = stack->top->next;
		ix = 1;
		while (curr && *(int *)curr->content > *(int *)prev->content
			&& *(int *)elem->content > *(int *)curr->content)
		{
			++ix;
			prev = curr;
			curr = curr->next;
		}
	}
	return (ix);
}

static void	without_planner(t_config *c)
{
	enum e_cmd	cmd;
	int			i;

	while (c->b->top)
	{
		i = find_sorted_position_in_rotated_sorted_stack(c->b->top, c->a);
		if (i > 0)
		{
			cmd = PSCMD_RRA;
			if (i < c->a->size - i)
				cmd = PSCMD_RA;
			else
				i = c->a->size - i;
			while (i-- > 0)
				resolve_cmd(c, cmd);
		}
		resolve_cmd(c, PSCMD_PA);
	}
	i = ft_stack_find(c->a, rbt_min(c->tree)->key);
	cmd = PSCMD_RRA;
	if (i < c->a->size - i)
		cmd = PSCMD_RA;
	else
		i = c->a->size - i;
	while (i-- > 0)
		resolve_cmd(c, cmd);
}

#include <limits.h>

static t_precalc	optimal_operations_count(t_config *c, int i, t_dlist *x)
{
	t_precalc	p;
	int			ix;

	p.rb = i;
	p.rrb = c->b->size - i;
	ix = find_sorted_position_in_rotated_sorted_stack(x, c->a);
	p.ra = ix;
	p.rra = c->a->size - ix;
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

static void	optimal_operations(t_config *c, t_precalc *p)
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
	{
		resolve_cmd_sequence(c, PSCMD_RR, ft_min(p->rb, p->ra));
		if (p->rb > p->ra)
			resolve_cmd_sequence(c, PSCMD_RB, p->rb - p->ra);
		else if (p->rb < p->ra)
			resolve_cmd_sequence(c, PSCMD_RA, p->ra - p->rb);
	}
	else if (p->script == PSS_RRR)
	{
		resolve_cmd_sequence(c, PSCMD_RRR, ft_min(p->rrb, p->rra));
		if (p->rrb > p->rra)
			resolve_cmd_sequence(c, PSCMD_RRB, p->rrb - p->rra);
		else if (p->rrb < p->rra)
			resolve_cmd_sequence(c, PSCMD_RRA, p->rra - p->rrb);
	}
	resolve_cmd(c, PSCMD_PA);
}

static void	final_rotation(t_config *c)
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

static void	with_planner(t_config *c)
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
		best = optimal_operations_count(c, i++, y);
		x = y->next;
		while (x)
		{
			x_best = optimal_operations_count(c, i++, x);
			if (x_best.best < best.best)
				ft_memcpy(&best, &x_best, sizeof(t_precalc));
			x = x->next;
		}
		optimal_operations(c, &best);
		y = c->b->top;
	}
	final_rotation(c);
}

static void	quadratic_sort_with_planner(t_config *c)
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
	(void)without_planner; // delete
	with_planner(c);
}

/*
#include <assert.h>
#include <libftdbg.h>
*/

int	find_uppermedian(t_config *c, t_stack *stack, int size)
{
	t_dlist		*cursor;
	t_rbtree	*tree_node;
	int			i;
	int			minimum;

	i = size - 1;
	minimum = *(int *)stack->top->content;
	cursor = stack->top->next;
	while (i-- > 0)
	{
		if (*(int *)cursor->content < minimum)
			minimum = *(int *)cursor->content;
		cursor = cursor->next;
	}
	tree_node = rbt_find(c->tree, ft_intcmp, &minimum);
	i = size / 2;
	while (i-- > 0)
		tree_node = rbt_next(tree_node);
	return (*(int *)tree_node->key);
}

void	sort_stack_tops(t_config *c)
{
	if (*(int *)c->a->top->content > *(int *)c->a->top->next->content
		&& *(int *)c->b->top->content < *(int *)c->b->top->next->content)
		resolve_cmd(c, PSCMD_SS);
	else if (*(int *)c->a->top->content > *(int *)c->a->top->next->content)
		resolve_cmd(c, PSCMD_SA);
	else if (*(int *)c->b->top->content < *(int *)c->b->top->next->content)
		resolve_cmd(c, PSCMD_SB);
	resolve_cmd(c, PSCMD_PA);
	resolve_cmd(c, PSCMD_PA);
}

void	sort_right_stack_nlogn(t_config *c, int size)
{
	int	median;
	int	i;
	/*
	int left, right;

	ft_eprint(AEC_RED "sort right stack " AEC_RESET);
	ft_putnbr_fd(size, STDERR_FILENO);
	ft_eprint("\n");
	ft_stack_intDebug(c->a);
	ft_stack_intDebug(c->b);
	*/

	if (size == 0)
		return ;
	else if (size == 1)
		resolve_cmd(c, PSCMD_PA);
	else if (size == 2)
	{
		if (*(int *)c->b->top->content < *(int *)c->b->top->next->content)
			resolve_cmd(c, PSCMD_SB);
		resolve_cmd(c, PSCMD_PA);
		resolve_cmd(c, PSCMD_PA);
	}
	else
	{
		median = find_uppermedian(c, c->b, size);
		i = 0;
		/*
		left = right = 0;
		*/
		while (i++ < size)
		{
			if (*(int *)c->b->top->content >= median)
			/*
			{
				*/
				resolve_cmd(c, PSCMD_PA);
				/*
				++left;
			}
			*/
			else
			/*
			{
				*/
				resolve_cmd(c, PSCMD_RB);
				/*
				++right;
			}
			*/
		}
		/*
		ft_putnbr_fd(median, STDERR_FILENO);
		ft_eprint(", ");
		ft_putnbr_fd(left, STDERR_FILENO);
		ft_eprint("-");
		ft_putnbr_fd(right, STDERR_FILENO);
		ft_eprint("\n");
		assert(right == left - (size %2 == 1));
		*/
		i = size / 2;
		while (i-- > 0)
			resolve_cmd(c, PSCMD_RRB);
		sort_left_stack_nlogn(c, size / 2 + (size % 2 == 1));
		sort_right_stack_nlogn(c, size / 2);
	}
}

void	sort_left_stack_nlogn(t_config *c, int size)
{
	int	median;
	int	i;
	/*
	int left, right;

	ft_eprint(AEC_RED "sort left stack " AEC_RESET);
	ft_putnbr_fd(size, STDERR_FILENO);
	ft_eprint("\n");
	ft_stack_intDebug(c->a);
	ft_stack_intDebug(c->b);
	*/

	if (size < 2)
		return ;
	else if (size == 2
		&& *(int *)c->a->top->content > *(int *)c->a->top->next->content)
		resolve_cmd(c, PSCMD_SA);
	else
	{
		median = find_uppermedian(c, c->a, size);
		i = 0;
		/*
		left = right = 0;
		*/
		while (i++ < size)
		{
			if (*(int *)c->a->top->content < median)
			/*
			{
				*/
				resolve_cmd(c, PSCMD_PB);
				/*
				++right;
			}
			*/
			else
			/*
			{
				*/
				resolve_cmd(c, PSCMD_RA);
				/*
				++left;
			}
			*/
		}
		/*
		ft_putnbr_fd(median, STDERR_FILENO);
		ft_eprint(", ");
		ft_putnbr_fd(left, STDERR_FILENO);
		ft_eprint("-");
		ft_putnbr_fd(right, STDERR_FILENO);
		ft_eprint("\n");
		assert(left - (size % 2 == 1) == right);
		*/
		i = size / 2 + (size % 2 == 1);
		while (i-- > 0)
			resolve_cmd(c, PSCMD_RRA);
		sort_left_stack_nlogn(c, size / 2 + (size % 2 == 1));
		sort_right_stack_nlogn(c, size / 2);
	}
}

void	ps_resolve_cmds(t_config *c)
{
	if (c->size < 2)
		return ;
	else if (c->size < 4)
		sort_triplet(c);
	else if (c->size < 60000)
		quadratic_sort_with_planner(c);
	else
		sort_left_stack_nlogn(c, c->size);
}
