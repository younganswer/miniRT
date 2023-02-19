#include "../../incs/raytracing.h"

t_vec3			mirror_reflection(
					t_var *var,
					t_light *light,
					t_hit hit,
					int depth
					);
static t_ray	get_reflect(t_hit hit);

// TODO: Schlick's reflectance approximation
t_vec3	mirror_reflection(t_var *var, t_light *light, t_hit hit, int depth)
{
	const t_hit	next_hit = hit_object(var, get_reflect(hit));
	t_vec3		ret;

	ret = (t_vec3){0, 0, 0};
	if (next_hit.object == NULL || depth == 0)
		return (ret);
	if (get_type(next_hit.object) == DIELECTRIC)
		ret = mirror_reflection(var, light, next_hit, depth - 1);
	else
		ret = phong_reflection(var, light, next_hit);
	return (vec3_matrix(vec3_div(get_color(hit.object), 256), ret));
}

static t_ray	get_reflect(t_hit hit)
{
	return ((t_ray){
		handle_shadow_acne(
			vec3_add(hit.ray.origin, hit.ray.direction),
			hit.normal.direction
		),
		vec3_reflect(
			vec3_reverse(hit.ray.direction),
			hit.normal.direction
		)
	});
}
