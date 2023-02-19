#ifndef RAY_H
# define RAY_H

# include "structs.h"

# define INF 1e9
# define EPSILON 1e-4
# define INFSIMAL 1e-9

// raytracing.c
t_vec3	raytracing(t_var *var, t_hit hit);
t_vec3	get_origin_color(t_object *object);
t_vec3	handle_shadow_acne(t_vec3 origin, t_vec3 direction);

// ambient.c
t_vec3	ambient(t_var *var, t_object *object);

// diffuse.c
t_vec3	diffuse(t_var *var, t_hit hit);

// get_distance.c
double	get_distance_to_sphere(void *object, t_ray ray);
double	get_distance_to_plane(void *object, t_ray ray);
double	get_distance_to_cylinder(void *object, t_ray ray);

// mirror_reflection.c
t_vec3	mirror_reflection(t_var *var, t_hit hit);

// phong_reflection.c
t_vec3	phong_reflection(t_var *var, t_hit hit);

// ray.c
t_ray	primary_ray(t_camera *camera, double row, double col);
t_ray	get_normal(t_object *object, t_vec3 contact);

// hit_object.c
t_hit	hit_object(t_var *var, t_ray ray);

// specular.c
t_vec3	specular(t_var *var, t_hit hit, int depth);

// vec3_utils_in_raytracing.c
uint	vec3_to_color(t_vec3 vec);
t_vec3	vec3_reflect(t_vec3 vec, t_vec3 normal);

#endif