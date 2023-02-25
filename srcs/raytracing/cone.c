#include "../../incs/raytracing.h"
#include <math.h>

double			get_distance_to_cone(void *object, t_ray ray);
t_ray			get_normal_of_cone(void *object, t_vec3 contact);
static double	get_dist(t_cone *cone, t_ray ray);

double	get_distance_to_cone(void *object, t_ray ray)
{
	t_cone *const	cone = (t_cone *) object;
	const double	t = get_dist(cone, ray);
	const t_vec3	contact = vec3_add(ray.origin, vec3_mul(ray.direction, t));
	const double	height = vec3_dot(
			vec3_sub(contact, cone->center),
			cone->normal
			);

	if (height < 0 || cone->height < height)
		return (INF);
	return (t);
}

t_ray	get_normal_of_cone(void *object, t_vec3 contact)
{
	t_cone *const	cone = (t_cone *) object;
	const double	cur_height = vec3_dot(
			vec3_sub(contact, cone->center),
			cone->normal
			);
	const double	cur_radius = cone->radius * (1 - cur_height / cone->height);

	if (fabs(vec3_dot(cone->normal, contact)
			- vec3_dot(cone->normal, cone->center)) < INFSIMAL)
		return ((t_ray){contact, vec3_reverse(cone->normal)});
	return ((t_ray){contact,
		vec3_unit(vec3_add(
				vec3_mul(cone->normal, cur_radius),
				vec3_mul(
					vec3_unit(vec3_sub(
							contact,
							vec3_add(
								cone->center,
								vec3_mul(cone->normal, cur_height)
							)
						)),
					(cone->height - cur_height)
				)
			))
	});
}

static double	get_dist(t_cone *cone, t_ray ray)
{
	const t_vec3	oc = vec3_sub(ray.origin, cone->center);
	const double	a = vec3_dot(ray.direction, ray.direction)
		- ((1 + pow(cone->radius, 2) / pow(cone->height, 2))
			* pow(vec3_dot(ray.direction, cone->normal), 2));
	const double	half_b = vec3_dot(ray.direction, oc)
		+ (pow(cone->radius, 2) / cone->height)
		* vec3_dot(ray.direction, cone->normal)
		- (1 + pow(cone->radius, 2) / pow(cone->height, 2))
		* vec3_dot(oc, cone->normal)
		* vec3_dot(ray.direction, cone->normal);
	const double	c = vec3_dot(oc, oc)
		+ 2 * (pow(cone->radius, 2) / cone->height)
		* vec3_dot(oc, cone->normal)
		- (1 + pow(cone->radius, 2) / pow(cone->height, 2))
		* pow(vec3_dot(oc, cone->normal), 2)
		- pow(cone->radius, 2);

	return (discriminate(a, half_b, c));
}
