NAME = philosophers

CC = gcc

ERR_FLAGS = -Wall -Wextra #-Werror

DEBUG_FLAGS = -g -fsanitize=address

DEP_FLAGS = -I. -Ilibft -lpthread

LIBFT = libft/libft.a

LIB = philosophers.h

SRC = ${wildcard *.c}

all: libft philosophers 

libft:
	cd libft && ${MAKE}

philosophers: ${LIB} ${SRC}
	${CC} ${ERR_FLAGS} ${DEBUG_FLAGS} ${DEP_FLAGS} ${SRC} ${LIBFT} -o $@

clean:
	rm -rf philosophers *.dSYM

fclean: clean
	cd libft && ${MAKE} fclean

re: fclean all

.PHONY: all clean fclean re libft 
