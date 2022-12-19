# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 09:59:34 by psaulnie          #+#    #+#              #
#    Updated: 2022/12/19 15:06:32 by psaulnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VECTOR = srcs/vector_main.cpp
MAP = srcs/map_main.cpp

LST_INCS =  stack.hpp \
			vector.hpp \
			comparison.hpp \
			is_integral.hpp \
			iterators.hpp \

CFLAGS = -Wall -Wextra -Werror -std=c++98
# CFLAGS += -fsanitize=address -g3

CC = c++
NAME = vector_tester
MNAME = map_tester

INCS	:=	$(addprefix srcs/,$(LST_INCS))

VOBJS = ${VECTOR:.cpp=.o}
MOBJS = ${MAP:.cpp=.o}

.PHONY:	all clean fclean re

all: ${NAME}

%.o:	%.cpp ${INCS}
		${CC} ${CFLAGS} -c $< -o $@

${NAME}: vector map

vector: ${VOBJS}
		${CC} ${CFLAGS} ${VOBJS} -o ${NAME}

map:	${MOBJS}
		${CC} ${CFLAGS} ${MOBJS} -o ${MNAME}

clean:
		rm -f ${MOBJS}
		rm -f ${VOBJS}

fclean: clean
		rm -f ${NAME}
		rm -f ${MNAME}

re: fclean all