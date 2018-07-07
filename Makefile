# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/26 16:04:15 by opavliuk          #+#    #+#              #
#    Updated: 2018/06/08 13:37:57 by opavliuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc 
CFLAGS=-Wall -Werror -Wextra
SRC=./fractolsrc/choose_fractol.c \
	./fractolsrc/draw_fractol.c \
	./fractolsrc/fractols.c \
	./fractolsrc/fractols2.c \
	./fractolsrc/hook.c \
	./fractolsrc/main.c 
	
OBJ=$(SRC:.c=.o)
LIB = libft/libft.a
NAME=fractol

all: lib $(NAME)

%.o: %.c
	@ $(CC) $(CFLAGS) -o $@ -c $< -I ./

$(NAME): $(OBJ) $(LIB)
	@ $(CC) $(CFLAGS) $(OBJ) $(LIB) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -o $(NAME) -I /usr/local/include 
	@ printf "\e[37;1m[Program \e[34;1mfractol \e[37;1mis \e[32;1mREADY TO SHOW!\e[37;1m]\e[0m🎅🏾🤙🏾🥃\n"

lib:
	@ printf "\e[32;1mCompiling libft.a ...\n"
	@ make -C libft/
	@ printf "\n\e[32;1mCompiling fractol ...\n"

clean:
	@ rm -f $(OBJ)
	@ make clean -C libft/
	@ printf "\e[37;1m[Directories \e[33;1mfractolsrc/ \e[37;1m&& \e[33;1mlibft/ \e[37;1mis \e[32;1mCLEAN!\e[37;1m]\e[0m🗑\n"

fclean: clean
	@ rm -f $(NAME)
	@ make fclean -C libft/
	@ printf "\e[37;1m[Directories \e[33;1mfractol/ \e[37;1m&& \e[33;1mlibft/ \e[37;1mis \e[32;1mFCLEAN!\e[37;1m]\e[0m🗑\n"

re: fclean all

.PHONY: all, clean, fclean, re
