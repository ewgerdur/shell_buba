NAME		= minishell

CC = gcc

FLAGS = -Wall -Wextra -Werror


SRCS := *.c

LIBFT			=	libft
OBJS 			=	$(SRCS:.c=.o)
LIBS			=	libft/libft.a
CC				=	@gcc -g
READLINE = -lreadline $(LDFLAGS) $(CPPFLAGS)


all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -s bonus -C $(LIBFT)
	$(CC) $(FLAGS) $(SRCS) $(LIBS) -o $(NAME) $(READLINE)

OBJS    :=  $(SRCS:.c=.o) $(UTILITIES:.c=.o)



.c.o:
	$(CC) -g $(CFLAGS) -g -c $< -o $(<:.c=.o)

clean:
	$(RM)   $(OBJS)

fclean: clean
	$(RM)   $(NAME)

re: fclean  all

.PHONY: all clean   fclean  re