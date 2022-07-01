NAME = bureaucrat

SRCS = Bureaucrat.cpp main.cpp

OBJS = ${SRCS:.cpp=.o}

RM = rm -rf

CFLGAS = -Wall -Werror -Wextra -std=c++98 -Wshadow -Wno-shadow
CC = g++

all:	${NAME}

$(NAME):	${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: flcean all

.PHONY: re flcean clean all