/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:07:59 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/29 19:08:30 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "push_swap.h"

#define OPTIMIZATIONS_2TO1_NUM	3

static void	*optimize_2to0(enum e_cmd cmd1, enum e_cmd cmd2,
							t_dlist **cmds, t_dlist *x)
{
	t_dlist	*y;

	if (!x || !x->next)
		return (x);
	if ((*(t_op *)x->content == cmd1 && *(t_op *)x->next->content == cmd2)
		|| (*(t_op *)x->content == cmd2 && *(t_op *)x->next->content == cmd1))
	{
		y = x->prev;
		if (!y)
			y = x->next->next;
		dl_erase(x->next, free);
		dl_erase(x, free);
		if (x == *cmds)
			*cmds = y;
		return (y);
	}
	return (x);
}

static t_dlist	*_optimize_2to1(t_op const op[3], t_dlist *x)
{
	t_dlist			*y;
	t_dlist const	*z = x->next;

	if ((*(t_op *)x->content == op[0] && *(t_op *)z->content == op[1])
		|| (*(t_op *)x->content == op[1] && *(t_op *)z->content == op[0]))
	{
		y = x->prev;
		if (!y)
			y = x;
		dl_erase(x->next, free);
		*(t_op *)x->content = op[2];
		return (y);
	}
	return (x);
}

static void	*optimize_2to1(t_dlist *x)
{
	int			i;
	t_op const	op[OPTIMIZATIONS_2TO1_NUM][3] = {
	{PSCMD_SA, PSCMD_SB, PSCMD_SS},
	{PSCMD_RA, PSCMD_RB, PSCMD_RR},
	{PSCMD_RRA, PSCMD_RRB, PSCMD_RRR}
	};

	if (!x || !x->next)
		return (x);
	i = 0;
	while (i < OPTIMIZATIONS_2TO1_NUM)
		x = _optimize_2to1(op[i++], x);
	return (x);
}

void	ps_optimize_cmds(t_config *c)
{
	t_dlist	*curr;
	t_dlist	*next;

	curr = c->resolved_cmds;
	while (curr && curr->next)
	{
		next = curr;
		next = optimize_2to0(PSCMD_RR, PSCMD_RRR, &c->resolved_cmds, next);
		next = optimize_2to0(PSCMD_RA, PSCMD_RRA, &c->resolved_cmds, next);
		next = optimize_2to0(PSCMD_RB, PSCMD_RRB, &c->resolved_cmds, next);
		next = optimize_2to0(PSCMD_PA, PSCMD_PB, &c->resolved_cmds, next);
		next = optimize_2to1(next);
		if (next == curr)
			curr = curr->next;
		else
			curr = next;
	}
}
