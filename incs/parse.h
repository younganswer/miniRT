#ifndef PARSE_H
# define PARSE_H

# include "../libs/libft/incs/libft.h"
# include "structs.h"

// parse.c
t_bool	parse(t_var *var, char *file);
t_bool	color_range_is_valid(t_var *var, t_vec3 color);
t_bool	dir_range_is_valid(t_var *var, t_vec3 dir);

// parse_ambient_lightning.c
t_bool	parse_ambient_lightning(t_var *var, char **splited);

// parse_camera.c
t_bool	parse_camera(t_var *var, char **splited);

// parse_cone.c
t_bool	parse_cone(t_var *var, char **splited);

// parse_light.c
t_bool	parse_light(t_var *var, char **splited);

// parse_sphere.c
t_bool	parse_sphere(t_var *var, char **splited);

// parse_plane.c
t_bool	parse_plane(t_var *var, char **splited);

// parse_cylinder.c
t_bool	parse_cylinder(t_var *var, char **splited);

// parse_utils.c
char	*get_next_line_not_empty(int fd);
t_bool	parse_vec3(t_var *var, t_vec3 *vec, char *line);
t_bool	parse_type(t_var *var, t_type *type, char *line);

#endif