#include "../../incs/raytracing.h"
#include <math.h>

t_vec3			diffuse(t_var *var, t_light *light, t_hit hit);
static double	get_diffuse(t_var *var, t_ray normal_ray, t_ray light_ray);

t_vec3	diffuse(t_var *var, t_light *light, t_hit hit)
{
	const t_ray		light_ray = (t_ray){
		hit.normal.origin,
		vec3_sub(light->origin, hit.normal.origin)
	};
	const double	ratio = get_diffuse(var, hit.normal, light_ray);

	return (vec3_mul(hit.color, ratio * light->ratio / 256.0));
}

static double	get_diffuse(t_var *var, t_ray normal_ray, t_ray light_ray)
{
	double		ret;
	t_hit		next_hit;
	double		dist_to_light;

	ret = vec3_dot(
			vec3_unit(normal_ray.direction),
			vec3_unit(light_ray.direction)
			);
	if (ret <= 0)
		return (0);
	dist_to_light = vec3_length(light_ray.direction);
	light_ray.direction = vec3_unit(light_ray.direction);
	next_hit = hit_object(var, light_ray);
	if (next_hit.object != NULL && \
		get_type(next_hit.object) == LAMBERTIAN && \
		vec3_length(next_hit.ray.direction) < dist_to_light)
		return (0);
	return (ret);
}
