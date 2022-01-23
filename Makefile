NAME := push_swap
RESOLVER := $(NAME)
CHECKER := checker

SRCS := \
	push_swap.c \
	check_args.c \
	config.c

SRC := src
INC := inc
OBJ := obj
LIB := libft

LIBFT := $(LIB)/$(LIB).a
LIBFT_OBJS := $(addprefix $(LIB)/, $(shell $(MAKE) -sC $(LIB) objls))

OBJS := $(addprefix $(OBJ)/, $(SRCS:.c=.o))
DEPS := $(OBJS:.o=.d)

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -I$(INC) -I$(LIB) -MMD -MP
LDFLAGS		:= -L$(LIB)
LDLIBS		:= -lft
ifdef DEBUG
  LIBDBG := $(LIB)dbg
  LIBFT += $(LIBDBG)/$(LIBDBG).a
  LIBFT_OBJS += $(addprefix $(LIBDBG)/, $(shell $(MAKE) -sC $(LIBDBG) objls))
  CFLAGS += -g3
  CPPFLAGS := -I$(LIBDBG) $(CPPFLAGS)
  LDFLAGS += -L$(LIBDBG)
  LDLIBS := -lftdbg $(LDLIBS)
endif

all: $(RESOLVER) $(CHECKER)

bonus: all

clean:
	$(RM) -r $(OBJ)
	$(MAKE) -C $(LIB) --no-print-directory clean
ifdef DEBUG
	$(MAKE) -C $(LIBDBG) --no-print-directory clean
endif

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

$(LIBDBG)/%.o: $(LIBDBG)/%.c
	$(MAKE) -C $(LIBDBG) --no-print-directory

$(RESOLVER): $(OBJS) $(LIBFT_OBJS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

$(CHECKER):

.PHONY: all bonus clean fclean re

-include $(DEPS)
