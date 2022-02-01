/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlogn_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:19:00 by dpowdere          #+#    #+#             */
/*   Updated: 2022/02/01 16:19:04 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "push_swap.h"

void	sort_left_stack_nlogn(t_config *c, int size)
{
	int	median;
	int	i;

	if (size < 2)
		return ;
	else if (size == 2
		&& *(int *)c->a->top->content > *(int *)c->a->top->next->content)
		resolve_cmd(c, PSCMD_SA);
	else
	{
		median = find_uppermedian(c, c->a, size);
		i = 0;
		while (i++ < size)
		{
			if (*(int *)c->a->top->content < median)
				resolve_cmd(c, PSCMD_PB);
			else
				resolve_cmd(c, PSCMD_RA);
		}
		resolve_cmd_sequence(c, PSCMD_RRA, size / 2 + (size % 2 == 1));
		sort_left_stack_nlogn(c, size / 2 + (size % 2 == 1));
		sort_right_stack_nlogn(c, size / 2);
	}
}

static inline void	sort_right_stack_size2(t_config *c)
{
	if (*(int *)c->b->top->content < *(int *)c->b->top->next->content)
		resolve_cmd(c, PSCMD_SB);
	resolve_cmd_sequence(c, PSCMD_PA, 2);
}

void	sort_right_stack_nlogn(t_config *c, int size)
{
	int	median;
	int	i;

	if (size < 2)
		resolve_cmd_sequence(c, PSCMD_PA, size);
	else if (size == 2)
		sort_right_stack_size2(c);
	else
	{
		median = find_uppermedian(c, c->b, size);
		i = 0;
		while (i++ < size)
		{
			if (*(int *)c->b->top->content >= median)
				resolve_cmd(c, PSCMD_PA);
			else
				resolve_cmd(c, PSCMD_RB);
		}
		resolve_cmd_sequence(c, PSCMD_RRB, size / 2);
		sort_left_stack_nlogn(c, size / 2 + (size % 2 == 1));
		sort_right_stack_nlogn(c, size / 2);
	}
}

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
