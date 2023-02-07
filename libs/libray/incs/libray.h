#ifndef LIBRAY_H
# define LIBRAY_H

# include "../../libvec/incs/vec3.h"

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