# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 12:39:58 by nsaraiva          #+#    #+#              #
#    Updated: 2025/09/06 14:57:38 by nsaraiva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c
SRC += src/ft_utils.c src/ft_getters.c
OBJ = $(SRC:.c=.o)

LIBFT = includes/libft 
PRINTF = includes/ft_printf

CC = cc
CCFLAGS = -Wall -Wextra -Werror -Iheader -g
LIBRARIES = -L$(LIBFT) -lft -L$(PRINTF) -lftprintf
NAME = pipex

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT) all
	$(MAKE) -C $(PRINTF) all
	$(CC) -Iheader -g $(OBJ) $(LIBRARIES) -o $(NAME)

%.o: %.c
	$(CC) -Iheader -g -c $< -o $@

clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(PRINTF) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(PRINTF) fclean

re: fclean all

.PHONY: all clean fclean re
