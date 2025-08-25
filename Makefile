# Project name
NAME		= Calculator

CXX			= g++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic
MAKEFLAGS	+= --no-print-directory -s

SRCS		= main.cpp helperFunctions.cpp printASCIIArt.cpp
OBJS 		= $(SRCS:.cpp=.o)

all: $(NAME)
	@echo "\033[38;5;70mProgram ready to use.\033[0m"

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@echo "\033[38;5;130mObject files removed.\033[0m"

fclean: clean
	rm -f $(NAME)
	@echo "\033[38;5;130mFully cleaned up.\033[0m"

re: fclean all

.PHONY: all clean fclean re
