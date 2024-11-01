# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 12:42:23 by drubio-m          #+#    #+#              #
#    Updated: 2024/11/01 18:36:51 by drubio-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Animals
SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp

CXX = c++
RM = rm -f
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address -I/usr/local/opt/readline/include

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:	
		@$(RM) $(OBJS)


fclean:	clean
		@$(RM) $(NAME)

re:	fclean all
			
.PHONY: all clean fclean re