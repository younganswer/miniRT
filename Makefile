SHELL	= /bin/bash
SPINNER	= /-\|/
IDX		= 0

NAME	= miniRT

LIBS_DIR		= libs

LIBFT_DIR		:= ${LIBS_DIR}/libft
LIBFT_INCS_DIR	:= ${LIBFT_DIR}/incs
LIBFT			:= ${LIBFT_DIR}/libft.a

LIBGNL_DIR		:= ${LIBS_DIR}/libgnl
LIBGNL_INCS_DIR	:= ${LIBGNL_DIR}/incs
LIBGNL			:= ${LIBGNL_DIR}/libgnl.a

LIBVEC_DIR		:= ${LIBS_DIR}/libvec
LIBVEC_INCS_DIR	:= ${LIBVEC_DIR}/incs
LIBVEC			:= ${LIBVEC_DIR}/libvec.a

LIBRAY_DIR		:= ${LIBS_DIR}/libray
LIBRAY_INCS_DIR	:= ${LIBRAY_DIR}/incs
LIBRAY			:= ${LIBRAY_DIR}/libray.a

LIBMLX_DIR		:= ${LIBS_DIR}/libmlx
LIBMLX_INCS_DIR	:= ${LIBMLX_DIR}/incs
LIBMLX			:= ${LIBMLX_DIR}/libmlx.a

INCS_DIR	= incs
SRCS_DIR	= srcs
OBJS_DIR	= objs

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I${INCS_DIR} -I${LIBFT_INCS_DIR} -I${LIBGNL_INCS_DIR} -I${LIBVEC_INCS_DIR} -I${LIBMLX_INCS_DIR} -MD -O3
LDFLAGS	= -L${LIBFT_DIR} -lft -L${LIBGNL_DIR} -lgnl -L${LIBVEC_DIR} -lvec -L${LIBRAY_DIR} -lray -L${LIBMLX_DIR} -lmlx -framework OpenGL -framework AppKit
AR		= ar rcs
RM		= rm -f

SRCS = 	miniRT.c \
		err/set_err.c \
		event/key_event.c \
		parse/parse.c \
		parse/parse_ambient_lightning.c \
		parse/parse_camera.c \
		parse/parse_lights.c \
		parse/parse_sphere.c \
		parse/parse_plane.c \
		parse/parse_cylinder.c \
		ray/ray.c \
		render/render.c \
		render/render_sphere.c \
		render/render_plane.c \
		render/render_cylinder.c
		
SRCS := ${addprefix ${SRCS_DIR}/, ${SRCS}}
OBJS := ${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}
DEPS := ${OBJS:.o=.d}


all: ${NAME}


${NAME}: ${OBJS}
	@printf "\bdone\n"
	@${CC} ${LDFLAGS} -g -o ${NAME} ${OBJS}
	@echo "Build ${NAME}: done"


${OBJS}: ${LIBMLX}


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
	@mkdir -p ${OBJS_DIR}/err
	@mkdir -p ${OBJS_DIR}/event
	@mkdir -p ${OBJS_DIR}/parse
	@mkdir -p ${OBJS_DIR}/ray
	@mkdir -p ${OBJS_DIR}/render


${LIBFT}:
	@${MAKE} -C ${LIBFT_DIR}


${LIBGNL}: ${LIBFT}
	@${MAKE} -C ${LIBGNL_DIR}


${LIBVEC}: ${LIBGNL}
	@${MAKE} -C ${LIBVEC_DIR}


${LIBRAY}: ${LIBVEC}
	@${MAKE} -C ${LIBRAY_DIR}


${LIBMLX}: ${LIBRAY}
	@${MAKE} -C ${LIBMLX_DIR}


clean:
	@echo "Remove dependencies in ${NAME}"
	@${MAKE} -C ${LIBFT_DIR} clean
	@${MAKE} -C ${LIBGNL_DIR} clean
	@${MAKE} -C ${LIBVEC_DIR} clean
	@${MAKE} -C ${LIBRAY_DIR} clean
	@${MAKE} -C ${LIBMLX_DIR} clean
	@rm -rf ${OBJS_DIR}


fclean:
	@echo "Remove dependencies in ${NAME}"
	@${MAKE} -C ${LIBFT_DIR} fclean
	@${MAKE} -C ${LIBGNL_DIR} fclean
	@${MAKE} -C ${LIBVEC_DIR} fclean
	@${MAKE} -C ${LIBRAY_DIR} fclean
	@${MAKE} -C ${LIBMLX_DIR} fclean
	@echo "Remove ${NAME}"
	@rm -rf ${OBJS_DIR}
	@${RM} ${NAME}
	

re:
	@echo "Re-build ${NAME}"
	@${MAKE} fclean
	@${MAKE} all


.PHONY: all clean fclean re bonus


-include ${DEPS}