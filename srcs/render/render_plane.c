#include "../../incs/render.h"
#include "../../incs/ray.h"
#include <math.h>

double	get_distance_of_plane(t_plane *plane, t_ray ray);
size_t	get_color_of_plane(t_plane *plane, t_ray ray);

double	get_distance_of_plane(t_plane *plane, t_ray ray)
{
	double	ret;
	double	denom;
	double	numer;

	ret = INF;
	denom = vec3_dot(plane->normal, ray.direction);
	if (fabs(denom) <= 1e-6)
		return (ret);
	numer = vec3_dot(vec3_sub(plane->point, ray.origin), plane->normal);
	ret = numer / denom;
	if (ret < 0)
		return (INF);
	return (ret);
}

size_t	get_color_of_plane(t_plane *plane, t_ray ray)
{
	size_t	ret;

	ret = (size_t) plane->color.x;
	ret = (ret << 8) + (size_t) plane->color.y;
	ret = (ret << 8) + (size_t) plane->color.z;
	(void) ray;
	return (ret);
}
