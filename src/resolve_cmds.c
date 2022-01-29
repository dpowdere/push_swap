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
	t_cmd	*command;

	command = &c->cmds[cmd];
	ft_println(command->name);
	command->cmd(c->a, c->b);
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
		while (*(int *)curr->content < *(int *)prev->content
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
		while (*(int *)curr->content > *(int *)prev->content
			&& *(int *)elem->content > *(int *)curr->content)
		{
			++ix;
			prev = curr;
			curr = curr->next;
		}
	}
	return (ix);
}

static void	sort_planner(t_config *c)
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

void	ps_resolve_cmds(t_config *c)
{
	if (c->a->size < 2)
		return ;
	else if (c->a->size < 4)
		sort_triplet(c);
	else
		sort_planner(c);
}
