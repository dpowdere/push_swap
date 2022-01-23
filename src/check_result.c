/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 23:00:47 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/23 23:01:17 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "push_swap.h"

void	ps_check_result(t_config *c)
{
	int		ok;
	t_dlist	*elem;

	ok = 1;
	if (c->b->top)
		ok = 0;
	elem = c->a->top;
	while (ok && elem && elem->next)
	{
		ok = ft_intcmp(elem->content, elem->next->content) < 0;
		elem = elem->next;
	}
	if (ok)
		ft_println("OK");
	else
		ft_println("KO");
}
