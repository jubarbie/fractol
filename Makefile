# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jubarbie <jubarbie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/30 16:51:35 by jubarbie          #+#    #+#              #
#    Updated: 2016/05/30 17:59:48 by jubarbie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS= -ILibs/libft -ILibs/libmlx -IIncludes -Wall -Wextra -Werror
SRC=	Sources/fractol.c	\
		Sources/init.c		\
		Sources/error.c		\
		Sources/display.c	\
		Sources/options.c	\
		Sources/events.c	\
		Sources/fractales.c
OBJ=$(SRC:.c=.o)
NAME=fractol

$(NAME): $(OBJ)
	@make -C Libs/libft
	@make -C Libs/libmlx
	@$(CC) -LLibs/libft/ -lft -LLibs/libmlx/ -lmlx -framework OpenGL -framework AppKit -framework Opencl -o $@ $^
	@echo "\033[32m[OK]\033[0m fractol created"

all: $(NAME)
	
%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@make clean -C Libs/libft
	@make clean -C Libs/libmlx
	@rm -rf $(OBJ)
	@echo "\033[32m[OK]\033[0m object files deleted"

fclean: clean
	@make fclean -C Libs/libft
	@rm -rf $(NAME)
	@echo "\033[32m[OK]\033[0m fractol deleted"

re: fclean all
