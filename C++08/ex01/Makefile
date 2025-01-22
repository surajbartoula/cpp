# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 11:02:10 by sbartoul          #+#    #+#              #
#    Updated: 2025/01/22 11:10:35 by sbartoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = span

SRC = main.cpp Span.cpp

OBJS = $(SRC:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

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
