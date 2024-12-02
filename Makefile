##
# Push Swap
#
# @file
# @version 0.1

CC := cc
CFLAGS := -Wall -Werror -Wextra

INCLUDES := -I. -Ilibft
LIBFT := -Llibft -lft

SRC_FILES := $(wildcard *.c)
OBJ_FILES := $(SRC_FILES:%.c=%.o)

NAME := push_swap

############ Rules ##################
all: libft $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_FILES) -o $(NAME) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

############ PHONY ##################
clean:
	$(MAKE)	-C libft $@
	rm -f $(OBJ_FILES)

fclean: clean
	$(MAKE)	-C libft $@
	rm -rf $(NAME)

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
