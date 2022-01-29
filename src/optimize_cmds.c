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

static void	*optimize(enum e_cmd cmd1, enum e_cmd cmd2, t_dlist *elem, t_config *c)
{
	t_dlist	*prev;
	t_dlist	*curr;
	t_dlist	*next;
	t_dlist	*next_next;
	void	*tmp;

	if (!elem || !elem->next)
		return (NULL);
	if ((
			*(enum e_cmd *)elem->content == cmd1 && \
			*(enum e_cmd *)elem->next->content == cmd2) \
		|| (
			*(enum e_cmd *)elem->content == cmd2 && \
			*(enum e_cmd *)elem->next->content == cmd1))
	{
		ft_print("optimize out: ");
		ft_print(c->cmds[cmd1].name);
		ft_print(" || ");
		ft_println(c->cmds[cmd2].name);
		prev = elem->prev;
		curr = elem;
		next = elem->next;
		next_next = elem->next->next;
		tmp = dl_pop(&next);
		free(tmp);
		tmp = dl_pop(&curr);
		free(tmp);
		if (prev)
			return (prev);
		else
			return (next_next);
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
		next = optimize(PSCMD_RR, PSCMD_RRR, next, c);
		next = optimize(PSCMD_RA, PSCMD_RRA, next, c);
		next = optimize(PSCMD_RB, PSCMD_RRB, next, c);
		next = optimize(PSCMD_PA, PSCMD_PB,  next, c);
		if (curr == c->resolved_cmds && next != curr)
			c->resolved_cmds = next;
		if (next == curr)
			curr = curr->next;
		else
			curr = next;
	}
}
