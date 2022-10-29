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
FLAGS		=	-Wall -Wextra -Werror
COMPILE_TYPE=	mandatory
HEADERS		=	-I ./include/${COMPILE_TYPE}/ -I ./libft/include/
COMPILE		=	$(CC) $(FLAGS)

# DEBUG
# OS	=	$(shell uname -s)
# ifeq ($(OS),Linux)
# debug: FLAGS += -pedantic -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=bounds -fsanitize=null -g3
# endif
# ifeq ($(OS),Darwin)
# debug: FLAGS += -fsanitize=address -g3
# endif
# debug: $(NAME)

# Code variables

LIB			=	libft/libft.a

NAME		=	pipex

MANDATORY	=	pipex.c \
				init_pipex.c \
				end.c
				# TODO
				# TODO sort files

SRCS		=	${MANDATORY:%=src/mandatory/%}

OBJS		=	${SRCS:src/%.c=bin/%.o}

# Bonus
BONUS		=	check_arg_bonus.c \
				close_fd_bonus.c \
				close_fds_bonus.c \
				end_bonus.c \
				exe_cmd_bonus.c \
				get_path_array_bonus.c \
				get_path_bonus.c \
				heredoc_bonus.c \
				init_input_bonus.c \
				init_output_bonus.c \
				init_pipes_bonus.c \
				init_pipex_bonus.c \
				make_path_bonus.c \
				pipex_bonus.c \
				use_pipe_bonus.c \
				waitpids_bonus.c

BONUS_SRCS		=	${BONUS:%=src/bonus/%}


# Makefile logic
all: mandatory

mandatory: $(NAME)

bonus:
	@make all SRCS="${BONUS_SRCS}" COMPILE_TYPE="bonus"

$(NAME):	$(LIB) $(OBJS)
	@echo "\n${TITLE}Compiling ${YELLOW}$(NAME)${NC} (${COMPILE_TYPE} version)\c"
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

clean:
	@echo "${LRED}Cleaning ${NC}binaries\c"
	@rm -rf bin
	@echo "${LGREEN} [OK]${NC}"
	@echo "${LRED}Cleaning ${NC}libft"
	@make fclean -C ./libft/


fclean: clean
	@echo "${LRED}Cleaning ${NC}$(NAME)\c"
	@rm -f $(NAME) $(BONUS_NAME)
	@echo "${LGREEN} [OK]${NC}\n"

re: fclean all
	@# make fclean
	@# make all

.PHONY: all re fclean clean
