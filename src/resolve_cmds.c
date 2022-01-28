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

void	ps_resolve_cmds(t_config *c)
{
	enum e_cmd	cmd;
	t_rbtree	*cur;
	int			*number;
	int			i;

	cur = rbt_min(c->tree);
	while (cur)
	{
		number = cur->key;
		i = ft_stack_find(c->a, number);
		cmd = PSCMD_RRA;
		if (i < c->a->size / 2)
			cmd = PSCMD_RA;
		else
			i = c->a->size - i;
		while (i-- > 0)
			ft_lstadd_front(&c->resolved_cmds, ft_lstnew(ft_new_int(cmd)));
		ft_lstadd_front(&c->resolved_cmds, ft_lstnew(ft_new_int(PSCMD_PB)));
		cur = rbt_next(cur);
	}
	i = c->b->size;
	while (i-- > 0)
		ft_lstadd_front(&c->resolved_cmds, ft_lstnew(ft_new_int(PSCMD_PA)));
}
