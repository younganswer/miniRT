SHELL	= /bin/bash
SPINNER	= /-\|/
IDX		= 0

NAME	= libvec.a

INCS_DIR	= incs
SRCS_DIR	= srcs
OBJS_DIR	= objs

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I${INCS_DIR} -I${LIBFT_INCS_DIR} -I${LIBGNL_INCS_DIR} -I${INCS_DIR} -MD -O3
AR		= ar rcs
RM		= rm -f

SRCS =	vec3/vec3_four_fundamental_arithmetic_operations.c \
		vec3/vec3_products.c \
		vec3/vec3_utils.c
		
SRCS := ${addprefix ${SRCS_DIR}/, ${SRCS}}
OBJS := ${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}
DEPS := ${OBJS:.o=.d}


all: ${NAME}


${NAME}: ${OBJS}
	@printf "\bdone\n"
	@${AR} ${NAME} ${OBJS}
	@echo "Build ${NAME}: done"


${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c | ${OBJS_DIR}
	${eval IDX = ${shell expr ${IDX} + 1}}
	${eval T_IDX = ${shell expr ${IDX} % 32}}
	${eval T_IDX = ${shell expr ${T_IDX} / 8 + 1}}
	${eval CHR = ${shell echo ${SPINNER} | cut -c ${T_IDX}}}
	@if [ ${IDX} = 1 ]; then\
		echo -n "Build dependencies in ${NAME} ...  ";\
	fi
	@printf "\b${CHR}"
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
	@echo "Re-build ${NAME}"
	@${MAKE} fclean
	@${MAKE} all


.PHONY: all clean fclean re bonus


-include ${DEPS}