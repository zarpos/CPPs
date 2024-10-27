# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 12:42:23 by drubio-m          #+#    #+#              #
#    Updated: 2024/10/27 09:26:02 by drubio-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Zombie
SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

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