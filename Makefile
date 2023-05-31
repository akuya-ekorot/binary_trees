# -*- Makefile -*-
CC = gcc
SRC = $(wildcard *.c) $(wildcard tests/*.c)
OBJ = $(SRC:.c=.o)
NAME = bin/binary_tree
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -pedantic

.PHONY: all clean oclean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	$(RM) $(OBJ)

oclean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all