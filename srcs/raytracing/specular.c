#include "../../incs/raytracing.h"
#include <math.h>

t_vec3			specular(t_var *var, t_light *light, t_hit hit);
static double	get_specular_ratio(t_var *var, t_ray light_ray, t_hit hit);

t_vec3	specular(t_var *var, t_light *light, t_hit hit)
{
	const t_ray		light_ray = (t_ray){
		light->origin,
		vec3_sub(hit.normal.origin, light->origin)
	};
	const double	specular_ratio = get_specular_ratio(var, light_ray, hit);
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

static double	get_specular_ratio(t_var *var, t_ray light_ray, t_hit hit)
{
	const t_vec3	reflect = vec3_reflect(
			light_ray.direction,
			hit.normal.direction
			);
	const t_hit		next_hit = hit_object(var, light_ray);
	const double	dot = vec3_dot(
			vec3_unit(reflect),
			vec3_unit(vec3_reverse(hit.ray.direction))
			);

	if (next_hit.object != NULL && \
		next_hit.type == LAMBERTIAN && \
		vec3_length(next_hit.ray.direction) < vec3_length(light_ray.direction))
		return (0);
	return (pow(fmax(0, dot), 10));
}
