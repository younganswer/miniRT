#ifndef STRUCTS_H
# define STRUCTS_H

# include "../libs/libvec/incs/vec3.h"
# include "ray.h"

typedef struct	s_camera
{
	t_ray	ray;
	double	fov;
}			t_camera;

typedef struct	s_var
{
	t_camera	*camera;
}				t_var;

#endif