/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpopreduce.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:40:58 by dpowdere          #+#    #+#             */
/*   Updated: 2021/12/08 17:45:00 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstpopreduce(t_list **lst, void *init, void *(*f)(void *, void *))
{
	while (*lst)
		init = f(init, ft_lstpop(lst));
	return (init);
}
