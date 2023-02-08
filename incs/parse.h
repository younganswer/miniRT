#ifndef PARSE_H
# define PARSE_H

# include "../libs/libft/incs/libft.h"
# include "structs.h"

// parse.c
t_bool	parse(t_var *var, char *file);
char	*get_next_line_not_empty(int fd);
t_bool	parse_vec3(t_vec3 *vec, char **line);

// parse_ambient_lightning.c
t_bool	parse_ambient_lightning(t_var *var, int fd);

// parse_camera.c
t_bool	parse_camera(t_var *var, int fd);

// parse_light.c
t_bool	parse_light(t_var *var, int fd);

// parse_shape.c
t_bool	parse_shape(t_var *var, int fd);

// parse_sphere.c
t_bool	parse_sphere(t_var *var, char *line);

// parse_plane.c
t_bool	parse_plane(t_var *var, char *line);

// parse_cylinder.c
t_bool	parse_cylinder(t_var *var, char *line);

#endif