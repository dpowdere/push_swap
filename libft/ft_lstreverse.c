/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 07:15:39 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/28 08:02:14 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstreverse(t_list **lst)
{
	t_list	*prv;
	t_list	*cur;
	t_list	*nxt;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	prv = NULL;
	cur = *lst;
	while (cur)
	{
		nxt = cur->next;
		cur->next = prv;
		prv = cur;
		cur = nxt;
	}
	if (prv)
		*lst = prv;
}
