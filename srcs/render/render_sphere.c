#include "../../incs/render.h"
#include "../../incs/ray.h"
#include <math.h>

double	hit_sphere(t_sphere *sphere, t_ray ray);
size_t	get_color_of_sphere(t_sphere *sphere, t_ray ray, double t);

double	hit_sphere(t_sphere *sphere, t_ray ray)
{
	const t_vec3	oc = vec3_sub(ray.origin, sphere->center);
	const double	a = vec3_length_squared(ray.direction);
	const double	half_b = vec3_dot(oc, ray.direction);
	const double	c = vec3_dot(oc, oc) - sphere->radius * sphere->radius;
	const double	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (-1.0);
	return ((-half_b - sqrt(discriminant)) / a);
}

size_t	get_color_of_sphere(t_sphere *sphere, t_ray ray, double t)
{
	size_t	ret;
	t_vec3	unit_dir;

	unit_dir = vec3_unit(
		vec3_sub(
			point_at_parameter(ray, t),
			sphere->center
		)
	);
	ret = (int) ((unit_dir.x + 1.0) * 255.999 * 0.5);
	ret = (ret << 8) + (int) ((unit_dir.y + 1.0) * 255.999 * 0.5);
	ret = (ret << 8) + (int) ((unit_dir.z + 1.0) * 255.999 * 0.5);
	return (ret);
}
