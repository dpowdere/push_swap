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

#include "push_swap.h"
#include "../src/debug.c"

int	main(int argc, char *argv[])
{
	t_config	*c;

	debug();
	c = ps_check_args(argc, argv);
	// resolve cmd sequence
	ps_config_free(c);
	return (EXIT_SUCCESS);
}
