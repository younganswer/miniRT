SHELL	= /bin/bash
IDX		= 0

NAME	= libvec.a

INCS_DIR	= incs
SRCS_DIR	= srcs
OBJS_DIR	= objs

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I{INCS_DIR} -MD -O3
AR		= ar rcs
RM		= rm -f

SRCS =	vec3/vec3_four_fundamental_arithmetic_operations.c \
		vec3/vec3_products.c \
		vec3/vec3_utils.c
		
SRCS := ${addprefix ${SRCS_DIR}/, ${SRCS}}
OBJS := ${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}
DEPS := ${OBJS:.o=.d}

SRCS_LEN = ${shell echo ${SRCS} | wc -w}


all: ${NAME}


${NAME}: ${OBJS}
	@if [ ${IDX} -gt 0 ]; then\
		printf "\b"; echo "done ";\
	fi
	@${AR} ${NAME} ${OBJS}
	@echo "Build ${NAME}: done"


${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c | ${OBJS_DIR}
	${eval IDX = ${shell expr ${IDX} + 1}}
	@if [ ${IDX} = 1 ]; then\
		echo -n "Build dependencies in ${NAME} ...  ";\
	fi
	@printf "%3d%%\b\b\b\b" ${shell expr ${IDX} \* 100 / ${SRCS_LEN}}
	@${CC} ${CFLAGS} -g -c $< -o $@


${OBJS_DIR}:
	@echo "Build ${NAME}"
	@mkdir -p ${OBJS_DIR}
	@mkdir -p ${OBJS_DIR}/vec3


clean:
	@echo "Remove dependencies in ${NAME}"
	@rm -rf ${OBJS_DIR}


fclean:
	@echo "Remove dependencies in ${NAME}"
	@echo "Remove ${NAME}"
	@rm -rf ${OBJS_DIR}
	@${RM} ${NAME}
	

re:
	@echo "Rebuild ${NAME}"
	@${MAKE} fclean
	@${MAKE} all


.PHONY: all clean fclean re

.NONPARALLEL: all clean fclean re

-include ${DEPS}