# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/03 16:06:24 by cdonaire          #+#    #+#              #
#    Updated: 2025/10/03 16:06:26 by cdonaire         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
CXFLAGS = -lXext -lX11 -lm

#Libft
LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

#Includes
INC			= -I ./includes/\
			  -I ./libft/\

#Sources
SRC_PATH	= 	src/
SRC			=	cal_costs.c \
				create_nodes.c \
				move_nodes.c \
				optimization.c \
				parser.c \
				printers.c \
				push_swap_utils.c \
				push_swap.c \
				sort_functions.c \
				sort_little.c \
				sorter.c \

SRCS		= $(addprefix $(SRC_PATH), $(SRC))

#Objects
OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

#Vanity

RED    = \033[0;31m
GREEN  = \033[0;32m
YELLOW = \033[0;33m
BLUE   = \033[0;34m
CYAN   = \033[0;36m
RESET  = \033[0m

#ACTIONS
all: $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH)	:
	@mkdir $(OBJ_PATH)

$(LIBFT)	:
	@echo "$(RED)Compiling LibFT...$(YELLOW)"
	@make -sC $(LIBFT_PATH)

$(NAME) : $(OBJS)
		@echo "$(RED)Compiling Push_Swap...$(YELLOW)"
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(CXFLAGS)
		@echo "$(GREEN)Push_Swap Ready!$(RESET)"

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LIBFT_PATH)
	@echo "$(GREEN)All objects have been removed!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)
	@echo "$(GREEN)All has been cleaned$(RESET)"

re: fclean all

bonus: all
			
.PHONY = all, re, bonus, clean, fclean 
.DEFAULT_GOAL = all
