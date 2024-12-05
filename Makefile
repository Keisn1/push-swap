##
# Push Swap
#
# @file
# @version 0.1

CC := cc
CFLAGS := -Wall -Werror -Wextra

INCLUDES := -I. -Ilibft
LIBFT := -Llibft -lft

ALL_C_FILES := $(wildcard *.c)
SRC_FILES := $(filter-out %_bonus.c main.c, $(ALL_C_FILES))
BONUS_SRC_FILES := $(filter-out main.c main_bonus.c, $(ALL_C_FILES))

OBJ_FILES := $(SRC_FILES:%.c=%.o)
BONUS_OBJ_FILES := $(BONUS_SRC_FILES:%.c=%.o)

NAME := push_swap
CHECKER := checker

############ Rules ##################
all: libft $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_FILES) main.c -o $(NAME) $(LIBFT)

bonus: libft $(BONUS_OBJ_FILES)
	$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_OBJ_FILES) main_bonus.c -o $(CHECKER) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

############ PHONY ##################
clean:
	$(MAKE)	-C libft $@
	rm -f $(OBJ_FILES)
	rm -f $(BONUS_OBJ_FILES)

fclean: clean
	$(MAKE)	-C libft $@
	rm -rf $(NAME)
	rm -rf $(CHECKER)

re: fclean all

libft:
	$(MAKE) -C libft

libft-re:
	$(MAKE) -C libft re

src-files:
	@echo $(SRC_FILES)

obj-files:
	@echo $(OBJ_FILES)

.PHONY: all clean fclean re libft obj-files
# end

a minor change
