SHELL	= /bin/bash
SPINNER	= /-\|/
IDX		= 0

SRCS_DIR	:= ./srcs
OBJS_DIR	:= ./objs
INCS_DIR	:= ./incs

MODULE_SRCS	:= mlx_image.swift mlx_window.swift mlx_init.swift
MODULE_SRCS	:= ${addprefix ${SRCS_DIR}/, ${MODULE_SRCS}}
MODULE_OBJS	:= ${MODULE_SRCS:${SRCS_DIR}/%.swift=${OBJS_DIR}/%.swiftmodule}

SRCS	:= interface.swift
SRCS	:= ${addprefix ${SRCS_DIR}/, ${SRCS}}
SRCS	:= ${SRCS} ${MODULE_SRCS}
OBJS	:= ${SRCS:${SRCS_DIR}/%.swift=${OBJS_DIR}/%.o}

C_SRCS	:= mlx_xpm.c mlx_png.c mlx_string_put.c
C_SRCS	:= ${addprefix ${SRCS_DIR}/, ${C_SRCS}}
C_OBJS	:= ${C_SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}

CC		:= gcc
CFLAGS	:= -O3

NAME	:= libmlx.dylib
#OPTI	:= -Ounchecked


all: ${NAME}


${NAME}: ${C_OBJS}
	@printf "\bdone\n"
	@swiftc ${OPTI} -o ${NAME} -emit-library ${OBJS} ${C_OBJS} -lz
	@echo "Build ${NAME}: done"


${OBJS_DIR}:
	@mkdir -p $@


${C_OBJS}: ${OBJS}


${OBJS}: ${OBJS_DIR}/interface.swiftmodule


${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	${eval IDX = ${shell expr ${IDX} + 1}}
	${eval T_IDX = ${shell expr ${IDX} % 32}}
	${eval T_IDX = ${shell expr ${T_IDX} / 8 + 1}}
	${eval CHR = ${shell echo ${SPINNER} | cut -c ${T_IDX}}}
	@printf "\b${CHR}"
	@${CC} ${CFLAGS} -c $< -o $@ -I${INCS_DIR}


${OBJS_DIR}/%.o: ${SRCS_DIR}/%.swift
	${eval IDX = ${shell expr ${IDX} + 1}}
	${eval T_IDX = ${shell expr ${IDX} % 32}}
	${eval T_IDX = ${shell expr ${T_IDX} / 8 + 1}}
	${eval CHR = ${shell echo ${SPINNER} | cut -c ${T_IDX}}}
	@printf "\b${CHR}"
	@swiftc ${OPTI} -parse-as-library -c $< -o $@ -I${OBJS_DIR}


${OBJS_DIR}/interface.swiftmodule: ${OBJS_DIR}/mlx_init.swiftmodule
	${eval IDX = ${shell expr ${IDX} + 1}}
	${eval T_IDX = ${shell expr ${IDX} % 32}}
	${eval T_IDX = ${shell expr ${T_IDX} / 8 + 1}}
	${eval CHR = ${shell echo ${SPINNER} | cut -c ${T_IDX}}}
	@printf "\b${CHR}"
	@swiftc ${OPTI} -parse-as-library -c ${SRCS_DIR}/interface.swift -o ${OBJS_DIR}/interface.swiftmodule -emit-module -module-name interface -module-link-name interface -I${OBJS_DIR}


${OBJS_DIR}/mlx_init.swiftmodule: ${OBJS_DIR}/mlx_window.swiftmodule
	${eval IDX = ${shell expr ${IDX} + 1}}
	${eval T_IDX = ${shell expr ${IDX} % 32}}
	${eval T_IDX = ${shell expr ${T_IDX} / 8 + 1}}
	${eval CHR = ${shell echo ${SPINNER} | cut -c ${T_IDX}}}
	@printf "\b${CHR}"
	@swiftc ${OPTI} -parse-as-library -c ${SRCS_DIR}/mlx_init.swift -o ${OBJS_DIR}/mlx_init.swiftmodule -emit-module -module-name mlx_init -module-link-name mlx_init -I${OBJS_DIR}


${OBJS_DIR}/mlx_window.swiftmodule: ${OBJS_DIR}/mlx_image.swiftmodule
	${eval IDX = ${shell expr ${IDX} + 1}}
	${eval T_IDX = ${shell expr ${IDX} % 32}}
	${eval T_IDX = ${shell expr ${T_IDX} / 8 + 1}}
	${eval CHR = ${shell echo ${SPINNER} | cut -c ${T_IDX}}}
	@printf "\b${CHR}"
	@swiftc ${OPTI} -parse-as-library -c ${SRCS_DIR}/mlx_window.swift -o ${OBJS_DIR}/mlx_window.swiftmodule -emit-module -module-name mlx_window -module-link-name mlx_window -I${OBJS_DIR}


${OBJS_DIR}/mlx_image.swiftmodule: ${OBJS_DIR}
	${eval IDX = ${shell expr ${IDX} + 1}}
	${eval T_IDX = ${shell expr ${IDX} % 32}}
	${eval T_IDX = ${shell expr ${T_IDX} / 8 + 1}}
	${eval CHR = ${shell echo ${SPINNER} | cut -c ${T_IDX}}}
	@if [ ${IDX} = 1 ]; then\
		echo -n "Build dependencies in ${NAME} ...  ";\
	fi
	@printf "\b${CHR}"
	@swiftc ${OPTI} -parse-as-library -c ${SRCS_DIR}/mlx_image.swift -o ${OBJS_DIR}/mlx_image.swiftmodule -emit-module -module-name mlx_image -module-link-name mlx_image -I${OBJS_DIR}


clean:
	@echo "Remove dependencies in ${NAME}"
	@rm -rf ${OBJS_DIR}


fclean: clean
	@echo "Remove ${NAME}"
	@rm -rf ${NAME}