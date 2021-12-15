/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:34:21 by dpowdere          #+#    #+#             */
/*   Updated: 2021/12/08 17:52:01 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void	*ft_lstpop(t_list **lst)
{
	void	*content;
	t_list	*elem;

	elem = *lst;
	content = elem->content;
	*lst = elem->next;
	free(elem);
	return (content);
}
