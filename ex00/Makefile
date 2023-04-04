NAME = btc

CC = c++
FLAG = -Wall -Wextra -Werror -std=c++98 -g
RM = rm -fr
src = main.cpp BitcoinExchange.cpp 

OBJ = $(src:.cpp=.o)

$(NAME) : $(OBJ)
	@$(CC) $(FLAG) $(OBJ) -o $(NAME)
	@echo "making successfully" $(NAME)

all : $(NAME)

%.o:%.cpp BitcoinExchange.hpp
	@$(CC) $(FLAG) -c $< -o $@
	@echo "successfully making $(NAME)"

clean:
	@$(RM) $(OBJ)
	@echo "successfully remove $(OBJ)"

fclean: clean
	@$(RM) $(NAME)
	@echo "successfully remove $(NAME)"

re: fclean all
