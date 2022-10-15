# Colors:
NC			=	\033[0m
LRED		=	\033[0;31m
GREEN		=	\033[0;32m
LRED		=	\033[1;31m
LGREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
LBLUE		=	\033[1;34m
TITLE		=	\033[38;5;33m

# Compile variables
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address # TODO remove sanitize
HEADERS		=	-I ./include -I ./libft/include/ -I ./gnl/include/
COMPILE		=	$(CC) $(FLAGS)

# Code variables

LIB			=	libft/libft.a gnl/gnl.a

NAME		=	pipex

TOOLS		=	$(wildcard src/*.c)

# TODO set the files in alph order.

#SRCS		=	${TOOLS:%=%}
SRCS		=	${TOOLS:src/%=%} \
				#$(NAME).c

OBJS		=	${SRCS:%.c=bin/%.o}

# Bonus
# BONUS_SRCS	=	
# BONUS_OBJS	=	${BONUS_SRCS:%.c=bin/%.o}


# Makefile logic
all: $(NAME)

bonus: all # TODO DEBUG


# DEBUG
OS	=	$(shell uname -s)
ifeq ($(OS),Linux)
debug: FLAGS += -pedantic -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=bounds -fsanitize=null -g3
endif
ifeq ($(OS),Darwin)
debug: FLAGS += -fsanitize=address -g3
endif
debug: $(NAME)

$(NAME):	$(OBJS) $(LIB)
	@echo "\n${TITLE}Compiling ${YELLOW}$(NAME)${NC}\c"
	@$(COMPILE) $(OBJS) $(HEADERS) $(LIB) -o $(NAME)
	@echo "${LGREEN} [OK]${NC}\n"

bin/%.o: src/%.c
	@echo "- ${TITLE}Compiling${NC} $< -> $@\c"
	@mkdir -p $(dir $@)
	@$(COMPILE) -c $< -o $@ $(HEADERS)
	@echo "${GREEN} [OK]${NC}"

libft/libft.a:
	@echo "- ${TITLE}Compiling${NC} libft"
	@make -C libft all

gnl/gnl.a:
	@echo "- ${TITLE}Compiling${NC} get_next_line"
	@make -C gnl all

clean:
	@echo "${LRED}Cleaning ${NC}binaries\c"
	@rm -rf bin
	@echo "${LGREEN} [OK]${NC}"
	@echo "${LRED}Cleaning ${NC}libft"
	@make fclean -C ./libft/
	@echo "${LRED}Cleaning ${NC}get_next_line"
	@make fclean -C ./gnl/


fclean: clean
	@echo "${LRED}Cleaning ${NC}$(NAME)\c"
	@rm -f $(NAME) $(BONUS_NAME)
	@echo "${LGREEN} [OK]${NC}\n"

re: fclean all
	@# make fclean
	@# make all

.PHONY: all re fclean clean
