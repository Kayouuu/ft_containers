# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 09:59:34 by psaulnie          #+#    #+#              #
#    Updated: 2022/11/21 14:11:30 by psaulnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LST_SRCS = vector_main.cpp

LST_INCS = ft_containers.hpp \
			stack.hpp \
			vector.hpp \
			comparison.hpp \
			is_integral.hpp \
			iterators.hpp \

CFLAGS = -Wall -Wextra -Werror -std=c++98
CFLAGS += -fsanitize=address -g3

CC = c++
NAME = ft_containers

SRCS	:=	$(addprefix srcs/,$(LST_SRCS))
INCS	:=	$(addprefix srcs/,$(LST_INCS))

OBJS = ${SRCS:.cpp=.o}

.PHONY:	all clean fclean re

all: ${NAME}

%.o:	%.cpp ${INCS}
		${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

vector: ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o vector

clean:
		rm -f ${OBJS}

fclean: clean
		rm -f ${NAME}
		rm -f vector

re: fclean all