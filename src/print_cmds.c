/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 06:25:34 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/28 06:26:03 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "push_swap.h"

void	ps_print_cmds(t_config *c)
{
	enum e_cmd	*cmd;

	ft_lstreverse(&c->resolved_cmds);
	cmd = ft_lstpop(&c->resolved_cmds);
	while (cmd)
	{
		ft_print(c->cmds[*cmd].name);
		cmd = ft_lstpop(&c->resolved_cmds);
	}
}
