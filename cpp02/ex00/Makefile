NAME = fixed

SRCS = main.cpp Fixed.cpp

OBJ = ${SRCS:.cpp=.o}

RM = rm -rf
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CC = g++

all:	${NAME}

$(NAME):	${OBJ}
		${CC} ${CXXFLAGS} ${OBJ} -o ${NAME}

clean:
		${RM} ${OBJ}

fclean:	clean
		${RM} ${NAME}

re: fclean all

.PHONY:	re fclean clean all	