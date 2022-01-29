/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftdbg.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:14:56 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/29 20:56:59 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTDBG_H
# define LIBFTDBG_H
# include <libft.h>

void	dl_intDebug(t_dlist *dlist);
void	ft_stack_strDebug(t_stack *stack);
void	ft_stack_intDebug(t_stack *stack);
void	rbt_intDebug(t_rbtree *root);

#endif
