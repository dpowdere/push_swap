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

#include "push_swap.h"

void	fake_free(void *p)
{
	(void)p;
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
	return (c);
}

void	ps_config_free(t_config *c)
{
	rbt_clear(&c->tree, fake_free);
	ft_stack_destroy(&c->a, free);
	ft_stack_destroy(&c->b, free);
	free(c);
}
