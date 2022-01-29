# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 20:21:26 by dpowdere          #+#    #+#              #
#    Updated: 2022/01/21 20:21:28 by dpowdere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBNAME := libftdbg
CONTENTS := \
  debug_dlist.c \
  debug_int_rbtree.c \
  debug_stack.c

AR := ar
ARFLAGS := crs

LIBFT := ../libft

CC := gcc
CFLAGS := -Wall -Wextra -Werror -g3
CPPFLAGS := -MMD -MP -I$(LIBFT)

NAME := $(LIBNAME).a
OBJS := $(CONTENTS:.c=.o)
DEPS := $(OBJS:.o=.d)

################################################################################

.PHONY: all clean fclean objls re

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

#%.o: %.c
#	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

all: $(NAME)

clean:
	$(RM) *.o *.d *.gch

fclean: clean
	$(RM) $(NAME) *.dSYM

re: fclean all

objls:
	@$(info $(OBJS))

-include $(DEPS)
