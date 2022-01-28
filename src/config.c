/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 23:03:56 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/22 23:10:03 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <libft.h>

#include "push_swap.h"

void	fake_free(void *p)
{
	(void)p;
}

static int	read_cmd(t_cmd *cmds, t_cmd **cmd, int *eof)
{
	char	*line;
	int		ret;
	int		i;

	line = NULL;
	*cmd = NULL;
	ret = ft_get_next_line(STDIN_FILENO, &line);
	if (ret == 1)
	{
		i = 0;
		while (i < PSCMD_TERMINATOR)
		{
			if (ft_strcmp(line, cmds[i].name) == 0)
			{
				*cmd = &cmds[i];
				break ;
			}
			++i;
		}
	}
	*eof = ret == 0;
	free(line);
	return (ret);
}

static t_cmd	*ps_cmds_init(void)
{
	static t_cmd	cmds[PSCMD_TERMINATOR] = {
	{PSCMD_PA, "pa", cmd_push_a},
	{PSCMD_PB, "pb", cmd_push_b},
	{PSCMD_SA, "sa", cmd_swap_a},
	{PSCMD_SB, "sb", cmd_swap_b},
	{PSCMD_SS, "ss", cmd_swap_both},
	{PSCMD_RA, "ra", cmd_rotate_a},
	{PSCMD_RB, "rb", cmd_rotate_b},
	{PSCMD_RR, "rr", cmd_rotate_both},
	{PSCMD_RRA, "rra", cmd_reverse_rotate_a},
	{PSCMD_RRB, "rrb", cmd_reverse_rotate_b},
	{PSCMD_RRR, "rrr", cmd_reverse_rotate_both}
	};

	return (cmds);
}

t_config	*ps_config_init(void)
{
	t_config	*c;

	c = (t_config *)malloc(sizeof(t_config));
	if (!c)
	{
		ft_eprintln("Can't allocate memory");
		exit(errno);
	}
	c->a = ft_stack_new();
	c->b = ft_stack_new();
	c->tree = NULL;
	c->resolved_cmds = NULL;
	c->cmds = ps_cmds_init();
	c->read = read_cmd;
	return (c);
}

void	ps_config_free(t_config *c)
{
	rbt_clear(&c->tree, fake_free);
	ft_stack_destroy(&c->a, free);
	ft_stack_destroy(&c->b, free);
	ft_lstclear(&c->resolved_cmds, free);
	free(c);
}
