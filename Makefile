NAME := push_swap
RESOLVER := $(NAME)
CHECKER := checker

RESOLVER_SRCS := push_swap.c check_args.c config.c \
	resolve_cmds.c optimize_cmds.c print_cmds.c \
	cmd_push.c cmd_swap.c cmd_rotate.c cmd_reverse_rotate.c
CHECKER_SRCS := checker.c check_args.c check_result.c config.c \
	cmd_push.c cmd_swap.c cmd_rotate.c cmd_reverse_rotate.c

SRC := src
INC := inc
OBJ := obj
LIB := libft

LIBFT := $(LIB)/$(LIB).a
LIBFT_OBJS := $(addprefix $(LIB)/, $(shell $(MAKE) -sC $(LIB) objls))

RESOLVER_OBJS := $(addprefix $(OBJ)/, $(RESOLVER_SRCS:.c=.o))
RESOLVER_DEPS := $(RESOLVER_OBJS:.o=.d)
CHECKER_OBJS := $(addprefix $(OBJ)/, $(CHECKER_SRCS:.c=.o))
CHECKER_DEPS := $(CHECKER_OBJS:.o=.d)

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

$(RESOLVER_OBJS): | $(OBJ)

$(CHECKER_OBJS): | $(OBJ)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

$(OBJ):
	mkdir $@

$(LIB)/%.o: $(LIB)/%.c
	$(MAKE) -C $(LIB) --no-print-directory

$(RESOLVER): $(RESOLVER_OBJS) $(LIBFT_OBJS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $(RESOLVER_OBJS) $(LDLIBS)

$(CHECKER): $(CHECKER_OBJS) $(LIBFT_OBJS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $(CHECKER_OBJS) $(LDLIBS)

.PHONY: all bonus clean fclean re

-include $(RESOLVER_DEPS) $(CHECKER_DEPS)
