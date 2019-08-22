# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/04 16:08:24 by fgeruss           #+#    #+#              #
#    Updated: 2019/08/22 16:20:15 by fgeruss          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OUTPUT = testing

INCLUDE = -I includes/

FLAGS = -Wall -Wextra -Werror

LIB_FILES = ft_atoi.c ft_putchar.c ft_strdup.c \
			ft_putstr.c ft_strlen.c ft_itoa.c \
			ft_strsub.c ft_isdigit.c ft_putnbr.c \
			ft_bzero.c ft_memset.c ft_strchr.c \
			ft_strnew_float.c ft_strjoin.c \
			ft_strcmp.c

SRC_FILES = ft_printf.c attribute.c \
            printing.c print_s.c print_c.c \
            print_d.c initialize.c digits_nbr.c \
            print_o.c print_x.c print_u.c \
            print_f1.c print_e.c print_e_help.c \
            print_e_other.c print_e_other_1.c \
            print_e_other_2.c print_e_presicion.c \
            for_norm.c

SRC = $(addprefix src/, $(SRC_FILES))
LIBFT = $(addprefix libft/, $(LIB_FILES))

OBJ = $(SRC_FILES:.c=.o) $(LIB_FILES:.c=.o)

all: $(NAME)

$(NAME):
	@echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compiling... Wait a sec. \(°□°)/"
	@gcc -c $(FLAGS) $(SRC) $(LIBFT) $(INCLUDE)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "(•̀ᴗ•́)و $(NAME) generated!".
	@gcc -o $(OUTPUT) $(OBJ) -I includes/ -L libft/

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(OUTPUT)


re: fclean all
