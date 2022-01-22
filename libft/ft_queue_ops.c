/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 11:11:55 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/22 11:12:24 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_q_en(t_queue *queue, void *data)
{
	t_dlist	*new;

	if (!queue || !data)
		return ;
	new = dl_new(data);
	if (!new)
		return ;
	dl_extend_head_head(&queue->in, new);
	if (!queue->out)
		queue->out = queue->in;
	++queue->size;
}

void	*ft_q_de(t_queue *queue)
{
	void	*data;

	if (!queue)
		return (NULL);
	data = dl_pop(&queue->out);
	if (!queue->out)
		queue->in = NULL;
	--queue->size;
	return (data);
}
