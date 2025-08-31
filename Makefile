# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 12:39:58 by nsaraiva          #+#    #+#              #
#    Updated: 2025/08/20 14:49:35 by nsaraiva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c
SRC += src/ft_utils.c src/ft_getters.c
OBJ = $(SRC:.c=.o)

LIBFT = includes/libft 
LIBFT_A = $(addprefix $(LIBFT)/, libft.a)
PRINTF = includes/ft_printf
PRINTF_A = $(addprefix $(PRINTF)/, ft_printf.a)

CC = cc
CCFLAGS = -Wall -Wextra -Werror -Iheader -g
LIBRARIES = -L$(LIBFT) -lft -L$(PRINTF) -lftprintf
NAME = pipex

all: $(LIBFT_A) $(PRINTF_A) $(NAME)

# $(NAME): $(OBJ)
# 	$(CC) $(CCFLAGS) $(OBJ) $(LIBRARIES) -o $(NAME)
$(NAME): $(OBJ)
	$(CC) -Iheader -g $(OBJ) $(LIBRARIES) -o $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT) all
$(PRINTF_A):
	$(MAKE) -C $(PRINTF) all

# %.o: %.c
# 	$(CC) $(CCFLAGS) -c $< -o $@
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
