#include "../../incs/raytracing.h"
#include <math.h>

double			get_distance_to_cylinder(void *object, t_ray ray);
t_ray			get_normal_of_cylinder(void *object, t_vec3 contact);

double	get_distance_to_cylinder(void *object, t_ray ray)
{
	
}

t_ray	get_normal_of_cylinder(void *object, t_vec3 contact)
{
	t_cylinder *const	cylinder = (t_cylinder *) object;
	const t_vec3		oc = vec3_sub(contact, cylinder->center);
	const double		oc_dot_normal = vec3_dot(oc, cylinder->normal);
	const t_vec3		normal = vec3_sub(oc, vec3_mul(cylinder->normal, oc_dot_normal));
	t_ray				ret;

	ret.origin = contact;
	if (vec3_dot(contact, cylinder->normal) == 0)
		ret.direction = vec3_reverse(cylinder->normal);
	else if (vec3_dot(vec3_add(contact, vec3_mul(cylinder->normal, -cylinder->height)), cylinder->normal) == 0)
		ret.direction = cylinder->normal;
	else
		ret.direction = vec3_unit(normal);
	return (ret);
}
