# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 00:26:43 by younhwan          #+#    #+#              #
#    Updated: 2023/01/24 11:27:26 by younhwan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL	= /bin/bash
SPINNER	= /-\|/
IDX		= 0

NAME = libgnl.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
AR = ar rcs
RM = rm -f

INCS_DIR = ./incs
SRCS_DIR = ./srcs
OBJS_DIR = ./objs

SRCS = 	get_next_line.c\
		get_next_line_utils.c

SRCS := ${addprefix ${SRCS_DIR}/, ${SRCS}}
OBJS = ${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}


all: ${OBJS_DIR}
	@make ${NAME}


${OBJS_DIR}:
	@echo "Build libgnl.a"
	@mkdir -p objs


${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	${eval IDX = ${shell expr ${IDX} + 1}}
	${eval T_IDX = ${shell expr ${IDX} % 32}}
	${eval T_IDX = ${shell expr ${T_IDX} / 8 + 1}}
	${eval CHR = ${shell echo ${SPINNER} | cut -c ${T_IDX}}}
	@if [ ${IDX} = 1 ]; then echo -n "Build dependencies in libgnl.a ...  "; fi
	@printf "\b${CHR}"
	@${CC} ${CFLAGS} -c ${patsubst %.o,%.c,${subst obj,src,$@}} -o $@ -I ${INCS_DIR}


${NAME}: ${OBJS}
	@printf "\bdone\n"
	@${AR} $@ $^
	@echo "Build libgnl.a: done"


clean:
	@echo "Remove dependencies in get_next_line"
	@rm -rf ${OBJS_DIR}


fclean: clean
	@echo "Remove libgnl.a"
	@${RM} ${NAME}


re:
	@echo "Re-build libgnl.a"
	@make fclean
	@make all


.PHONY: all clean fclean re