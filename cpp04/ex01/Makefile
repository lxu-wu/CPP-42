NAME = brain

SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp

OBJ = ${SRCS:.cpp=.o}

RM = rm -rf
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow -fsanitize=address -g
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