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
FLAGS		=	-Wall -Wextra #-Werror
HEADERS		=	-I ./include -I ./src/libft/include
COMPILE		=	$(CC) $(FLAGS) $(HEADERS)

# Code variables

NAME		=	pipex

LIBFT		=	src/libft/libft.a
PRINTF		=	src/libft/libftprintf.a
GNL			=	src/libft/get_next_line.a
LIB			=	$(LIBFT) $(PRINTF) $(GNL)

TOOLS		=	close_pipe.c \
				close_pipes.c \
				end_error_file.c \
				end.c \
				free_array.c \
				free_end.c \
				get_path.c \
				get_path_array.c \
				heredoc.c \
				init_input.c \
				init_output.c \
				init_pipes.c \
				init_pipex.c \
				make_path.c \
				use_pipe.c

SRCS		=	$(NAME).c \
				${TOOLS:%=tools/%}

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

$(NAME):	$(LIB) $(OBJS)
	@echo "\n${TITLE}Compiling ${YELLOW}$(NAME)${NC}\c"
	@$(COMPILE) $(OBJS) $(LIB) -o $(NAME)
	@echo "${LGREEN} [OK]${NC}\n"

bin/%.o: src/%.c
	@echo "- ${TITLE}Compiling${NC} $< -> $@\c"
	@mkdir -p $(dir $@)
	@$(COMPILE) -c $< -o $@ $(DEBUG)
	@echo "${GREEN} [OK]${NC}"

$(LIBFT):
	@echo "${TITLE}Compiling${NC} ${YELLOW}${@:src/%=%}${NC}"
	@make -C $(dir $@) BIN="../../bin/"

clean: # TODO compile libft
	@#echo "${LRED}Cleaning ${NC}libft, printf and gnl"
	@#make -C $(dir $(LIBFT)) fclean BIN="../../bin/"
	@echo "${LRED}Cleaning ${NC}binaries\c"
	@rm -rf bin
	@echo "${LGREEN} [OK]${NC}"

fclean: clean
	@echo "${LRED}Cleaning ${NC}$(NAME)\c"
	@rm -f $(NAME) $(BONUS_NAME)
	@echo "${LGREEN} [OK]${NC}"

re: fclean all
	@# make fclean
	@# make all

.PHONY: all re fclean clean
