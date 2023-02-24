SHELL	= /bin/bash
IDX		= 0

NAME	= libray.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I{INCS_DIR} -MD -O3
AR		= ar rcs
RM		= rm -f

INCS_DIR = incs
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS =  libray.c

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
	@${CC} ${CFLAGS} -c $< -o $@



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

.NOTPARALLEL: all clean fclean re

-include ${DEPS}