/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 02:46:31 by dpowdere          #+#    #+#             */
/*   Updated: 2021/03/12 03:02:46 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <limits.h>

#include "libft.h"

/*
** Naive and lazy conversion of string to int, partly similar
** to `strtoi` BSD function and `strtol`, `strtoll`, `strtoq`
** stdlib functions. It returns no error.
*/

#define DIGITS		"0123456789abcdefghijklmnopqrstuvwxyz"
#define DIGITS_N	36

static int	_strtoi(const char **nptr, int sign, int base)
{
	int	index;
	int	n;
	int	m;

	n = 0;
	m = 0;
	index = ft_str_index(DIGITS, **nptr);
	if (index < 0)
		errno = EINVAL;
	while (index >= 0 && index < base)
	{
		n = n * base + index * sign;
		index = ft_str_index(DIGITS, *++*nptr);
		if ((sign > 0 && n < m) || (sign < 0 && n > m))
			errno = ERANGE;
		if (sign > 0 && n < m)
			return (INT_MAX);
		else if (sign < 0 && n > m)
			return (INT_MIN);
		m = n;
	}
	return (n);
}

int	ft_strtoi(const char *nptr, char **endptr, int base)
{
	int	sign;
	int	n;

	sign = 1;
	if (base < 1 || base > DIGITS_N)
	{
		errno = EINVAL;
		return (0);
	}
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		++nptr;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		++nptr;
	}
	n = _strtoi(&nptr, sign, base);
	if (endptr != NULL)
		*endptr = (char *)nptr;
	return (n);
}
