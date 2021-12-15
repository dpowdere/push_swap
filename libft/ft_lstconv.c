/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstconv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:24:23 by dpowdere          #+#    #+#             */
/*   Updated: 2021/12/08 17:25:40 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

/*
** Similar to `ft_lstmap`, but reusing list elements
** while changing their content.
*/
t_list	*ft_lstconv(t_list *lst, void *(*f)(void *))
{
	t_list	*converted_list;

	converted_list = NULL;
	while (lst)
		ft_lstadd_back(&converted_list, ft_lstpopconv(&lst, f));
	return (converted_list);
}

t_list	*ft_lstconv_xd(
			t_list *lst,
			void *(*f)(void *, void *),
			void *extra_data)
{
	t_list	*converted_list;

	converted_list = NULL;
	while (lst)
		ft_lstadd_back(&converted_list, ft_lstpopconv_xd(&lst, f, extra_data));
	return (converted_list);
}
