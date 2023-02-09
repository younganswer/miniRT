#include "../../incs/render.h"
#include "../../incs/ray.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double			get_distance_of_sphere(t_sphere *sphere, t_ray ray);
size_t			get_color_of_sphere(t_sphere *sphere, t_ray ray);
static double	get_dist(double a, double half_b, double c);

double	get_distance_of_sphere(t_sphere *sphere, t_ray ray)
{
	const t_vec3	oc = vec3_sub(ray.origin, sphere->center);
	const double	a = vec3_dot(ray.direction, ray.direction);
	const double	half_b = vec3_dot(oc, ray.direction);
	const double	c = vec3_dot(oc, oc) - sphere->radius * sphere->radius;

	return (get_dist(a, half_b, c));
}

size_t	get_color_of_sphere(t_sphere *sphere, t_ray ray)
{
	size_t	ret;

	ret = (size_t) sphere->color.x;
	ret = (ret << 8) + (size_t) sphere->color.y;
	ret = (ret << 8) + (size_t) sphere->color.z;
	(void) ray;
	return (ret);
}

static double	get_dist(double a, double half_b, double c)
{
	double	discriminant;
	double	t1;
	double	t2;

	discriminant = pow(half_b, 2) - a * c;
	if (discriminant < 0)
		return (INF);
	discriminant = sqrt(discriminant);
	t1 = (-half_b - discriminant) / a;
	t2 = (-half_b + discriminant) / a;
	if (t1 < 0 && t2 < 0)
		return (INF);
	if (t1 < 0)
		return (t2);
	if (t2 < 0)
		return (t1);
	return (fmin(t1, t2));
}
