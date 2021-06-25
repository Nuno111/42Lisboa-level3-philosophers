NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIB = libft.h

OPT = -c -g

LIBOPT = ar rcs

SRC = ${wildcard *.c}

DST = $(SRC:.c=.o)

$(NAME) : $(DST)
	$(LIBOPT) $@ $^

%.o : %.c $(LIB)
	$(CC) $(OPT) $(CFLAGS) $<

all : $(NAME)

clean :
	rm -f $(DST)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
