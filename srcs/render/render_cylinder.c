#include "../../incs/render.h"
#include <math.h>

double			get_distance_of_cylinder(t_cylinder *cylinder, t_ray ray);
size_t			get_color_of_cylinder(t_cylinder *cylinder, t_ray ray);
static double	get_dist(double a, double half_b, double c);

double	get_distance_of_cylinder(t_cylinder *cylinder, t_ray ray)
{
	const t_vec3	oc = vec3_sub(ray.origin, cylinder->center);
	const double	a
		= vec3_dot(ray.direction, ray.direction)
			- pow(vec3_dot(ray.direction, cylinder->normal), 2);
	const double	half_b
		= vec3_dot(oc, ray.direction)
			- vec3_dot(oc, cylinder->normal)
				* vec3_dot(ray.direction, cylinder->normal);
	const double	c
		= vec3_dot(oc, oc)
			- pow(vec3_dot(oc, cylinder->normal), 2)
				- pow(cylinder->radius, 2);
	return (get_dist(a, half_b, c));
}

size_t	get_color_of_cylinder(t_cylinder *cylinder, t_ray ray)
{
	size_t	ret;

	ret = (size_t) cylinder->color.x;
	ret = (ret << 8) + (size_t) cylinder->color.y;
	ret = (ret << 8) + (size_t) cylinder->color.z;
	(void) ray;
	return (ret);
}

static double	get_dist(double a, double half_b, double c)
{
	const double	discriminant = pow(half_b, 2) - a * c;
	double			t;

	if (discriminant < 0)
		return (INF);
	t = (-half_b - sqrt(discriminant)) / a;
	if (EPSILON < t)
		return (t);
	t = (-half_b + sqrt(discriminant)) / a;
	if (EPSILON < t)
		return (t);
	return (INF);
}
