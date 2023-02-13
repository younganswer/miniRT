#include "../../incs/raytracing.h"
#include <math.h>

double			get_distance_to_sphere(void *object, t_ray ray);
double			get_distance_to_plane(void *object, t_ray ray);
double			get_distance_to_cylinder(void *object, t_ray ray);
static double	dist_to_sphere(double a, double half_b, double c);
static double	dist_to_cylinder(double a, double half_b, double c);

double	get_distance_to_sphere(void *object, t_ray ray)
{
	t_sphere *const	sphere = (t_sphere *) object;
	const t_vec3	oc = vec3_sub(ray.origin, sphere->center);
	const double	a = vec3_dot(ray.direction, ray.direction);
	const double	half_b = vec3_dot(oc, ray.direction);
	const double	c = vec3_dot(oc, oc) - sphere->radius * sphere->radius;

	return (dist_to_sphere(a, half_b, c));
}

double	get_distance_to_plane(void *object, t_ray ray)
{
	t_plane *const	plane = (t_plane *) object;
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

double	get_distance_to_cylinder(void *object, t_ray ray)
{
	t_cylinder *const	cylinder = (t_cylinder *) object;
	const t_vec3		oc = vec3_sub(ray.origin, cylinder->center);
	const double		a
		= vec3_dot(ray.direction, ray.direction)
		- pow(vec3_dot(ray.direction, cylinder->normal), 2);
	const double		half_b
		= vec3_dot(oc, ray.direction)
		- vec3_dot(oc, cylinder->normal)
		* vec3_dot(ray.direction, cylinder->normal);
	const double		c
		= vec3_dot(oc, oc)
		- pow(vec3_dot(oc, cylinder->normal), 2)
		- pow(cylinder->radius, 2);

	return (dist_to_cylinder(a, half_b, c));
}

static double	dist_to_sphere(double a, double half_b, double c)
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

static double	dist_to_cylinder(double a, double half_b, double c)
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
