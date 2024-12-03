##
# Push Swap
#
# @file
# @version 0.1

CC := cc
CFLAGS := -Wall -Werror -Wextra
GTEST_LIBS := -lgtest -lgtest_main -pthread #for googletests

CXX := g++
CXX_FLAGS := -Wall -Werror -Wextra
FSANITIZE =
VERBOSE =

SRC_DIR := src
RUN_DIR := run
BIN_DIR := bin
OBJ_DIR := obj
BUILD_DIR := build
TEST_DIR := tests
INCLUDES := -Iincludes -Ilibft
LIBFT := -Llibft -lft

SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME := push_swap
CHECKER := checker

############ Rules ##################
all: libft $(NAME)

$(NAME): $(OBJ_FILES) $(RUN_DIR)/push_swap/main.c
	$(CC) $(CFLAGS) $(INCLUDES) $(FSANITIZE) $(OBJ_FILES) $(RUN_DIR)/$(NAME)/main.c -o $(NAME) $(LIBFT)

bonus: libft $(OBJ_FILES) $(RUN_DIR)/checker/main.c
	$(CC) $(CFLAGS) $(INCLUDES) $(FSANITIZE) $(OBJ_FILES) $(RUN_DIR)/$(CHECKER)/main.c -o $(CHECKER) $(LIBFT)

# Object file compilation for C
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(FSANITIZE) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

############ PHONY ##################
clean:
	$(MAKE)	-C libft $@
	rm -f $(OBJ_FILES) $(BONUS_OBJ_FILES)

fclean: clean
	$(MAKE)	-C libft $@
	rm -rf $(BIN_DIR)
	rm -rf $(OBJ_DIR)
	rm -rf $(BUILD_DIR)
	rm -rf $(NAME)

re: fclean all

test_all: test test_push_swap test_push_swap_valgrind

test:
	cmake -S . -B build -DBUILD_TEST=ON && \
	cmake --build build && \
	./build/run_tests

test_push_swap:
	make FSANITIZE=-fsanitize=address && \
	pytest tests/test_push_swap.py::test_push_swap

test_push_swap_valgrind:
	make && \
	pytest tests/test_push_swap.py::test_push_swap_valgrind

test_checker:
	make bonus && \
	pytest tests/test_checker.py::test_checker

test_checker_valgrind:
	make bonus && \
	pytest $(VERBOSE) tests/test_checker.py::test_checker_valgrind

compile_commands:
	cmake -S . -B build -DBUILD_TEST=ON -DBUILD_PUSH_SWAP=ON -DCMAKE_EXPORT_COMPILE_COMMANDS=ON && \
	rm -f compile_commands.json
	mv build/compile_commands.json ./compile_commands.json

libft:
	$(MAKE) -C libft

libft-re:
	$(MAKE) -C libft re

bear: $(NAME)

norminette:
	- norminette -R CheckForbiddenSourceHeader -R CheckDefine $(SRC_DIR)/
	- norminette -R CheckForbiddenSourceHeader -R CheckDefine $(SRC_DIR)/
	- norminette -R CheckForbiddenSourceHeader -R CheckDefine $(INCLUDES)/

src-files:
	@echo $(SRC_FILES)

obj-files:
	@echo $(OBJ_FILES)

.PHONY: all clean fclean test libft bonus test-bonus subproject obj-files
# end
