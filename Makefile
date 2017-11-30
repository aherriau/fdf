# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherriau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/17 10:05:05 by aherriau          #+#    #+#              #
#    Updated: 2017/11/30 23:29:52 by aherriau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

export CC = cc

export CFLAGS = -Wall -Wextra -Werror

NAME = fdf

SRC = ./srcs/main.c ./srcs/ft_init_mlx.c ./srcs/ft_key_hook.c\
	  ./srcs/ft_mouse_hook.c ./srcs/ft_mouse_hook_2.c ./srcs/ft_mouse_hook_3.c\
	  ./srcs/ft_read_input.c ./srcs/ft_process_fdf.c ./srcs/ft_axo.c\
	  ./srcs/ft_obli.c ./srcs/ft_curvi.c ./srcs/ft_image.c ./srcs/ft_image_2.c\
	  ./srcs/ft_image_3.c ./srcs/ft_image_tools.c ./srcs/ft_image_tools_2.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft

red=`tput setaf 1`
green=`tput setaf 2`
reset=`tput sgr0`


all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) -o $@ $^ -L $(LIBFT_DIR) -lft -lmlx -framework OpenGL -framework AppKit
	@echo "$(green)Compilation finished: $(NAME)$(reset)"

%.o: %.c ./srcs/fdf.h
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean fclean

clean:
	@$(MAKE) $@ -C $(LIBFT_DIR)
	@rm -f $(OBJ)
	@echo "$(green)Object files deleted: $(NAME)$(reset)"

fclean: clean
	@$(MAKE) $@ -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "$(green)Executable file deleted: $(NAME)$(reset)"

re: fclean all
