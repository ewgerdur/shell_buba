NAME = libft

INC_DIR = .

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c\
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_strrchr.c ft_putstr_fd.c\
		ft_memmove.c ft_memset.c  ft_putendl_fd.c ft_putnbr_fd.c ft_putchar_fd.c\
		ft_strchr.c ft_strlen.c ft_strlcat.c ft_strtrim.c ft_split.c\
		ft_strjoin.c ft_strncmp.c ft_strlcpy.c ft_strnstr.c\
		ft_strncmp.c  ft_tolower.c ft_toupper.c ft_substr.c\
		ft_isascii.c ft_strdup.c ft_memccpy.c ft_strmapi.c\

OBJS = ${SRCS:.c=.o}

BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstadd_back.c ft_lstlast.c ft_lstdelone.c ft_lstclear.c\
		ft_lstiter.c ft_lstmap.c\

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

DEPS = libft.h

CFLAGS = -Wall -Wextra -Werror -I${INC_DIR}

AR = ar rc

.c.o : ${DEPS}
		gcc ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

$(NAME): ${OBJS}
			${AR} ${NAME}.a ${OBJS}

bonus:	${BONUS_OBJS}
			${AR} ${NAME}.a ${BONUS_OBJS}

clean:
			rm -f ${OBJS} ${BONUS_OBJS} 

fclean:		clean
			rm -f ${NAME}.a

re: fclean all

.PHONY: all clean fclean re
