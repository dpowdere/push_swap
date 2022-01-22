/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 10:47:44 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/22 10:47:49 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "libft.h"

void	ft_q_init(t_queue *queue)
{
	queue->in = NULL;
	queue->out = NULL;
	queue->size = 0;
}

t_queue	*ft_q_new(void)
{
	t_queue	*q;

	q = (t_queue *)malloc(sizeof(t_queue));
	if (!q)
		return (NULL);
	ft_q_init(q);
	return (q);
}

void	ft_q_clear(t_queue *queue, void (*f)(void *))
{
	if (!queue || !f)
		return ;
	dl_nxt_clear(&queue->in, f);
	queue->out = NULL;
	queue->size = 0;
}

void	ft_q_destroy(t_queue **queue, void (*f)(void *))
{
	ft_q_clear(*queue, f);
	free(queue);
}
