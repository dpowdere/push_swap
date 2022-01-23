/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:41:14 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/23 14:42:11 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_config	*c;
	t_cmd		*cmd;
	int			eof;

	c = ps_check_args(argc, argv);
	cmd = NULL;
	eof = 0;
	while (c->read(c->cmds, &cmd, &eof) && cmd && !eof)
		cmd->cmd(c->a, c->b);
	if (!eof)
		ft_eprintln("Error");
	else
		ps_check_result(c);
	ps_config_free(c);
	return (EXIT_SUCCESS);
}
