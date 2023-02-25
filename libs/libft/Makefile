# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 15:00:44 by younhwan          #+#    #+#              #
#    Updated: 2023/02/25 15:00:45 by younhwan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL	= /bin/bash
IDX		= 0

NAME = libft.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I{INCS_DIR} -MD -O3
AR		= ar rcs
RM		= rm -f

INCS_DIR = incs
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS =  ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_exit_with_error.c \
		ft_is_space.c \
		ft_strcmp.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strappend.c \
		ft_swap.c \
		ft_lstindex.c \
		ft_strslen.c \
		ft_strsfree.c \
		ft_skip_space.c \
		ft_atof.c

SRCS := ${SRCS:%.c=${SRCS_DIR}/%.c}
OBJS := ${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}
DEPS := ${OBJS:.o=.d}

SRCS_LEN	= ${shell echo ${SRCS} | wc -w}


all: ${NAME}


${NAME}: ${OBJS}
	@if [ ${IDX} -gt 0 ]; then\
		printf "\b"; echo "done ";\
	fi
	@${AR} $@ $^
	@echo "Build ${NAME}: done"


${OBJS}: ${OBJS_DIR}


${OBJS_DIR}:
	@echo "Build ${NAME}"
	@mkdir -p objs


${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	${eval IDX = ${shell expr ${IDX} + 1}}
	@if [ ${IDX} = 1 ]; then\
		echo -n "Build dependencies in ${NAME} ...  ";\
	fi
	@printf "%3d%%\b\b\b\b" ${shell expr ${IDX} \* 100 / ${SRCS_LEN}}
	@${CC} ${CFLAGS} -g -c $< -o $@



clean:
	@echo "Remove dependencies in ${NAME}"
	@rm -rf ${OBJS_DIR}


fclean: clean
	@echo "Remove ${NAME}"
	@${RM} ${NAME}


re:
	@echo "Rebuild ${NAME}"
	@${MAKE} fclean
	@${MAKE} all


.PHONY: all clean fclean re

.NONPARALLEL: all clean fclean re

-include ${DEPS}