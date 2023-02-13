#ifndef RAY_H
# define RAY_H

# include "structs.h"
# define INF 1e9
# define EPSILON 1e-4

// raytracing.c
uint	phong_reflection(t_var *var, t_hit hit);
t_vec3	get_origin_color(t_object *object);

// ambient.c
t_vec3	ambient(t_var *var, t_object *object);

// diffuse.c
t_vec3	diffuse(t_var *var, t_object *object, t_ray ray);

// get_distance.c
double	get_distance_to_sphere(void *object, t_ray ray);
double	get_distance_to_plane(void *object, t_ray ray);
double	get_distance_to_cylinder(void *object, t_ray ray);

// ray.c
t_ray	primary_ray(t_camera *camera, int row, int col);
t_ray	get_normal(t_object *object, t_vec3 contact);

// hit_object.c
t_hit	hit_object(t_var *var, t_ray ray);

// specular.c
t_vec3	specular(t_var *var, t_object *object, t_ray ray, int depth);

#endif