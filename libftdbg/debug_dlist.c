/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_dlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:57:33 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/29 21:03:24 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	dl_intDebug(t_dlist *dlist)
{
	t_dlist	*tmp;

	ft_eprint(":-->:" AEC_YELLOW);
	tmp = dlist;
	while (dlist)
	{
		ft_eprint(" ");
		ft_putnbr_fd(*(int *)dlist->content, STDERR_FILENO);
		tmp = dlist;
		dlist = dlist->next;
	}
	ft_eprint(AEC_RESET "\n:<--:" AEC_YELLOW);
	dlist = tmp;
	while (dlist)
	{
		ft_eprint(" ");
		ft_putnbr_fd(*(int *)dlist->content, STDERR_FILENO);
		dlist = dlist->prev;
	}
	ft_eprint(AEC_RESET "\n\n");
}
