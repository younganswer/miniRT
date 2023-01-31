SHELL	= /bin/bash
SPINNER	= /-\|/
IDX		= 0

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
AR = ar rcs
RM = rm -f

INCS_DIR = ./incs
SRCS_DIR = ./srcs
OBJS_DIR = ./objs

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
		ft_lstindex.c

SRCS := ${SRCS:%.c=${SRCS_DIR}/%.c}
OBJS := ${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}

all: ${OBJS_DIR}
	@make ${NAME}

${NAME}: ${OBJS}
	@printf "\bdone\n"
	@${AR} $@ $^
	@echo "Build libft.a: done"

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	${eval IDX = ${shell expr ${IDX} + 1}}
	${eval T_IDX = ${shell expr ${IDX} % 32}}
	${eval T_IDX = ${shell expr ${T_IDX} / 8 + 1}}
	${eval CHR = ${shell echo ${SPINNER} | cut -c ${T_IDX}}}
	@if [ ${IDX} = 1 ]; then echo -n "Build dependencies in libft.a ...  "; fi
	@printf "\b${CHR}"
	@${CC} ${CFLAGS} -c $< -o $@ -I ${INCS_DIR}

${OBJS_DIR}:
	@echo "Build libft.a"
	@mkdir -p objs

clean:
	@echo "Remove dependencies in libft"
	@rm -rf ${OBJS_DIR}

fclean: clean
	@echo "Remove libft.a"
	@${RM} ${NAME}

re:
	@echo "Re-build libft.a"
	@make fclean
	@make all

.PHONY: bonus all clean fclean re