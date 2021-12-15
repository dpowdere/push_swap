/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 11:31:13 by dpowdere          #+#    #+#             */
/*   Updated: 2021/12/09 17:18:43 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include <stddef.h>
# include <sys/types.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# define NL_CHAR '\n'

# define GNL_LINE	1
# define GNL_EOF	0
# define GNL_ERROR	-1

# define READ_EOF	0
# define READ_ERROR	-1

# define SUCCESS	1
# define FAIL		0

# define FOUND			1
# define NOT_FOUND		0

struct			s_part
{
	char			*s;
	ssize_t			size;
	struct s_part	*next;
};

struct			s_stash
{
	int				fd;
	ssize_t			start;
	ssize_t			end;
	struct s_part	*head;
	struct s_part	*tail;
};

# define DEFAULT_FD -1
# define DEFAULT_START_POS	0
# define DEFAULT_END_POS	-1

int		gnl_add_tail(struct s_stash *stash);
void	gnl_dump_line(struct s_stash *stash, char *line);
int		gnl_find_nl(struct s_stash *stash);
int		gnl_get_line_from_stash(struct s_stash *stash, char **line);
size_t	gnl_get_line_size(struct s_stash *stash);
void	gnl_reset(struct s_stash *stash, int kind);

# define RESET_ALL_TO_DEFAULT	0
# define KEEP_FILE_DESCRIPTOR	1

#endif
