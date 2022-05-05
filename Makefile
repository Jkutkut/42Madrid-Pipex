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
LIB_CC		=	ar rcT
CC			=	gcc
FLAGS		=	-Wall -Wextra #-Werror
#HEADERS		=	-I ./include  ./src/libft  ./src/ft_printf  ./src/get_next_line
HEADERS		=	-I ./include -I ./src/libft -I ./src/ft_printf/include -I ./src/get_next_line/include
COMPILE		=	$(CC) $(FLAGS) $(HEADERS)

# Code variables

NAME		=	pipex

LIBFT		=	src/libft/libft.a
PRINTF		=	src/ft_printf/libftprintf.a
GNL			=	src/get_next_line/gnl.a
LIB			=	$(LIBFT) $(PRINTF) $(GNL)

TOOLS		=	close_pipe.c \
				close_pipes.c \
				end.c \
				end_error_file.c \
				free_end.c \
				get_path.c \
				get_path_array.c \
				heredoc.c \
				init_pipex.c \
				use_pipe.c

SRCS		=	$(NAME).c \
				${TOOLS:%=tools/%}

OBJS		=	${SRCS:%.c=bin/%.o}

# Bonus
# BONUS_SRCS	=	
# BONUS_OBJS	=	${BONUS_SRCS:%.c=bin/%.o}


# Makefile logic
all: $(NAME)

# DEBUG
ifeq ($(UNAME_S),Linux)
debug: FLAGS += -pedantic -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=bounds -fsanitize=null -g3
endif
ifeq ($(UNAME_S),Darwin)
debug: FLAGS += -pedantic -fsanitize=address -g3
endif
debug: $(NAME)

re: fclean all

$(NAME):	$(LIB) $(OBJS)
	@echo "\n${TITLE}Compiling ${YELLOW}$(NAME)${NC}\c"
	@$(COMPILE) $(OBJS) $(LIB) -o $(NAME)
	@echo "${LGREEN} [OK]${NC}\n"

bin/%.o: src/%.c
	@echo "- ${TITLE}Compiling${NC} $< -> $@\c"
	@mkdir -p $(dir $@)
	@$(COMPILE) -c $< -o $@ $(DEBUG)
	@echo "${GREEN} [OK]${NC}"

%.a:
	@make $(dir $@)Makefile -s
	@echo "${TITLE}Compiling${NC} ${YELLOW}${@:src/%=%}${NC}"
	@make -C $(dir $@) BIN="../../bin/$(dir ${@:src/%=%})"

%/Makefile:
	@echo "${TITLE}Loading submodules${NC}"
	@git submodule update --init --recursive
	@echo "${TITLE}Submodules loaded ${LGREEN}[OK]${NC}"

clean:
	@echo "${LRED}Cleaning ${NC}libft"
	@make -C $(dir $(LIBFT)) fclean BIN="../../bin/libft"
	@echo "${LRED}Cleaning ${NC}ft_printf"
	@make -C $(dir $(PRINTF)) fclean BIN="../../bin/ft_printf"
	@echo "${LRED}Cleaning ${NC}binaries\c"
	@rm -rf bin
	@echo "${LGREEN} [OK]${NC}"

fclean: clean
	@echo "${LRED}Cleaning ${NC}$(NAME) and $(BONUS_NAME)\c"
	@rm -f $(NAME) $(BONUS_NAME)
	@echo "${LGREEN} [OK]${NC}"

.PHONY: all re fclean clean
