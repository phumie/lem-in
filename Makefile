# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/04 09:42:40 by pnevhuta          #+#    #+#              #
#    Updated: 2017/12/04 09:42:48 by pnevhuta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = lemin.c error_check.c additions.c manage_errors.c creation.c\
	  farm_transformation.c farm_destruction.c ant_transportation.c\
	  tools.c tools2.c get_paths.c sort_paths.c creation2.c

FLAGS = gcc -Wall -Wextra -Werror 

LIBFT = libft/libft.a

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	$(FLAGS) -o $(NAME) $(SRC) $(LIBFT)

clean:
	make -C libft/ clean

fclean:
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all clean
