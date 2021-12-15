/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 11:29:30 by dpowdere          #+#    #+#             */
/*   Updated: 2021/12/09 17:20:46 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#include "ft_get_next_line.h"

int	ft_get_next_line(int fd, char **line)
{
	static struct s_stash	stash;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (GNL_ERROR);
	if (stash.fd != fd)
	{
		gnl_reset(&stash, RESET_ALL_TO_DEFAULT);
		stash.fd = fd;
	}
	if (stash.tail == NULL && gnl_add_tail(&stash) == FAIL)
		return (GNL_ERROR);
	while (gnl_find_nl(&stash) == NOT_FOUND)
	{
		if (gnl_add_tail(&stash) == FAIL)
		{
			gnl_reset(&stash, RESET_ALL_TO_DEFAULT);
			return (GNL_ERROR);
		}
	}
	*line = NULL;
	if (gnl_get_line_from_stash(&stash, line) == FAIL)
		return (GNL_ERROR);
	if (*line == NULL)
		return (GNL_EOF);
	return (GNL_LINE);
}

void	gnl_reset(struct s_stash *stash, int kind)
{
	struct s_part	*tmp;

	if (kind == RESET_ALL_TO_DEFAULT)
		stash->fd = DEFAULT_FD;
	stash->start = DEFAULT_START_POS;
	stash->end = DEFAULT_END_POS;
	while (stash->head)
	{
		if (stash->head->s)
			free(stash->head->s);
		tmp = stash->head;
		stash->head = stash->head->next;
		free(tmp);
	}
	stash->head = NULL;
	stash->tail = NULL;
}

int	gnl_add_tail(struct s_stash *stash)
{
	struct s_part	*tail;

	tail = (struct s_part *)malloc(sizeof(struct s_part));
	if (tail == NULL)
		return (FAIL);
	tail->next = NULL;
	tail->s = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (tail->s == NULL)
	{
		free(tail);
		return (FAIL);
	}
	if (stash->tail == NULL)
		stash->head = tail;
	else
		stash->tail->next = tail;
	stash->tail = tail;
	tail->size = read(stash->fd, tail->s, BUFFER_SIZE);
	if (tail->size == READ_ERROR)
		return (FAIL);
	return (SUCCESS);
}

int	gnl_find_nl(struct s_stash *stash)
{
	if (stash->head->next == NULL)
		stash->end = stash->start;
	else
		stash->end = 0;
	if (stash->tail->size == READ_EOF)
		return (FOUND);
	while (stash->end < stash->tail->size)
	{
		if (stash->tail->s[stash->end] == NL_CHAR)
			return (FOUND);
		stash->end += 1;
	}
	return (NOT_FOUND);
}

int	gnl_get_line_from_stash(struct s_stash *stash, char **line)
{
	size_t	size;

	if (stash->head->next == NULL && stash->tail->size == READ_EOF)
	{
		*line = NULL;
		gnl_reset(stash, RESET_ALL_TO_DEFAULT);
		return (SUCCESS);
	}
	size = gnl_get_line_size(stash);
	*line = (char *)malloc(size * sizeof(char));
	if (*line == NULL)
	{
		gnl_reset(stash, RESET_ALL_TO_DEFAULT);
		return (FAIL);
	}
	gnl_dump_line(stash, *line);
	if (stash->start >= stash->tail->size)
		gnl_reset(stash, KEEP_FILE_DESCRIPTOR);
	return (SUCCESS);
}
