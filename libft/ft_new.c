/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:30:18 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/18 17:57:24 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "libft.h"

int	*ft_new_int(int n)
{
	int	*p;

	p = (int *)malloc(sizeof(int));
	if (!p)
		return (NULL);
	*p = n;
	return (p);
}

char	*ft_new_str(char const *str)
{
	size_t const	size = ft_strlen(str) + 1;
	char			*str2;

	str2 = (char *)malloc(size);
	if (!str2)
		return (NULL);
	ft_strlcpy(str2, str, size);
	return (str2);
}
