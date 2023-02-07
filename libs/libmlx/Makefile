SHELL	= /bin/bash
SPINNER	= /-\|/
IDX		= 0

NAME	:= libmlx.a
CC		:= cc
CFLAGS	:= -O3
# add to match string put with X11 in size and position
CFLAGS	+= -DSTRINGPUTX11
CFLAGS	+= -Wno-deprecated-declarations
AR		:= ar rcs
RM		:= rm -f

INCS_DIR	:= incs
SRCS_DIR	:= srcs
OBJS_DIR	:= objs

SRCS	:=	mlx_shaders.c \
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


all: ${NAME}


${NAME}: ${OBJS}
	@printf "\bdone\n"
	@${AR} ${NAME} ${OBJS}
	@echo "Build ${NAME}: done"


${OBJS_DIR}:
	@echo "Build libmlx.a"
	@mkdir -p $@
	

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c | ${OBJS_DIR}
	${eval IDX = ${shell expr ${IDX} + 1}}
	${eval T_IDX = ${shell expr ${IDX} % 32}}
	${eval T_IDX = ${shell expr ${T_IDX} / 8 + 1}}
	${eval CHR = ${shell echo ${SPINNER} | cut -c ${T_IDX}}}
	@if [ ${IDX} = 1 ]; then echo -n "Build dependencies in ${NAME} ...  "; fi
	@printf "\b${CHR}"
	@${CC} ${CFLAGS} -c $< -o $@ -I ${INCS_DIR}


${OBJS_DIR}/%.o: ${SRCS_DIR}/%.m | ${OBJS_DIR}
	${eval IDX = ${shell expr ${IDX} + 1}}
	${eval T_IDX = ${shell expr ${IDX} % 32}}
	${eval T_IDX = ${shell expr ${T_IDX} / 8 + 1}}
	${eval CHR = ${shell echo ${SPINNER} | cut -c ${T_IDX}}}
	@if [ ${IDX} = 1 ]; then echo -n "Build dependencies in ${NAME} ...  "; fi
	@printf "\b${CHR}"
	@${CC} ${CFLAGS} -c $< -o $@ -I ${INCS_DIR}


clean:
	@echo "Remove dependencies in libmlx.a"
	@${RM} -r ${OBJS_DIR}


fclean: clean
	@echo "Remove libmlx.a"
	@${RM} ${NAME}


re:
	@echo "Rebuild libmlx.a"
	@${MAKE} fclean
	@${MAKE} all


.PHONY: all clean fclean re