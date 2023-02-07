#ifndef PARSE_H
# define PARSE_H

# include "../libs/libft/incs/libft.h"
# include "structs.h"

// parse.c
t_bool	parse(t_var *var, char *file);

// parse_camera.c
t_bool	parse_camera(t_var *var, int fd);

// parse_shape.c
t_bool	parse_shape(t_var *var, int fd);

#endif