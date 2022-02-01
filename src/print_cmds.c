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

#include <stdlib.h>
#include <libft.h>
#include "push_swap.h"

void	ps_print_cmds(t_config *c)
{
	enum e_cmd	*cmd;

	cmd = dl_pop(&c->resolved_cmds);
	while (cmd)
	{
		ft_println(c->cmds[*cmd].name);
		free((void *)cmd);
		cmd = dl_pop(&c->resolved_cmds);
	}
}
