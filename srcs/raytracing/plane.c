#include "../../incs/raytracing.h"
#include <math.h>

double	get_distance_to_plane(void *object, t_ray ray);
t_ray	get_normal_of_plane(void *object, t_vec3 contact);

double	get_distance_to_plane(void *object, t_ray ray)
{
	t_plane *const	plane = (t_plane *) object;
	const double	denom = vec3_dot(plane->normal, ray.direction);
	const double	numer = vec3_dot(vec3_sub(plane->point, ray.origin), plane->normal);
	double			ret;

	if (fabs(denom) <= INFSIMAL)
		return (INF);
	ret = numer / denom;
	if (ret <= 0)
		return (INF);
	return (ret);
}

t_ray	get_normal_of_plane(void *object, t_vec3 contact)
{
	t_plane *const	plane = (t_plane *) object;
	
	return (
		(t_ray){
			contact,
			plane->normal
		}
	);
}
