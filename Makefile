SRC_DIR 	:= src
OBJ_DIR 	:= obj

BIN 		:= solver
SRC 		:= $(wildcard $(SRC_DIR)/*.c)
OBJ 		:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

CC			:= gcc
CFLAGS		:= -g -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	/bin/rm -fr $(OBJ_DIR)

fclean: clean
	/bin/rm -f $(BIN)

re: fclean all