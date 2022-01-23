/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:53:35 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/22 23:09:17 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include <libft.h>

typedef struct s_config
{
	t_stack		*a;
	t_stack		*b;
	t_rbtree	*tree;
}			t_config;

void		fake_free(void *p);
void		ps_check_args(int argc, char **argv);
t_config	*ps_config_init(void);
void		ps_config_free(t_config *c);

#endif
