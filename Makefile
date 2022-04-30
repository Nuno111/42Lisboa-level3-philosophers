NAME = philo

CC = gcc

RM = rm -rf

ERR_FLAGS = -Wall -Wextra #-Werror

DEBUG_FLAGS = -g -fsanitize=address

DEP_FLAGS = -I. -pthread

LIB = philosophers.h

SRC = ${wildcard *.c}

all: ${NAME} 

${NAME}: ${LIB} ${SRC}
	${CC} ${ERR_FLAGS} ${DEBUG_FLAGS} ${DEP_FLAGS} ${SRC} -o $@

basic: ${NAME} 
	./${NAME} 5 800 200 200

large: ${NAME} 
	./${NAME} 80 800 200 200

leaks: ${NAME} 
	valgrind ./${NAME} 2 800 200 200

clean:
	$(RM) $(NAME) *.dSYM

fclean: clean

re: fclean all

.PHONY: all clean fclean re 
