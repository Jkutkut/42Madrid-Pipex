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
HEADERS		=	-I ./include -I ./libft/include
COMPILE		=	$(CC) $(FLAGS)

# Code variables

LIB			=	libft/libft.a

NAME		=	pipex

SRC_FILES	=	check_arg.c \
				close_fd.c \
				close_fds.c \
				end.c \
				exe_cmd.c \
				get_path.c \
				get_path_array.c \
				heredoc.c \
				init_input.c \
				init_output.c \
				init_pipes.c \
				init_pipex.c \
				make_path.c \
				pipex.c \
				use_pipe.c \
				waitpids.c

SRCS		=	${SRC_FILES:src/%=%}

OBJS		=	${SRCS:%.c=bin/%.o}

# Bonus
BONUS_SRCS	=	check_arg_bonus.c \
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

B_SRCS		=	${BONUS_SRCS:%=bonus/%}


# Makefile logic
all: $(NAME)

bonus:
	make all SRCS="${B_SRCS}"


# DEBUG
OS	=	$(shell uname -s)
ifeq ($(OS),Linux)
debug: FLAGS += -pedantic -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=bounds -fsanitize=null -g3
endif
ifeq ($(OS),Darwin)
debug: FLAGS += -fsanitize=address -g3
endif
debug: $(NAME)

$(NAME):	$(LIB) $(OBJS)
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
