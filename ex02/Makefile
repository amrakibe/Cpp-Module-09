NAME = PmergeMe

CC = c++
FLAG = -Wall -Wextra -Werror -std=c++98
RM = rm -fr
src = main.cpp PmergeMe.cpp
OBJ = $(src:.cpp=.o)

$(NAME) : $(OBJ)
	@$(CC) $(FLAG) $(OBJ) -o $(NAME)
	@echo "making successfully" $(NAME)

all : $(NAME)

%.o:%.cpp PmergeMe.hpp
	@$(CC) $(FLAG) -c $< -o $@
	@echo "successfully making $(NAME)"

clean:
	@$(RM) $(OBJ)
	@echo "successfully remove $(OBJ)"

fclean: clean
	@$(RM) $(NAME)
	@echo "successfully remove $(NAME)"

re: fclean all
