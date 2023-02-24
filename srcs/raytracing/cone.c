#include "../../incs/raytracing.h"
#include <math.h>

double	get_distance_to_cone(void *object, t_ray ray);
t_ray	get_normal_of_cone(void *object, t_vec3 contact);

double	get_distance_to_cone(void *object, t_ray ray)
{
	t_cone *const	cone = (t_cone *) object;
	const t_vec3	oc = vec3_sub(ray.origin, cone->center);
	const double	radius2 = cone->radius * cone->radius;
	const double	height2 = cone->height * cone->height;
	const double	a = vec3_dot(ray.direction, ray.direction)
						- ((1 + radius2 / height2) * pow(vec3_dot(ray.direction, cone->normal), 2));
	const double	half_b = vec3_dot(ray.direction, oc)
						- ((1 + radius2 / height2) * vec3_dot(ray.direction, cone->normal) * vec3_dot(oc, cone->normal));
	const double	c = vec3_dot(oc, oc)
						- ((1 + radius2 / height2) * pow(vec3_dot(oc, cone->normal), 2))
						- radius2;

	return (discriminate(a, half_b, c));
}

t_ray	get_normal_of_cone(void *object, t_vec3 contact)
{
	t_cone *const	cone = (t_cone *) object;
	const double	height2 = cone->height * cone->height;
	const t_vec3	oc = vec3_sub(contact, cone->center);
	const double	m = vec3_dot(oc, cone->normal) / height2;
	const t_vec3	p = vec3_add(cone->center, vec3_mul(cone->normal, m));
	const t_vec3	normal = vec3_unit(vec3_sub(contact, p));

	return ((t_ray){contact, normal});
}
