#include "../../incs/raytracing.h"
#include <math.h>
#include <stdio.h>

double			get_distance_to_cylinder(void *object, t_ray ray);
t_ray			get_normal_of_cylinder(void *object, t_vec3 contact);
static double	get_distance_to_base(t_ray normal, t_ray ray, double radius);
static double	get_distance_to_curved(t_cylinder *cylinder, t_ray ray);
static t_bool	is_out_of_height(t_cylinder *cylinder, t_ray ray, double t);

double	get_distance_to_cylinder(void *object, t_ray ray)
{
	t_cylinder *const	cylinder = (t_cylinder *) object;
	t_ray				normal;
	double				dist_to_bottom;
	double				dist_to_top;
	double				dist_to_curved;

	normal = (t_ray){cylinder->center, cylinder->normal};
	dist_to_bottom = get_distance_to_base(normal, ray, cylinder->radius);
	normal.origin = vec3_add(
			cylinder->center,
			vec3_mul(cylinder->normal, cylinder->height)
			);
	normal.direction = vec3_reverse(normal.direction);
	dist_to_top = get_distance_to_base(normal, ray, cylinder->radius);
	dist_to_curved = get_distance_to_curved(cylinder, ray);
	return (fmin(fmin(dist_to_bottom, dist_to_top), dist_to_curved));
}

t_ray	get_normal_of_cylinder(void *object, t_vec3 contact)
{
	t_cylinder *const	cylinder = (t_cylinder *) object;
	const t_vec3		oc = vec3_sub(contact, cylinder->center);
	const double		oc_dot_normal = vec3_dot(oc, cylinder->normal);
	const t_vec3		normal = vec3_sub(
			oc,
			vec3_mul(cylinder->normal, oc_dot_normal)
			);
	t_ray				ret;

	ret.origin = contact;
	if (vec3_dot(contact, cylinder->normal) == 0)
		ret.direction = vec3_reverse(cylinder->normal);
	contact = vec3_add(contact, vec3_mul(cylinder->normal, cylinder->height));
	if (vec3_dot(contact, cylinder->normal) == 0)
		ret.direction = cylinder->normal;
	else
		ret.direction = vec3_unit(normal);
	return (ret);
}

static double	get_distance_to_base(t_ray normal, t_ray ray, double radius)
{
	t_vec3	oc;
	double	denom;
	double	numer;
	double	ret;
	double	dist_to_center;

	oc = vec3_sub(normal.origin, ray.origin);
	denom = vec3_dot(normal.direction, ray.direction);
	numer = vec3_dot(vec3_sub(oc, ray.origin), normal.direction);
	if (fabs(denom) <= INFSIMAL)
		return (INF);
	ret = numer / denom;
	if (ret < 0)
		return (INF);
	dist_to_center = vec3_length(
			vec3_sub(
				vec3_add(ray.origin, vec3_mul(ray.direction, ret)),
				normal.origin
				)
			);
	if (radius < dist_to_center)
		return (INF);
	return (ret);
}

static double	get_distance_to_curved(t_cylinder *cylinder, t_ray ray)
{
	const t_vec3	oc = vec3_sub(ray.origin, cylinder->center);
	const double	a
		= vec3_dot(ray.direction, ray.direction) - \
			pow(vec3_dot(ray.direction, cylinder->normal), 2);
	const double	half_b
		= vec3_dot(oc, ray.direction) - \
			vec3_dot(oc, cylinder->normal) * \
				vec3_dot(ray.direction, cylinder->normal);
	const double	c
		= vec3_dot(oc, oc) - \
			pow(vec3_dot(oc, cylinder->normal), 2) - \
				pow(cylinder->radius, 2);
	double			ret;

	ret = pow(half_b, 2) - a * c;
	if (ret < 0)
		return (INF);
	ret = (-half_b - sqrt(ret)) / a;
	if (ret < 0)
		return (INF);
	if (is_out_of_height(cylinder, ray, ret))
		return (INF);
	return (ret);
}

static t_bool	is_out_of_height(t_cylinder *cylinder, t_ray ray, double t)
{
	const t_vec3	contact = vec3_add(ray.origin, vec3_mul(ray.direction, t));
	const t_vec3	oc = vec3_sub(contact, cylinder->center);
	const double	oc_dot_normal = vec3_dot(oc, cylinder->normal);

	if (oc_dot_normal < 0 || cylinder->height < oc_dot_normal)
		return (TRUE);
	return (FALSE);
}
