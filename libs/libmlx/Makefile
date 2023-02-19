SHELL	= /bin/bash
IDX		= 0

NAME	= libmlx.a
CC		= cc
CFLAGS	= -I${INCS_DIR} -MD -O3
# add to match string put with X11 in size and position
CFLAGS	+= -DSTRINGPUTX11
CFLAGS	+= -Wno-deprecated-declarations
AR		= ar rcs
RM		= rm -f

INCS_DIR	= incs
SRCS_DIR	= srcs
OBJS_DIR	= objs

SRCS	=	mlx_shaders.c \
			mlx_new_window.m \
			mlx_init_loop.m \
			mlx_new_image.m \
			mlx_xpm.c \
			mlx_int_str_to_wordtab.c
SRCS	+=	mlx_png.c \
			mlx_mouse.m

SRCS	:= ${addprefix ${SRCS_DIR}/, ${SRCS}}
OBJS	:= ${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}
OBJS	:= ${OBJS:${SRCS_DIR}/%.m=${OBJS_DIR}/%.o}
DEPS	:= ${OBJS:.o=.d}

SRCS_LEN	:= ${shell echo ${SRCS} | wc -w}


all: ${NAME}


${NAME}: ${OBJS}
	@if [ ${IDX} -gt 0 ]; then\
		printf "\b"; echo "done ";\
	fi
	@${AR} ${NAME} ${OBJS}
	@echo "Build ${NAME}: done"


${OBJS_DIR}:
	@echo "Build ${NAME}"
	@mkdir -p $@
	

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c | ${OBJS_DIR}
	${eval IDX = ${shell expr ${IDX} + 1}}
	@if [ ${IDX} = 1 ]; then\
		echo -n "Build dependencies in ${NAME} ...  ";\
	fi
	@printf "%3d%%\b\b\b\b" ${shell expr ${IDX} \* 100 / ${SRCS_LEN}}
	@${CC} ${CFLAGS} -c $< -o $@


${OBJS_DIR}/%.o: ${SRCS_DIR}/%.m | ${OBJS_DIR}
	${eval IDX = ${shell expr ${IDX} + 1}}
	@if [ ${IDX} = 1 ]; then\
		echo -n "Build dependencies in ${NAME} ...  ";\
	fi
	@printf "%3d%%\b\b\b\b" ${shell expr ${IDX} \* 100 / ${SRCS_LEN}}
	@${CC} ${CFLAGS} -c $< -o $@


clean:
	@echo "Remove dependencies in ${NAME}"
	@${RM} -r ${OBJS_DIR}


fclean: clean
	@echo "Remove ${NAME}"
	@${RM} ${NAME}


re:
	@echo "Re-build ${NAME}"
	@${MAKE} fclean
	@${MAKE} all


.PHONY: all clean fclean re

.NONPARALLEL: all clean fclean re

-include ${DEPS}