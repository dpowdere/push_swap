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

static void	*optimize(enum e_cmd cmd1, enum e_cmd cmd2,
						t_dlist **cmds, t_dlist *elem)
{
	t_dlist	*x;

	if (!elem || !elem->next)
		return (elem);
	if ((
			*(enum e_cmd *)elem->content == cmd1 && \
			*(enum e_cmd *)elem->next->content == cmd2) \
		|| (
			*(enum e_cmd *)elem->content == cmd2 && \
			*(enum e_cmd *)elem->next->content == cmd1))
	{
		x = elem->prev;
		if (!x)
			x = elem->next->next;
		dl_erase(elem->next, free);
		dl_erase(elem, free);
		if (elem == *cmds)
			*cmds = x;
		return (x);
	}
	return (elem);
}

void	ps_optimize_cmds(t_config *c)
{
	t_dlist	*curr;
	t_dlist	*next;

	curr = c->resolved_cmds;
	while (curr && curr->next)
	{
		next = curr;
		next = optimize(PSCMD_RR, PSCMD_RRR, &c->resolved_cmds, next);
		next = optimize(PSCMD_RA, PSCMD_RRA, &c->resolved_cmds, next);
		next = optimize(PSCMD_RB, PSCMD_RRB, &c->resolved_cmds, next);
		next = optimize(PSCMD_PA, PSCMD_PB, &c->resolved_cmds, next);
		if (next == curr)
			curr = curr->next;
		else
			curr = next;
	}
}
