/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:53:35 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/23 21:45:09 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include <libft.h>

enum e_cmd
{
	PSCMD_PA,
	PSCMD_PB,
	PSCMD_SA,
	PSCMD_SB,
	PSCMD_SS,
	PSCMD_RA,
	PSCMD_RB,
	PSCMD_RR,
	PSCMD_RRA,
	PSCMD_RRB,
	PSCMD_RRR,
	PSCMD_TERMINATOR
};

typedef struct s_cmd
{
	enum e_cmd	id;
	char const	*name;
	void		(*cmd)(t_stack *, t_stack *);
}			t_cmd;

typedef struct s_config
{
	t_stack		*a;
	t_stack		*b;
	t_rbtree	*tree;
	t_cmd		*cmds;
}			t_config;

void		fake_free(void *p);
void		ps_check_args(int argc, char **argv);
t_config	*ps_config_init(void);
void		ps_config_free(t_config *c);

void		cmd_push_a(t_stack *a, t_stack *b);
void		cmd_push_b(t_stack *a, t_stack *b);
void		cmd_reverse_rotate_a(t_stack *a, t_stack *b);
void		cmd_reverse_rotate_b(t_stack *a, t_stack *b);
void		cmd_reverse_rotate_both(t_stack *a, t_stack *b);
void		cmd_rotate_a(t_stack *a, t_stack *b);
void		cmd_rotate_b(t_stack *a, t_stack *b);
void		cmd_rotate_both(t_stack *a, t_stack *b);
void		cmd_swap_a(t_stack *a, t_stack *b);
void		cmd_swap_b(t_stack *a, t_stack *b);
void		cmd_swap_both(t_stack *a, t_stack *b);

#endif
