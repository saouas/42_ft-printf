# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ratin <ratin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 18:46:26 by ratin             #+#    #+#              #
#    Updated: 2019/01/30 20:05:10 by ratin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_PATH = src
OBJ_PATH = obj
INC_PATH = includes
LIB_PATH = libft

SRC_NAME =	ft_printf.c \
			ft_printf_tabinit.c \
			func_wrapper.c \
			func_wrapper2.c \
			func_wrapper3.c \
			func_float.c \
			parse.c \
			field.c \
			utility.c \
			flag.c \
			ft_find_param.c \
			ft_isfloat.c \
			flag2.c \
			w_ft_putpointer.c \
			w_ft_put_d.c \
			w_ft_putconverted.c \
			ft_put_conversion.c \
			ft_map.c \
			ft_map2.c \
			len_function.c \
			ft_unside_len.c \
			w_ft_put_long.c \
			ft_llprint_space.c \
			ft_give_conversion.c \
			ft_strlen.c ft_strdup.c ft_atoi.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_strcat.c ft_strcmp.c \
			ft_strcpy.c ft_tolower.c ft_toupper.c ft_strncmp.c ft_strncat.c \
			ft_strlcat.c ft_strncpy.c ft_strchr.c ft_strrchr.c ft_strstr.c \
			ft_strnstr.c ft_memcmp.c ft_memchr.c ft_memmove.c ft_memset.c \
			ft_bzero.c ft_memcpy.c ft_memccpy.c ft_putchar.c ft_putstr.c \
			ft_putnbr.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr.c \
			ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c \
			ft_itoa.c ft_strsplit.c ft_strtrim.c ft_strjoin.c ft_strsub.c \
			ft_strequ.c ft_strnequ.c ft_strmapi.c ft_strmap.c ft_striteri.c \
			ft_striter.c ft_strclr.c ft_strdel.c ft_strnew.c ft_memdel.c \
			ft_memalloc.c ft_lstadd.c ft_lstiter.c ft_lstnew.c ft_lstdelone.c \
			ft_lstdel.c ft_lstmap.c ft_isblank.c ft_str_is_alpha.c ft_str_is_printable.c \
			ft_str_is_numeric.c ft_str_is_lowercase.c ft_str_is_uppercase.c ft_strndup.c \
			get_next_line.c ft_strjoin_free.c ft_print_words_tables.c ft_strdjoin.c \
			ft_putunbr.c ft_convert_base.c ft_ulong_itoa.c ft_nbrlen.c ft_pow.c ft_isthischar.c\
			ft_realloc.c ft_reverse_str.c ft_atoi_base.c get_nb.c ft_abs.c ft_litoa.c \
			ft_ullatoi.c ft_putullnbr.c ft_ul_convert_base.c atoul.c ft_lutoa.c	\
			ft_putcount.c

OBJECT_NAME = $(SRC_NAME:.c=.o)
INC_NAME = ft_printf.h

LIB = libftprintf.a

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(SRC_NAME:.c=.o))

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror 

all: obj $(NAME)

$(NAME): $(OBJ)
	ar rc $(LIB) $(OBJ)
	ranlib $(NAME)
#	$(CC) $(FLAGS) -o $@ $^ -lm
# RAJOUTER LES CFLAGS dans la compilation des objects

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC_PATH)/$(INC_NAME)
	$(CC) $(CFLAGS) -o $@ -c $<

obj:
	mkdir -p obj

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(LIB)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)/$(NAME).h
	norminette libft/../includes/libft.h

.PHONY: all fclean clean re norme