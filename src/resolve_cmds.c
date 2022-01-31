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

static void	quadratic_sort_with_planner(t_config *c)
{
	enum e_cmd	cmd;
	int			i;

	i = c->a->size - 3;
	while (i-- > 0)
	{
		if (c->size >= 500 && c->a->size > 3 && c->b->size > 1
			&& *(int *)c->a->top->content > *(int *)c->a->top->next->content
			&& *(int *)c->b->top->content < *(int *)c->b->top->next->content)
			resolve_cmd(c, PSCMD_SS);
		resolve_cmd(c, PSCMD_PB);
	}
	sort_triplet(c);
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
	else if (c->size < 8)
		quadratic_sort_with_planner(c);
	else
		sort_left_stack_nlogn(c, c->size);
}
