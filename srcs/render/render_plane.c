#include "../../incs/render.h"
#include "../../incs/ray.h"
#include <math.h>

double	hit_plane(t_plane *plane, t_ray ray);
size_t	get_color_of_plane(t_plane *plane, t_ray ray, double t);

double	hit_plane(t_plane *plane, t_ray ray)
{
	const double	denominator = vec3_dot(plane->normal, ray.direction);
	if (fabs(denominator) > 1e-6)
		return (vec3_dot(vec3_sub(plane->point, ray.origin), plane->normal)
			/ denominator);
	return (-1.0);
}

size_t	get_color_of_plane(t_plane *plane, t_ray ray, double t)
{
	size_t	ret;

	ret = (size_t) plane->color.x;
	ret = (ret << 8) + (size_t) plane->color.y;
	ret = (ret << 8) + (size_t) plane->color.z;
	(void) ray;
	(void) t;
	return (ret);
}
