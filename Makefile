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
FSANITIZE = -fsanitize=address

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

# TEST_SRC_FILES := $(wildcard $(TEST_DIR)/*.cpp )
# TEST_OBJ_FILES := $(TEST_SRC_FILES:$(TEST_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# TEST_TARGET := bin/run_tests

NAME := push_swap

############ Rules ##################
all: libft $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(INCLUDES)  $(OBJ_FILES) $(RUN_DIR)/main.c -o $(NAME) $(LIBFT)


# Object file compilation for C
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


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

re: fclean all

test:
	cmake -S . -B build -DBUILD_TEST=ON && \
	cmake --build build && \
	./build/run_tests

compile_commands:
	cmake -S . -B build -DBUILD_TEST=ON -DBUILD_PUSH_SWAP=ON -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

libft:
	$(MAKE) -C libft

libft-re:
	$(MAKE) -C libft re

bear: $(NAME) $(TEST_TARGET)

norminette:
	- norminette -R CheckForbiddenSourceHeader -R CheckDefine $(SRC_DIR)/
	- norminette -R CheckForbiddenSourceHeader -R CheckDefine $(SRC_DIR)/
	- norminette -R CheckForbiddenSourceHeader -R CheckDefine $(INCLUDES)/

src-files:
	@echo $(SRC_FILES)

obj-files:
	@echo $(OBJ_FILES)

test-obj-files:
	@echo $(TEST_OBJ_FILES)

.PHONY: all clean fclean test libft bonus test-bonus subproject obj-files
# end
