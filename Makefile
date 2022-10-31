# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 09:59:34 by psaulnie          #+#    #+#              #
#    Updated: 2022/10/27 14:34:42 by psaulnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#need to add .tpp

LST_SRCS = main.cpp \
LST_INCS = ft_containers.hpp \
			stack/stack.hpp \
			vector/vector.hpp
LST_OBJS = ${SRCS:.cpp=.o}

CFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
NAME = ft_containers

SRCS	:=	$(addprefix srcs/,$(LST_SRCS))
INCS	:=	$(addprefix srcs/,$(LST_INCS))

.PHONY:	all clean fclean re

all: ${NAME}

%.o:	%.cpp ${INCS}
		${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
		rm -f ${OBJS}

fclean: clean
		rm -f ${NAME}

re: fclean all