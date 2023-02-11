#include "../../incs/render.h"
#include "../../incs/ray.h"
#include <math.h>

double	get_distance_of_plane(void *content, t_ray ray);
uint	get_color_of_plane(void *content, t_ray ray);

double	get_distance_of_plane(void *content, t_ray ray)
{
	t_plane *const	plane = (t_plane *) content;
	double			ret;
	double			denom;
	double			numer;

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

uint	get_color_of_plane(void *content, t_ray ray)
{
	t_plane *const	plane = (t_plane *) content;
	uint			ret;

	ret = (uint) plane->color.x;
	ret = (ret << 8) + (uint) plane->color.y;
	ret = (ret << 8) + (uint) plane->color.z;
	(void) ray;
	return (ret);
}
