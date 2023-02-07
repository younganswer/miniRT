SHELL	= /bin/bash
SPINNER	= /-\|/
IDX		= 0

NAME = libgnl.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
AR = ar rcs
RM = rm -f

INCS_DIR = incs
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS =  get_next_line.c \
		get_next_line_utils.c

SRCS := ${SRCS:%.c=${SRCS_DIR}/%.c}
OBJS := ${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}


all: ${NAME}


${NAME}: ${OBJS}
	@printf "\bdone\n"
	@${AR} $@ $^
	@echo "Build ${NAME}: done"


${OBJS}: ${OBJS_DIR}


${OBJS_DIR}:
	@echo "Build ${NAME}"
	@mkdir -p objs


${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	${eval IDX = ${shell expr ${IDX} + 1}}
	${eval T_IDX = ${shell expr ${IDX} % 32}}
	${eval T_IDX = ${shell expr ${T_IDX} / 8 + 1}}
	${eval CHR = ${shell echo ${SPINNER} | cut -c ${T_IDX}}}
	@if [ ${IDX} = 1 ]; then echo -n "Build dependencies in ${NAME} ...  "; fi
	@printf "\b${CHR}"
	@${CC} ${CFLAGS} -c $< -o $@ -I ${INCS_DIR}



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


.PHONY: bonus all clean fclean re