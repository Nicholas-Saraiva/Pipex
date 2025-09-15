# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/23 11:38:26 by nsaraiva          #+#    #+#              #
#    Updated: 2025/07/11 19:14:50 by nsaraiva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = get_next_line.c get_next_line_utils.c 
OBJ = $(SRC:.c=.o)

NAME = libget.a

all : $(NAME)

$(NAME) : $(OBJ) 
	ar -rcs $(NAME) $(OBJ)	
$(OBJ) : $(SRC)
	cc -c -g -Wall -Wextra -Werror $(SRC)	

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
