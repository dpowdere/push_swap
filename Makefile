NAME := push_swap
RESOLVER := $(NAME)
CHECKER := checker

SRCS := push_swap.c

SRC := src
INC := inc
OBJ := obj
LIB := libft

LIBFT := $(LIB)/libft.a
LIBFT_OBJS := $(addprefix $(LIB)/, $(shell $(MAKE) -sC $(LIB) object_list))

OBJS := $(addprefix $(OBJ)/, $(SRCS:.c=.o))
DEPS := $(OBJS:.o=.d)

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -I$(INC) -I$(LIB) -MMD -MP
LDFLAGS		:= -L$(LIB)
LDLIBS		:= -lft
ifdef DEBUG
  CFLAGS += -g3
endif

all: $(RESOLVER) $(CHECKER)

bonus: all

clean:
	$(RM) -r $(OBJ)
	$(MAKE) -C $(LIB) --no-print-directory clean

fclean: clean
	$(RM) $(RESOLVER) $(CHECKER) $(LIBFT)
	$(RM) -r *.dSYM

re: fclean all

$(OBJS): | $(OBJ)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

$(OBJ):
	mkdir $@

$(LIB)/%.o: $(LIB)/%.c
	$(MAKE) -C $(LIB) --no-print-directory

$(RESOLVER): $(OBJS) $(LIBFT_OBJS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

$(CHECKER):

.PHONY: all bonus clean fclean re

-include $(DEPS)
