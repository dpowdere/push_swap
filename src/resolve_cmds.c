/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 06:25:23 by dpowdere          #+#    #+#             */
/*   Updated: 2022/02/01 16:10:50 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "push_swap.h"

void	resolve_cmd(t_config *c, enum e_cmd cmd)
{
	t_dlist	*elem;

	elem = dl_new(ft_new_int(cmd));
	dl_extend_head_head(&c->resolved_cmds, elem);
	c->cmds[cmd].cmd(c->a, c->b);
}

void	resolve_cmd_sequence(t_config *c, enum e_cmd cmd, int i)
{
	while (i-- > 0)
		resolve_cmd(c, cmd);
}

void	ps_resolve_cmds(t_config *c)
{
	if (c->size < 2)
		return ;
	else if (c->size < 4)
		sort_triplet(c);
	else if (c->size < 750)
		quadratic_sort_with_planner(c);
	else
		sort_left_stack_nlogn(c, c->size);
}
