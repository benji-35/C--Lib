##
## EPITECH PROJECT, 2022
## C++-Lib
## File description:
## Makefile
##

INCLUDES	=	-I string/													\
				-I exceptions/												\
				-I list/													\
				-I text/													\
				-I shared_ptr/												\
				-I unique_ptr/												\

LIBS	=	-lcriterion

TESTS	=	tests/

SRC	=	$(TESTS)test.cpp

OBJ	=	$(SRC:.cpp=.o)

BIN_NAME	=	run_test

%.o: %.cpp
	@echo "$(GAME_NAME) > [CPP: $<]"
	@g++ -c $< $(INCLUDES) -o $@

all:	tests

tests:	$(OBJ)
	@g++ -o $(BIN_NAME) $(OBJ) $(INCLUDES) $(LIBS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(BIN_NAME)

re:	fclean all
