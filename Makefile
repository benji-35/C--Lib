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
				-I map/														\
				-I file/													\

LIBS	=	-lcriterion

TESTS	=	tests/

SRC	=	$(TESTS)test.cpp					\
		$(TESTS)test_shared_ptr.cpp			\

OBJ	=	$(SRC:.cpp=.o)

BIN_NAME	=	run_test

%.o: %.cpp
	@echo "$(BIN_NAME) > [CPP: $<]"
	@g++ -c $< $(INCLUDES) -o $@

all:	tests

tests:	$(OBJ)
	@g++ -o $(BIN_NAME) $(OBJ) $(INCLUDES) $(LIBS)
	@g++ -o bin_test main_test.cpp -g $(INCLUDES) $(LIBS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(BIN_NAME)
	rm -f bin_test

re:	fclean all
