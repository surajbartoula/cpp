# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 10:53:05 by sbartoul          #+#    #+#              #
#    Updated: 2024/11/06 10:22:48 by sbartoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animal

SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp

OBJS = $(SRC:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow

all: $(NAME)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
