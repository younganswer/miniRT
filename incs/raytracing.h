#ifndef RAY_H
# define RAY_H

# include "structs.h"

// raytracing.c
uint	phong_reflection(t_var *var, t_shape *shape, t_ray ray);
t_vec3	get_origin_color(t_shape *shape);

// ambient.c
t_vec3	ambient(t_var *var, t_shape *shape);

// diffuse.c
t_vec3	diffuse(t_var *var, t_shape *shape, t_ray ray);

// primary_ray.c
t_ray	primary_ray(t_camera *camera, int row, int col);

// specular.c
t_vec3	specular(t_var *var, t_shape *shape, t_ray ray, int depth);

#endif