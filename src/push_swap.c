/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:55:08 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/22 13:26:58 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_config	*c;

	c = ps_check_args(argc, argv);
	ps_resolve_cmds(c);
	dl_nxt_reverse(&c->resolved_cmds);
	ps_optimize_cmds(c);
	ps_print_cmds(c);
	ps_config_free(c);
	return (EXIT_SUCCESS);
}
