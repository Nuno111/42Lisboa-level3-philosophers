NAME = philosophers

CC = gcc

ERR_FLAGS = -Wall -Wextra -Werror

DEBUG_FLAGS = -g -fsanitize=address

DEP_FLAGS = -I. -Ilibft

LIBFT = libft/libft.a

LIB = philosphers.h

SRC = ${wildcard *.c}

all: libft philosophers 

libft:
	cd libft && ${MAKE}

philosophers: ${LIB} ${SRC}
	${CC} ${ERR_FLAGS} ${DEBUG_FLAGS} ${DEP_FLAGS} ${SRC} ${LIBFT} -o $@

clean:
	rm -rf push_swap *.dSYM

fclean: clean
	cd libft && ${MAKE} fclean

re: fclean all

.PHONY: all clean fclean re libft
