NAME := push_swap
RESOLVER := $(NAME)
CHECKER := checker

SRC := src
INC := include
LIB := libft

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -I$(INC) -I$(LIB) -MMD
LDFLAGS		:= -L$(LIB)
LDLIBS		:= -lft

all: $(RESOLVER) $(CHECKER)

bonus: all

clean:

fclean: clean

re: fclean all

.PHONY: all bonus clean fclean re
