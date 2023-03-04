#include "../../incs/raytracing.h"

t_vec3			mirror_reflection(
					t_var *var,
					t_light *light,
					t_hit hit,
					int depth
					);
static t_ray	get_reflect(t_hit hit);

t_vec3	mirror_reflection(t_var *var, t_light *light, t_hit hit, int depth)
{
	const t_hit	next_hit = hit_object(var, get_reflect(hit));
	t_vec3		next_color;
	t_vec3		ret;

	ret = vec3_mul(vec3_div(hit.color, 256), 0.05);
	if (next_hit.object == NULL || depth == 0)
		return (ret);
	next_color = (t_vec3){0, 0, 0};
	if (next_hit.type == LAMBERTIAN)
		next_color = phong_reflection(var, light, next_hit);
	else if (next_hit.type == DIELECTRIC)
		next_color = mirror_reflection(var, light, next_hit, depth - 1);
	ret = vec3_add(ret, vec3_mul(next_color, 0.95));
	return (vec3_matrix(vec3_div(hit.color, 256), ret));
}

static t_ray	get_reflect(t_hit hit)
{
	return ((t_ray){
		hit.normal.origin,
		vec3_unit(vec3_reflect(
				hit.ray.direction,
				hit.normal.direction
			))
	});
}
