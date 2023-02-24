#ifndef RAYTRACING_H
# define RAYTRACING_H

# include "structs.h"

# define INF 1e9
# define EPSILON 1e-4
# define INFSIMAL 1e-9
# define K 1.0

// raytracing.c
t_vec3	raytracing(t_var *var, t_hit hit);
t_vec3	get_color(t_object *object);
t_type	get_type(t_object *object);

// ambient.c
t_vec3	ambient(t_var *var, t_hit hit);

// cone.c
double	get_distance_to_cone(void *object, t_ray ray);
t_ray	get_normal_of_cone(void *object, t_vec3 contact);

// cylinder.c
double	get_distance_to_cylinder(void *object, t_ray ray);
t_ray	get_normal_of_cylinder(void *object, t_vec3 contact);

// diffuse.c
t_vec3	diffuse(t_var *var, t_light *light, t_hit hit);

// mirror_reflection.c
t_vec3	mirror_reflection(t_var *var, t_light *light, t_hit hit, int depth);

// phong_reflection.c
t_vec3	phong_reflection(t_var *var, t_light *light, t_hit hit);

// plane.c
double	get_distance_to_plane(void *object, t_ray ray);
t_ray	get_normal_of_plane(void *object, t_vec3 contact);

// ray.c
t_ray	primary_ray(t_camera *camera, double row, double col);

// hit_object.c
t_hit	hit_object(t_var *var, t_ray ray);

// specular.c
t_vec3	specular(t_light *light, t_hit hit);

// sphere.c
double	get_distance_to_sphere(void *object, t_ray ray);
t_ray	get_normal_of_sphere(void *object, t_vec3 contact);
double	discriminate(double a, double half_b, double c);

// vec3_utils_in_raytracing.c
uint	vec3_to_color(t_vec3 vec);
t_vec3	vec3_reflect(t_vec3 vec, t_vec3 normal);

#endif