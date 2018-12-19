NAME	= data
CXX		= g++
FLAGS	= -Wall -Wextra -Werror
SRC		= Data.cpp main.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

%.o:    %.cpp
		$(CXX) -o $@ -c $< $(FLAGS)

$(NAME): $(OBJ)
		$(CXX) -o $(NAME) $(OBJ) $(FLAGS)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
