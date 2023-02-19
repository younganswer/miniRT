SHELL	= /bin/bash
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
		err/exit_with_err.c \
		err/set_err.c \
		event/key_event.c \
		raytracing/raytracing.c \
		raytracing/ambient.c \
		raytracing/diffuse.c \
		raytracing/get_distance.c \
		raytracing/hit_object.c \
		raytracing/mirror_reflection.c \
		raytracing/phong_reflection.c \
		raytracing/ray.c \
		raytracing/specular.c \
		raytracing/vec3_utils_in_raytracing.c \
		render/render.c \

OBJS_DIRS = ${OBJS_DIR}/err \
			${OBJS_DIR}/event \
			${OBJS_DIR}/raytracing \
			${OBJS_DIR}/render

ifdef BONUS
	SRCS += parse_bonus/parse_bonus.c \
			parse_bonus/parse_ambient_lightning_bonus.c \
			parse_bonus/parse_camera_bonus.c \
			parse_bonus/parse_light_bonus.c \
			parse_bonus/parse_sphere_bonus.c \
			parse_bonus/parse_plane_bonus.c \
			parse_bonus/parse_cylinder_bonus.c \
			parse_bonus/parse_utils_bonus.c
	OBJS_DIRS += ${OBJS_DIR}/parse_bonus
else
	SRCS += parse/parse.c \
			parse/parse_ambient_lightning.c \
			parse/parse_camera.c \
			parse/parse_light.c \
			parse/parse_sphere.c \
			parse/parse_plane.c \
			parse/parse_cylinder.c \
			parse/parse_utils.c
	OBJS_DIRS += ${OBJS_DIR}/parse
endif

ifdef SANITIZE
	CFLAGS += -fsanitize=address
endif

SRCS := ${addprefix ${SRCS_DIR}/, ${SRCS}}
OBJS := ${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}
DEPS := ${OBJS:.o=.d}

SRCS_LEN	= ${shell echo ${SRCS} | wc -w}

IS_MANDATORY	= ${OBJS_DIR}/is_mandatory
IS_BONUS		= ${OBJS_DIR}/is_bonus


all: ${IS_MANDATORY}


bonus: ${IS_BONUS}


${IS_MANDATORY}:
	@${RM} ${NAME} ${IS_BONUS}
	@${MAKE} ${NAME}
	@touch ${IS_MANDATORY}


${IS_BONUS}:
	@${RM} ${NAME} ${IS_MANDATORY}
	@${MAKE} BONUS=1 ${NAME}
	@touch ${IS_BONUS}


${NAME}: ${OBJS}
	@if [ ${IDX} -gt 0 ]; then\
		printf "\b"; echo "done ";\
	fi
	@${CC} ${LDFLAGS} -g -o ${NAME} ${OBJS}
	@echo "Build ${NAME}: done"


${OBJS}: ${LIBMLX}


${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c | ${OBJS_DIRS}
	${eval IDX = ${shell expr ${IDX} + 1}}
	@if [ ${IDX} = 1 ]; then\
		echo -n "Build dependencies in ${NAME} ...  ";\
	fi
	@printf "%3d%%\b\b\b\b" ${shell expr ${IDX} \* 100 / ${SRCS_LEN}}
	@${CC} ${CFLAGS} -g -c $< -o $@


${OBJS_DIR}:
	@echo "Build ${NAME}"
	@mkdir -p ${OBJS_DIR}


${OBJS_DIRS}: ${OBJS_DIR}
	@mkdir -p ${OBJS_DIRS}


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

.NOTPARALLEL: all clean fclean re bonus

-include ${DEPS}