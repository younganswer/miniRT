#include "../../incs/raytracing.h"
#include <math.h>

t_vec3			diffuse(t_var *var, t_light *light, t_hit hit);
static double	get_diffuse_ratio(t_var *var, t_light *light, t_hit hit);

t_vec3	diffuse(t_var *var, t_light *light, t_hit hit)
{
	if (hit.object == NULL)
		return ((t_vec3){0, 0, 0});
	return (
		vec3_mul(
			get_color(hit.object),
			get_diffuse_ratio(var, light, hit) / 256.0
		)
	);
}

static double	get_diffuse_ratio(t_var *var, t_light *light, t_hit hit)
{
	const t_ray	normal_ray = (t_ray){
		handle_shadow_acne(
			vec3_add(hit.ray.origin, hit.ray.direction),
			hit.normal.direction
			),
		hit.normal.direction
	};
	const t_ray	light_ray = (t_ray){
		normal_ray.origin,
		vec3_unit(vec3_sub(light->origin, normal_ray.origin))
	};
	double		ret;
	t_hit		next_hit;
	double		dist_to_light;

	ret = vec3_dot(normal_ray.direction, light_ray.direction) * light->ratio;
	if (ret <= 0)
		return (0);
	dist_to_light = vec3_length(vec3_sub(light->origin, normal_ray.origin));
	next_hit = hit_object(var, light_ray);
	if (next_hit.object != NULL && \
		get_type(next_hit.object) == LAMBERTIAN && \
		vec3_length(next_hit.ray.direction) < dist_to_light)
		return (0);
	return (ret);
}
