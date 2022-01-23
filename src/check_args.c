/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 22:29:46 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/22 22:30:34 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stddef.h>
#include <libft.h>
#include "push_swap.h"

#define WHITESPACE_CHARS	" \t\n\r\v\f"

void	ps_populate_b(t_config *c, char *const *list)
{
	int		i;
	int		number;
	char	*endptr;

	i = 0;
	endptr = NULL;
	while (list[i])
	{
		number = ft_strtoi(list[i], &endptr, 10);
		if (errno == EINVAL || errno == ERANGE || (endptr && *endptr != '\0'))
		{
			free((void *)list);
			ps_config_free(c);
			ft_eprintln("Error");
			exit(EXIT_FAILURE);
		}
		ft_stack_push(c->b, ft_new_int(number));
		++i;
	}
}

void	ps_populate_a(t_config *c)
{
	int	*number;

	number = ft_stack_pop(c->b);
	if (rbt_find(c->tree, ft_intcmp, number) != NULL)
	{
		ps_config_free(c);
		ft_eprintln("Error");
		exit(EXIT_FAILURE);
	}
	rbt_insert(&c->tree, ft_intcmp, number);
	ft_stack_push(c->a, number);
}

void	ps_check_args(int argc, char **argv)
{
	t_config	*c;
	char *const	*list;

	c = ps_config_init();
	while (argc-- > 1)
	{
		list = ft_split_const(argv[argc], WHITESPACE_CHARS);
		ps_populate_b(c, list);
		free((void *)list);
		ps_populate_a(c);
	}
	ps_config_free(c);
}
