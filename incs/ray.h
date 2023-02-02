#ifndef RAY_H
# define RAY_H

# include "../libs/libvec/incs/vec3.h"

typedef struct	s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

// ray.c
t_vec3	origin(t_ray ray);
t_vec3	direction(t_ray ray);
t_vec3	point_at_parameter(t_ray ray, double t);

#endif