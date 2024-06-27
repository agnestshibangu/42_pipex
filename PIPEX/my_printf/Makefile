NAME = my_printf

SRCS = ft_printf.c my_printf_character.c  my_printf_string.c my_printf_number.c ft_nbrlen_unsigned.c my_printf_unsigned.c my_printf_hex_lower.c my_printf_hex_upper.c my_printf_pointer.c

OBJS = ${SRCS:.c=.o}

RM = rm -f

CC = gcc

FLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS} ${BOBJ}

fclean:    clean
	${RM} ${NAME}

re: fclean all

# bonus: ${BOBJ}
	ar -rcs ${NAME} ${BOBJ}

.PHONY: all bonus clean fclean re