NAME = push_swap

CFLAGS = -Wall -Wextra -Werror 

SRCS = align_stack.c \
	   init_stack.c \
	   print.c \
	   stack.c \
	   brute.c \
	   instruc.c \
	   state.c \
	   move.c \
	   main.c \
	   resolution.c \
	   param.c \
	   free.c \
	   fonction_suite.c \
	   oper.c \
	   brute_ope.c \
	   utils.c  

SRCO = $(SRCS:.c=.o)

CC = gcc

RM = rm -f

$(NAME):
	$(CC) $(CFLAGS)  $(SRCS) -o $(NAME)
	$(CC) $(CFLAGS) $(SRCS) -c
	
all: $(SRCO) $(NAME)

clean:
	$(RM) $(SRCO)

fclean: clean
	$(RM) $(NAME)

re:  fclean all

.PHONY: clean flcean re	
