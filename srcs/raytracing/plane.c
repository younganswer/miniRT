#include "../../incs/raytracing.h"
#include <math.h>

double	get_distance_to_plane(void *object, t_ray ray);
t_ray	get_normal_of_plane(void *object, t_vec3 contact);

double	get_distance_to_plane(void *object, t_ray ray)
{
	t_plane *const	plane = (t_plane *) object;
	const t_vec3	op = vec3_sub(plane->point, ray.origin);
	const double	denom = vec3_dot(plane->normal, ray.direction);
	const double	numer = vec3_dot(op, plane->normal);

	if (fabs(denom) <= INFSIMAL)
		return (INF);
	if (numer / denom <= 0)
		return (INF);
	return (numer / denom);
}

t_ray	get_normal_of_plane(void *object, t_vec3 contact)
{
	t_plane *const	plane = (t_plane *) object;

	return ((t_ray){contact, plane->normal});
}
