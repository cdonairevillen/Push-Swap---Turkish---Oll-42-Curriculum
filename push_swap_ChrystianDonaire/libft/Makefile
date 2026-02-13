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

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
NAME = libft.a
SOURCE = functions/Transform/ft_atoi.c \
		functions/Memory/ft_bzero.c \
		functions/Malloc/ft_calloc.c \
		functions/Check/ft_isalnum.c \
		functions/Check/ft_isalpha.c \
		functions/Check/ft_isascii.c \
		functions/Check/ft_isdigit.c \
		functions/Check/ft_isprint.c \
		functions/Malloc/ft_itoa.c \
		functions/Memory/ft_memchr.c \
		functions/Memory/ft_memcmp.c \
		functions/Memory/ft_memcpy.c \
		functions/Memory/ft_memmove.c \
		functions/Memory/ft_memset.c \
		functions/Write/ft_putchar_fd.c \
		functions/Write/ft_putendl_fd.c \
		functions/Write/ft_putnbr_fd.c \
		functions/Write/ft_putstr_fd.c \
		functions/Malloc/ft_split.c \
		functions/String/ft_strchr.c \
		functions/Malloc/ft_strdup.c \
		functions/Transform/ft_striteri.c \
		functions/Malloc/ft_strjoin.c \
		functions/String/ft_strlcat.c \
		functions/String/ft_strlcpy.c \
		functions/String/ft_strlen.c \
		functions/Malloc/ft_strmapi.c \
		functions/String/ft_strncmp.c \
		functions/String/ft_strnstr.c \
		functions/String/ft_strrchr.c \
		functions/Malloc/ft_strtrim.c \
		functions/Malloc/ft_substr.c \
		functions/Transform/ft_tolower.c \
		functions/Transform/ft_toupper.c \
		functions/ft_printf/ft_printf.c \
		functions/ft_printf/ft_apply_sign.c \
		functions/ft_printf/ft_parse_format.c \
		functions/ft_printf/ft_print_format.c \
		functions/ft_printf/ft_printf_utils.c \
		functions/ft_printf/ft_write_chars.c \
		functions/ft_printf/ft_write_pointer.c \
		functions/ft_printf/ft_writenbr_base.c \
		funcions/GNL/get_next_line_bonus.c \
		

SOURCEBONUS =  functions/List/ft_lstadd_back_bonus.c \
			functions/List/ft_lstadd_front_bonus.c \
			functions/List/ft_lstclear_bonus.c \
			functions/List/ft_lstdelone_bonus.c \
			functions/List/ft_lstiter_bonus.c \
			functions/List/ft_lstlast_bonus.c \
			functions/List/ft_lstmap_bonus.c \
			functions/List/ft_lstnew_bonus.c \
			functions/List/ft_lstsize_bonus.c

OBJ = $(SOURCE:.c=.o)
OBJBONUS = $(SOURCEBONUS:.c=.o)
INCLUDE = libft.h
RM = rm -f

all: $(NAME)

$(NAME) : $(OBJ)  
		ar rcs $(NAME) $(OBJ)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJBONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJ) $(OBJBONUS)
	ar rcs $(NAME) $(OBJ) $(OBJBONUS)
			
.PHONY = all, clean, fclean, re, bonus
.DEFAULT_GOAL = all
