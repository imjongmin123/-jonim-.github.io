NAME = a.out
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC_FILES = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp ICharacter.cpp \
			IMateriaSource.cpp MateriaSource.cpp Floor.cpp
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