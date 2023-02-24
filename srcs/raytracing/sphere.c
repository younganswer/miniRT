#include "../../incs/raytracing.h"
#include <math.h>

double			get_distance_to_sphere(void *object, t_ray ray);
t_ray			get_normal_of_sphere(void *object, t_vec3 contact);
static double	get_dist(t_sphere *sphere, t_ray ray);

double	get_distance_to_sphere(void *object, t_ray ray)
{
	t_sphere *const	sphere = (t_sphere *) object;

	return (get_dist(sphere, ray));
}

t_ray	get_normal_of_sphere(void *object, t_vec3 contact)
{
	t_sphere *const	sphere = (t_sphere *) object;
	const t_vec3	normal = vec3_unit(vec3_sub(contact, sphere->center));

	return ((t_ray){contact, normal});
}

static double	get_dist(t_sphere *sphere, t_ray ray)
{
	const t_vec3	oc = vec3_sub(ray.origin, sphere->center);
	const double	a = vec3_dot(ray.direction, ray.direction);
	const double	half_b = vec3_dot(oc, ray.direction);
	const double	c = vec3_dot(oc, oc) - sphere->radius * sphere->radius;
	double			ret;

	ret = pow(half_b, 2) - a * c;
	if (ret < 0)
		return (INF);
	ret = (-half_b - sqrt(ret)) / a;
	if (ret < 0)
		return (INF);
	return (ret);
}
