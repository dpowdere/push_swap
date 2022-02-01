/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:53:35 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/29 19:08:51 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include <libft.h>

typedef enum e_cmd
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
}			t_op;

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
	t_dlist		*resolved_cmds;
	t_cmd		*cmds;
	int const	size;
	int			(*read)(t_cmd *cmds, t_cmd **cmd, int *eof);
}			t_config;

typedef enum e_script
{
	PSS_RR,
	PSS_RRR,
	PSS_RB_RRA,
	PSS_RRB_RA
}			t_script;

typedef struct s_precalc
{
	int			ra;
	int			rra;
	int			rb;
	int			rrb;
	int			best;
	t_script	script;
}			t_precalc;

void		execute_optimal_plan(t_config *c, t_precalc *p);
void		fake_free(void *p);
void		final_rotation(t_config *c);
void		find_and_execute_optimal_plan(t_config *c);
t_precalc	find_optimal_plan(t_config *c, int i, t_dlist *x);
int			find_sorted_position_in_rotated_sorted_stack(
				t_dlist *elem, t_stack *stack);
int			find_uppermedian(t_config *c, t_stack *stack, int size);
void		quadratic_sort_with_planner(t_config *c);
void		resolve_cmd(t_config *c, enum e_cmd cmd);
void		resolve_cmd_sequence(t_config *c, enum e_cmd cmd, int i);
void		sort_left_stack_nlogn(t_config *c, int size);
void		sort_right_stack_nlogn(t_config *c, int size);
void		sort_triplet(t_config *c);

t_config	*ps_check_args(int argc, char **argv);
void		ps_check_result(t_config *c);
void		ps_config_free(t_config *c);
t_config	*ps_config_init(void);
void		ps_optimize_cmds(t_config *c);
void		ps_resolve_cmds(t_config *c);
void		ps_print_cmds(t_config *c);

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
