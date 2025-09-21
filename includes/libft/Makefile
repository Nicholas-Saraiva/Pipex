# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsaraiva <nsaraiva@student.42porto.com>   +#+  +:+       +#+          #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 12:36:01 by nsaraiva          #+#    #+#              #
#    Updated: 2025/07/11 19:15:01 by nsaraiva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_isalpha.c ft_isdigit.c  ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
			ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
			ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_substr.c  ft_strjoin.c ft_strdup.c \
			ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c\
			ft_putendl_fd.c ft_putnbr_fd.c ft_max.c

SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
			ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJ) 
	ar -rcs $(NAME) $(OBJ)	
$(OBJ) : $(SRC)
	cc -c -g -Wall -Wextra -Werror $(SRC)	

bonus : $(OBJ_BONUS)
	ar -rcs $(NAME) $(OBJ_BONUS)
$(OBJ_BONUS) : $(SRC_BONUS)
	cc -c -Wall -Wextra -Werror $(SRC_BONUS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
