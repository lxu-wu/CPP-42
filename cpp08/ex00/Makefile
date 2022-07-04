NAME = easyfind

SRCS = main.cpp

OBJ = ${SRCS:.cpp=.o}

RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow -fsanitize=address -g
CC = g++

all:	${NAME}

$(NAME):	${OBJ}
		${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean:
		${RM} ${OBJ}

fclean:	clean
		${RM} ${NAME}

re: fclean all

.PHONY:	re fclean clean all	