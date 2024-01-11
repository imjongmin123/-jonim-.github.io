# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonim <jonim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/08 12:39:28 by jonim             #+#    #+#              #
#    Updated: 2023/09/15 18:02:47 by jonim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MEGAPHONE
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
SRC_FILES = megaphone.cpp
SRC_OBJ = $(SRC_FILES:.cpp=.o)
all: $(NAME)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<
$(NAME): $(SRC_OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRC_OBJ)
clean:
	$(RM) $(SRC_OBJ)
fclean:
	make clean
	$(RM) $(NAME)
re:
	make fclean
	make all
.PHONY: all clean fclean re