# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 12:42:23 by drubio-m          #+#    #+#              #
#    Updated: 2025/05/05 00:10:30 by drubio-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -DDEBUG
 
SRCS = main.cpp PmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compilando programa..."
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	@echo "Limpiando objetos..."
	@rm -f $(OBJS)

fclean: clean
	@echo "Eliminando ejecutable..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
