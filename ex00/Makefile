NAME = easyfind
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	${RM} $(OBJS)

fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY: all clean fclean re

.PHONY: valgrind
valgrind: all
	valgrind -q --leak-check=full ./$(NAME)