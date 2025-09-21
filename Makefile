# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 12:39:58 by nsaraiva          #+#    #+#              #
#    Updated: 2025/09/17 22:26:49 by nsaraiva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c
SRC += src/ft_utils.c src/ft_getters.c src/ft_errors.c src/ft_count_words.c src/ft_get_cmd.c
OBJ = $(SRC:.c=.o)

SRC_BONUS = main_bonus.c
SRC_BONUS += src/ft_utils.c src/ft_getters.c src/ft_errors.c src/ft_count_words.c src/ft_get_cmd.c
SRC_BONUS += src_bonus/ft_utils_bonus.c src_bonus/ft_here_doc.c
SRC_BONUS += src_bonus/get_fd_file_b.c src_bonus/cmd_not_found.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

LIBFT = includes/libft 
PRINTF = includes/ft_printf
GNL = includes/get_next_line

CC = cc
CCFLAGS = -Wall -Wextra -Werror -Iheader -g
LIBRARIES = -L$(LIBFT) -lft -L$(PRINTF) -lftprintf
NAME = pipex
BONUS = .bonus

all: $(NAME)
bonus: $(BONUS)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT) all
	$(MAKE) -C $(PRINTF) all
	rm -rf .bonus
	$(CC) -Iheader -g $(OBJ) $(LIBRARIES) -o $(NAME)

$(BONUS): $(OBJ_BONUS)
	$(MAKE) -C $(LIBFT) all
	$(MAKE) -C $(PRINTF) all
	$(MAKE) -C $(GNL) all
	touch .bonus
	rm -rf main.o
	$(CC) -Iheader -g $(OBJ_BONUS) $(LIBRARIES) -L$(GNL) -lget -o $(NAME)

%.o: %.c
	$(CC) -Iheader -g -c $< -o $@

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)
	rm -rf .bonus
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(PRINTF) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BONUS)
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(PRINTF) fclean

re: fclean all

.PHONY: all clean fclean re bonus
