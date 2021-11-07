NAME = philosophers

CC = gcc

RM = rm -rf

ERR_FLAGS = -Wall -Wextra #-Werror

DEBUG_FLAGS = -g -fsanitize=address

DEP_FLAGS = -I. -lpthread

LIB = philosophers.h

SRC = ${wildcard *.c}

all: philosophers 

philosophers: ${LIB} ${SRC}
	${CC} ${ERR_FLAGS} ${DEBUG_FLAGS} ${DEP_FLAGS} ${SRC} -o $@

basic: philosophers
	./philosophers 5 800 200 200
clean:
	$(RM) $(NAME) *.dSYM

fclean: clean

re: fclean all

.PHONY: all clean fclean re 
