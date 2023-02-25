#include "../../incs/raytracing.h"
#include <math.h>

t_vec3			specular(t_light *light, t_hit hit);
static double	get_specular_ratio(t_ray light_ray, t_hit hit);

t_vec3	specular(t_light *light, t_hit hit)
{
	const t_ray		light_ray = (t_ray){
		hit.normal.origin,
		vec3_sub(light->origin, hit.normal.origin)
	};
	const double	specular_ratio = get_specular_ratio(light_ray, hit);
	const t_vec3	light_color = vec3_mul(
			light->color,
			light->ratio / 256.0
			);
	const t_vec3	obj_color = vec3_mul(
			hit.color,
			specular_ratio / 256.0
			);

	return (vec3_matrix(obj_color, light_color));
}

static double	get_specular_ratio(t_ray light_ray, t_hit hit)
{
	const t_vec3	reflect = vec3_reflect(
			light_ray.direction,
			hit.normal.direction
			);
	const double	dot = vec3_dot(
			vec3_unit(reflect),
			vec3_unit(vec3_reverse(hit.ray.direction))
			);

	return (pow(fmax(0, dot), 10));
}
