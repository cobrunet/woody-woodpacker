.PHONY: all clean fclean re

NAME = woody

CC = gcc

SRC_PATH = ./src/
SRC_NAME = woody.c handle.c

OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)

INC_PATH = ./inc/

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@echo "\033[36mWOODY:\033[0m [\033[35mCompilation:\033[0m\033[32m $@\033[0m]"
	@$(CC) -o $@ -c $< $(CFLAGS) $(INC)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^ $(INC)
	@echo "[\033[36m-------------------------------------\033[0m]"
	@echo "[\033[36m------------- WOODY - OK ------------\033[0m]"
	@echo "[\033[36m-------------------------------------\033[0m]"

clean:
	@rm -rf $(OBJ_PATH)
	@echo "[\033[31mSuppression des .o\033[0m]"

fclean: clean
	@rm -f $(NAME)
	@echo "[\033[31mSuppression de \033[36m$(NAME)\033[0m\033[0m]"

re: fclean clean
